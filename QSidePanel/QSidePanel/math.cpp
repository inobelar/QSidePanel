#include "math.hpp"

QPointF q_sp::lerp(const qreal t, const QPointF &a, const QPointF &b) {
    return (1.0-t)*a + t*b;
}

QRectF q_sp::lerp(const qreal t, const QRectF &a, const QRectF &b) {
    const QPointF topLeft   = lerp(t, a.topLeft(),     b.topLeft());
    const QPointF bottRight = lerp(t, a.bottomRight(), b.bottomRight());
    return QRectF(topLeft, bottRight);
}
