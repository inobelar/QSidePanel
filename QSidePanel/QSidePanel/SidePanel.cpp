#include "SidePanel.hpp"

#include "math.hpp"
#include "side_panel_helpers.hpp"

#include <QDebug>


void SidePanel::_setState(const SidePanelState new_state) {
    if(_state == new_state)
        return;

    _state = new_state;

    emit stateChanged(_state);
}

// -----------------------------------------------------------------------------

#include <QEvent>

bool SidePanel::eventFilter(QObject *watched, QEvent *event)
{
    // Important note: DONT RETURN TRUE here, on event receive, because it's
    // blocks events handling, if few panels binded to the same parent widget

    if(event->type() == QEvent::Resize)
    {
        switch (_state) {
        case SidePanelState::Opened: { const auto geom = getOpenedRect(this->parentWidget()->rect()); this->setGeometry( geom ); this->updateHandlerRect(_anim_progress, geom); } break;
        case SidePanelState::Closed: { const auto geom = getClosedRect(this->parentWidget()->rect()); this->setGeometry( geom ); this->updateHandlerRect(_anim_progress, geom); } break;
        }

        // return true;
    }
    else if(event->type() == QEvent::Move)
    {
        switch (_state) {
        case SidePanelState::Opened: { const auto geom = getOpenedRect(this->parentWidget()->rect()); this->setGeometry( geom ); this->updateHandlerRect(_anim_progress, geom); } break;
        case SidePanelState::Closed: { const auto geom = getClosedRect(this->parentWidget()->rect()); this->setGeometry( geom ); this->updateHandlerRect(_anim_progress, geom); } break;
        }

        // return true;
    }

    return base_t::eventFilter(watched, event);
}

// -----------------------------------------------------------------------------

void SidePanel::updateHandlerRect(const qreal progress, const QRect& geom)
{
    const QRect handle_geom = alignedHandlerRect( geom, _handler->size() , progress);
    _handler->setGeometry( handle_geom );
}

SidePanel::SidePanel(QWidget *parent)
    : base_t(parent)
{
    /* ======================================================================

        This is the place, where NO member std::function IMMEDIATE call alowed.

        Call them in init() method

       ====================================================================== */

    const auto anim_func = [this](qreal t) -> void
    {
        const QRect parent_rect = this->parentWidget()->rect();

        const QRectF geom_start = getClosedRect(parent_rect);
        const QRectF geom_end   = getOpenedRect(parent_rect);

        const QRect new_geom = q_sp::lerp(t, geom_start, geom_end).toRect();
        this->setGeometry( new_geom );

        updateHandlerRect(_anim_progress, new_geom);

        qDebug() << new_geom << t;
    };


    _timer = new QTimer(this);
    _timer->setInterval(10);

    connect(_timer, &QTimer::timeout, this, [this, anim_func]
    {
        const auto time_now = std::chrono::system_clock::now();
        if((time_now - _time_start) >= _duration)
        {
            _timer->stop();

            // This setGeometry() for cases when duration=200ms, interval_time=100ms;
            switch (_state) {
            case SidePanelState::Opening: { const auto geom = getOpenedRect(this->parentWidget()->rect()); this->setGeometry( geom ); _anim_progress = 1.0; updateHandlerRect(_anim_progress, geom); } break;
            case SidePanelState::Closing: { const auto geom = getClosedRect(this->parentWidget()->rect()); this->setGeometry( geom ); _anim_progress = 0.0; updateHandlerRect(_anim_progress, geom); } break;
            default: break;
            }

            switch (_state) {
            case SidePanelState::Opening: { this->show(); _setState(SidePanelState::Opened); } break;
            case SidePanelState::Closing: { this->hide(); _setState(SidePanelState::Closed); } break;
            default: break;
            }

            return;
        }

        const auto time_end = (_time_start + _duration);

        // [t_start .. t_now .. t_end] -> [0.0 .. t .. 1.0]
        qreal t = q_sp::scale(
                    time_now.time_since_epoch().count(),
                    _time_start.time_since_epoch().count(),
                    time_end.time_since_epoch().count(),
                    0.0, 1.0);

        if(_state == SidePanelState::Closing) // On closing - reverse it
            t = (1.0 - t);

        _anim_progress = t;

        // Pass normalized value through easing functions
        if(_state == SidePanelState::Opening)
        {
            t = curve_on_open.valueForProgress(t);
        }
        else if(_state == SidePanelState::Closing)
        {
            t = curve_on_close.valueForProgress(t);
        }

        anim_func(t);

    });

    _handler = new HandlerWidgetT(parent);
    _handler->setObjectName("SidePanel_handler");


    // =========================================================================
    // Default behaviour basically the same as PanelLeftSide

    this->getOpenedRect = [this](const QRect& parent_rect) -> QRect
    {
        return q_sp::rect_opened_left(getPanelSize(), parent_rect);
    };

    this->getClosedRect = [this](const QRect& parent_rect) -> QRect
    {
        return q_sp::rect_closed_left(getPanelSize(), parent_rect);
    };

    // -------------------------------------------------------------------------

    this->alignedHandlerRect = [](const QRect& panel_geom, const QSize& handler_size, qreal) -> QRect
    {
        return q_sp::rect_aligned_right_center(panel_geom, handler_size);
    };

    // -------------------------------------------------------------------------

    this->initialHandlerSize = [this]() -> QSize
    {
        return this->_handler->size();
    };

    // -------------------------------------------------------------------------

    this->updateHandler = [](const SidePanelState state, HandlerWidgetT* handler)
    {
        Q_UNUSED(state);
        Q_UNUSED(handler);
    };

}

