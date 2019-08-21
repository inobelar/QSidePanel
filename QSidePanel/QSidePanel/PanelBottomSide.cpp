#include "PanelBottomSide.hpp"

#include "side_panel_helpers.hpp"

PanelBottomSide::PanelBottomSide(QWidget *parent)
    : SidePanel(parent)
{

    this->getOpenedRect = [this](const QRect& parent_rect) -> QRect
    {
        return q_sp::rect_opened_bottom(this->getPanelSize(), parent_rect);
    };

    this->getClosedRect = [this](const QRect& parent_rect) -> QRect
    {
        return q_sp::rect_closed_bottom(this->getPanelSize(), parent_rect);
    };

    this->alignedHandlerRect = [](const QRect& panel_geom, const QSize& handler_size, qreal) -> QRect
    {
        return q_sp::rect_aligned_top_center(panel_geom, handler_size);
    };

    this->initialHandlerSize = []() -> QSize {
        return {120, 60};
    };

    this->updateHandler = [](const SidePanelState state, HandlerWidgetT* handler)
    {
        switch (state) {
        case SidePanelState::Opening: { handler->setText("vvv"); } break;
        case SidePanelState::Opened:  { handler->setText("vvv"); } break;
        case SidePanelState::Closing: { handler->setText("^^^"); } break;
        case SidePanelState::Closed:  { handler->setText("^^^"); } break;
        default: break;
        }
    };
}

PanelBottomSide::~PanelBottomSide()
{

}
