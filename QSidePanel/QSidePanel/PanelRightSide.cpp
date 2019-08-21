#include "PanelRightSide.hpp"

#include "side_panel_helpers.hpp"

PanelRightSide::PanelRightSide(QWidget *parent)
    : SidePanel(parent)
{

    this->getOpenedRect = [this](const QRect& parent_rect) -> QRect
    {
        return q_sp::rect_opened_right(this->getPanelSize(), parent_rect);
    };

    this->getClosedRect = [this](const QRect& parent_rect) -> QRect
    {
        return q_sp::rect_closed_right(this->getPanelSize(), parent_rect);
    };

    this->alignedHandlerRect = [](const QRect& panel_geom, const QSize& handler_size, qreal) -> QRect
    {
        return q_sp::rect_aligned_left_center(panel_geom, handler_size);
    };

    this->initialHandlerSize = []() -> QSize {
        return {60, 120};
    };

    this->updateHandler = [](const SidePanelState state, HandlerWidgetT* handler)
    {
        switch (state) {
        case SidePanelState::Opening: { handler->setText(">"); } break;
        case SidePanelState::Opened:  { handler->setText(">"); } break;
        case SidePanelState::Closing: { handler->setText("<"); } break;
        case SidePanelState::Closed:  { handler->setText("<"); } break;
        default: break;
        }
    };

}

PanelRightSide::~PanelRightSide()
{

}