SidePanel::~SidePanel()
{
    if(_timer != nullptr)
    {
        _timer->stop();

        delete _timer;
        _timer = nullptr;
    }

    if(_handler != nullptr) {
        delete _handler;
        _handler = nullptr;
    }

    if(parentWidget()) {
        removeEventFilter(this);
    }
}

void SidePanel::init()
{
    QTimer::singleShot(0, [this] {
        _handler->resize( initialHandlerSize() );
        updateHandler(_state, _handler);
    });


    connect(_handler, &QAbstractButton::clicked, this, [this]
    {
        if(_timer->isActive())
        {
            qDebug() << "CLICK DURING ANIMATION";

            switch (_state) {
            case SidePanelState::Opening: { _setState(SidePanelState::Closing); } break;
            case SidePanelState::Closing: { _setState(SidePanelState::Opening); } break;
            default: break;
            }

        } else
        {
            switch (_state) {
            case SidePanelState::Closed: { this->show(); _setState(SidePanelState::Opening); } break;
            case SidePanelState::Opened: { this->show(); _setState(SidePanelState::Closing); } break;
            default: break;
            }

            _time_start = std::chrono::system_clock::now();
            _timer->start();
        }
    });

    connect(this, &SidePanel::stateChanged, _handler, [this](SidePanelState state)
    {
        updateHandler(state, _handler);
    });


    this->parentWidget()->installEventFilter(this);

//    this->hide();
    QTimer::singleShot(0, [this] {
        const auto geom = getClosedRect(this->parentWidget()->rect()); this->setGeometry( geom ); _anim_progress = 0.0; updateHandlerRect(_anim_progress, geom);
    });
}

// -----------------------------------------------------------------------------

void SidePanel::openPanel()
{
    _timer->stop(); // Stop animation, if it's running

    this->show();

    const QRect new_geom = getOpenedRect(this->parentWidget()->rect());
    this->setGeometry( new_geom );

    _anim_progress = 1.0;
    updateHandlerRect(_anim_progress, new_geom);

    _setState(SidePanelState::Opened);
}

void SidePanel::closePanel()
{
    _timer->stop(); // Stop animation, if it's running

    this->hide();

    const QRect new_geom = getClosedRect(this->parentWidget()->rect());
    this->setGeometry( new_geom );

    _anim_progress = 0.0;
    updateHandlerRect(_anim_progress, new_geom);

    _setState(SidePanelState::Closed);
}

// -----------------------------------------------------------------------------

void SidePanel::setDuration(const std::chrono::milliseconds &duration)
{
    _duration = duration;

    // TODO: is it safe during animation ?
}

std::chrono::milliseconds SidePanel::getDuration() const
{
    return _duration;
}

// -----------------------------------------------------------------------------

void SidePanel::setPanelSize(int size)
{
    _panel_size = size;

    // TODO: handle somehow opened/closed state. and state during animation
}

int SidePanel::getPanelSize() const
{
    return _panel_size;
}

// -----------------------------------------------------------------------------

void SidePanel::setOpenEasingCurve(const QEasingCurve &curve)
{
    curve_on_open = curve;
}

void SidePanel::setCloseEasingCurve(const QEasingCurve &curve)
{
    curve_on_close = curve;
}

// -----------------------------------------------------------------------------

QSize SidePanel::getHandlerSize() const
{
    return _handler->size();
}

// -----------------------------------------------------------------------------

#include <QResizeEvent>

void SidePanel::resizeEvent(QResizeEvent *event)
{
    base_t::resizeEvent(event);

    updateHandlerRect(_anim_progress, this->geometry());
}
