#include "PanelTopSide.hpp"

#include "side_panel_helpers.hpp"

PanelTopSide::PanelTopSide(QWidget *parent)
    : SidePanel(parent)
{

    this->getOpenedRect = [this](const QRect& parent_rect) -> QRect
    {
        return q_sp::rect_opened_top(this->getPanelSize(), parent_rect);
    };

    this->getClosedRect = [this](const QRect& parent_rect) -> QRect
    {
        return q_sp::rect_closed_top(this->getPanelSize(), parent_rect);
    };

    this->alignedHandlerRect = [](const QRect& panel_geom, const QSize& handler_size, qreal) -> QRect
    {
        return q_sp::rect_aligned_bottom_center(panel_geom, handler_size);
    };

    this->initialHandlerSize = []() -> QSize
    {
        return {120, 60};
    };

    this->updateHandler = [](const SidePanelState state, HandlerWidgetT* handler)
    {
        switch (state) {
        case SidePanelState::Opening: { handler->setText("^^^"); } break;
        case SidePanelState::Opened:  { handler->setText("^^^"); } break;
        case SidePanelState::Closing: { handler->setText("vvv"); } break;
        case SidePanelState::Closed:  { handler->setText("vvv"); } break;
        default: break;
        }
    };

}

PanelTopSide::~PanelTopSide()
{

}
