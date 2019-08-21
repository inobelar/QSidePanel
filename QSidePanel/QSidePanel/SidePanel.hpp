#ifndef Q_SIDE_PANEL__SIDE_PANEL_HPP
#define Q_SIDE_PANEL__SIDE_PANEL_HPP

#include <QScrollArea>

#include <QTimer>
#include <chrono>

#include <QEasingCurve>

#include <QPushButton>

#include <functional> // for std::function

#include "SidePanelState.hpp"

// -----------------------------------------------------------------------------

class SidePanel : public QScrollArea
{
    Q_OBJECT

public:

    using HandlerWidgetT = QPushButton;

private:

    SidePanelState _state = SidePanelState::Closed;
    void _setState(const SidePanelState new_state);


    std::chrono::milliseconds _duration {1000};

    std::chrono::system_clock::time_point _time_start;

    QEasingCurve curve_on_open  = {QEasingCurve::Type::OutBounce};
    QEasingCurve curve_on_close = {QEasingCurve::Type::InBounce };

    QTimer* _timer = nullptr;

    HandlerWidgetT* _handler = nullptr;

    qreal _anim_progress = 0.0;

    void updateHandlerRect(const qreal progress, const QRect& geom);

    int _panel_size = 100; // px

protected:

    bool eventFilter(QObject* watched, QEvent* event) override;

public:

    // =========================================================================
    // Callbacks for behaviour customization

    using rect_func_t = std::function<QRect(const QRect& /*parent_rect*/)>;

    rect_func_t getOpenedRect;

    rect_func_t getClosedRect;

    // -------------------------------------------------------------------------

    using handler_align_func_t = std::function<QRect(const QRect& /*panel_geom*/, const QSize& /*handler_size*/, qreal /*progress*/)>;

    handler_align_func_t alignedHandlerRect;

    // -------------------------------------------------------------------------

    using handler_size_func_t = std::function<QSize()>;

    handler_size_func_t initialHandlerSize;

    // -------------------------------------------------------------------------

    using handler_update_func_t = std::function<void(const SidePanelState, HandlerWidgetT*)>;

    handler_update_func_t updateHandler;

    // =========================================================================

    using base_t = QScrollArea;
    explicit SidePanel(QWidget *parent = nullptr);
    virtual ~SidePanel() override;

    void init();

    // Immediately open/close panel without animation
    void openPanel();
    void closePanel();

    void setDuration(const std::chrono::milliseconds& duration);
    std::chrono::milliseconds getDuration() const;

    void setPanelSize(int size);
    int getPanelSize() const;

    void setOpenEasingCurve (const QEasingCurve& curve);
    void setCloseEasingCurve(const QEasingCurve& curve);

    QSize getHandlerSize() const;

signals:
    void stateChanged(SidePanelState state);

protected:
    void resizeEvent(QResizeEvent* event) override;
};

#endif // Q_SIDE_PANEL__SIDE_PANEL_HPP
