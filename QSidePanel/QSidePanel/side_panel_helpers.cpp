#include "side_panel_helpers.hpp"

QRect q_sp::rect_opened_left(const int width, const QRect &parent_rect)
{
    QRect rect(0, 0, width, parent_rect.height());
    rect.moveTopLeft(parent_rect.topLeft());
    return rect;
}

QRect q_sp::rect_closed_left(const int width, const QRect &parent_rect)
{
    QRect rect(0, 0, width, parent_rect.height());
    rect.moveTopRight(parent_rect.topLeft());
    return rect;
}

QRect q_sp::rect_opened_right(const int width, const QRect &parent_rect)
{
    QRect rect(0, 0, width, parent_rect.height());
    rect.moveTopRight(parent_rect.topRight());
    return rect;
}

QRect q_sp::rect_closed_right(const int width, const QRect &parent_rect)
{
    QRect rect(0, 0, width, parent_rect.height());
    rect.moveTopLeft(parent_rect.topRight());
    return rect;
}

QRect q_sp::rect_opened_top(const int height, const QRect &parent_rect)
{
    QRect rect(0, 0, parent_rect.width(), height);
    rect.moveTopLeft(parent_rect.topLeft());
    return rect;
}

QRect q_sp::rect_closed_top(const int height, const QRect &parent_rect)
{
    QRect rect(0, 0, parent_rect.width(), height);
    rect.moveBottomLeft(parent_rect.topLeft());
    return rect;
}

QRect q_sp::rect_opened_bottom(const int height, const QRect &parent_rect)
{
    QRect rect(0, 0, parent_rect.width(), height);
    rect.moveBottomLeft(parent_rect.bottomLeft());
    return rect;
}

QRect q_sp::rect_closed_bottom(const int height, const QRect &parent_rect)
{
    QRect rect(0, 0, parent_rect.width(), height);
    rect.moveTopLeft(parent_rect.bottomLeft());
    return rect;
}

QRect q_sp::rect_opened_full_left(const int handler_width, const QRect &parent_rect)
{
    QRect rect = parent_rect;
    rect.setRight(parent_rect.right() - handler_width);
    return rect;
}

QRect q_sp::rect_opened_full_right(const int handler_width, const QRect &parent_rect)
{
    QRect rect = parent_rect;
    rect.setLeft(parent_rect.left() + handler_width);
    return rect;
}

QRect q_sp::rect_opened_full_top(const int handler_height, const QRect &parent_rect)
{
    QRect rect = parent_rect;
    rect.setBottom(parent_rect.bottom() - handler_height);
    return rect;
}

QRect q_sp::rect_opened_full_bottom(const int handler_height, const QRect &parent_rect)
{
    QRect rect = parent_rect;
    rect.setTop(parent_rect.top() + handler_height);
    return rect;
}

QRect q_sp::rect_aligned_left_center(const QRect &target, const QSize &size)
{
    QRect rect(0, 0, size.width(), size.height());
    rect.moveTopRight( {target.left(), target.center().y() - (size.height()/2)} );
    return rect;
}

QRect q_sp::rect_aligned_right_center(const QRect &target, const QSize &size)
{
    QRect rect(0, 0, size.width(), size.height());
    rect.moveTopLeft( {target.right(), target.center().y() - (size.height()/2)} );
    return rect;
}

QRect q_sp::rect_aligned_top_center(const QRect &target, const QSize &size)
{
    QRect rect(0, 0, size.width(), size.height());
    rect.moveBottomLeft( {target.center().x() - (size.width()/2), target.top()} );
    return rect;
}

QRect q_sp::rect_aligned_bottom_center(const QRect &target, const QSize &size)
{
    QRect rect(0, 0, size.width(), size.height());
    rect.moveTopLeft( {target.center().x() - (size.width()/2), target.bottom()} );
    return rect;
}

QRect q_sp::rect_opened_half_left(const int handler_width, const QRect &parent_rect)
{
    QRect rect = parent_rect;
    rect.setRight( std::min( rect.center().x(), (parent_rect.right() - handler_width) ) );
    return rect;
}

QRect q_sp::rect_opened_half_right(const int handler_width, const QRect &parent_rect)
{
    QRect rect = parent_rect;
    rect.setLeft( std::max(rect.center().x(), (parent_rect.left() + handler_width) ) );
    return rect;
}

QRect q_sp::rect_opened_half_top(const int handler_height, const QRect &parent_rect)
{
    QRect rect = parent_rect;
    rect.setBottom( std::min(rect.center().y(), (parent_rect.bottom() - handler_height) ) );
    return rect;
}

QRect q_sp::rect_opened_half_bottom(const int handler_height, const QRect &parent_rect)
{
    QRect rect = parent_rect;
    rect.setTop( std::max(rect.center().y(), (parent_rect.top() + handler_height) ) );
    return rect;
}
