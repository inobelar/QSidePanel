#ifndef Q_SIDE_PANEL__SIDE_PANEL_HELPERS_HPP
#define Q_SIDE_PANEL__SIDE_PANEL_HELPERS_HPP

#include <QRect>

namespace q_sp {

/*  ┌──╔══╗
    │  ║  ║
    └──╚══╝  */
QRect rect_opened_left(const int width, const QRect& parent_rect);

/*  ╔══╗──┐
    ║  ║  │
    ╚══╝──┘  */
QRect rect_closed_left(const int width, const QRect& parent_rect);

// -----------------------------------------------------------------------------

/*  ╔══╗──┐
    ║  ║  │
    ╚══╝──┘  */
QRect rect_opened_right(const int width, const QRect& parent_rect);

/*  ┌──╔══╗
    │  ║  ║
    └──╚══╝  */
QRect rect_closed_right(const int width, const QRect& parent_rect);

// -----------------------------------------------------------------------------

/*  ┌────┐
    ╔════╗
    ╚════╝  */
QRect rect_opened_top(const int height, const QRect& parent_rect);

/*  ╔════╗
    ╚════╝
    └────┘  */
QRect rect_closed_top(const int height, const QRect& parent_rect);

// -----------------------------------------------------------------------------

/*  ╔════╗
    ╚════╝
    └────┘  */
QRect rect_opened_bottom(const int height, const QRect& parent_rect);

/*  ┌────┐
    ╔════╗
    ╚════╝  */
QRect rect_closed_bottom(const int height, const QRect& parent_rect);

// -----------------------------------------------------------------------------

QRect rect_opened_full_left(const int handler_width, const QRect& parent_rect);

QRect rect_opened_full_right(const int handler_width, const QRect& parent_rect);

QRect rect_opened_full_top(const int handler_height, const QRect& parent_rect);

QRect rect_opened_full_bottom(const int handler_height, const QRect& parent_rect);

// -----------------------------------------------------------------------------

QRect rect_opened_half_left(const int handler_width, const QRect& parent_rect);

QRect rect_opened_half_right(const int handler_width, const QRect& parent_rect);

QRect rect_opened_half_top(const int handler_height, const QRect& parent_rect);

QRect rect_opened_half_bottom(const int handler_height, const QRect& parent_rect);

// =============================================================================

/*   ┌─
    ╔╗
    ╚╝
     └─  */
QRect rect_aligned_left_center(const QRect& target, const QSize& size);

/*  ─┐
     ╔╗
     ╚╝
    ─┘   */
QRect rect_aligned_right_center(const QRect& target, const QSize& size);

/*    ╔═╗
    ┌─╚═╝─┐  */
QRect rect_aligned_top_center(const QRect& target, const QSize& size);

/*  └─╔═╗─┘
      ╚═╝    */
QRect rect_aligned_bottom_center(const QRect& target, const QSize& size);

} // namespace q_sp

#endif // Q_SIDE_PANEL__SIDE_PANEL_HELPERS_HPP
