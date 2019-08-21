#ifndef Q_SIDE_PANEL__MATH_HPP
#define Q_SIDE_PANEL__MATH_HPP

#include <QPointF>
#include <QRectF>

namespace q_sp {

// via: https://stackoverflow.com/a/23157705
constexpr double scale(const double& valueIn, const double& baseMin, const double& baseMax, const double& limitMin, const double& limitMax)
{
    return ((limitMax - limitMin) * (valueIn - baseMin) / (baseMax - baseMin)) + limitMin;
}

// Linear interpolation (between points)
QPointF lerp(const qreal t, const QPointF& a, const QPointF& b);

// Linear interpolation (between rects)
QRectF lerp(const qreal t, const QRectF& a, const QRectF& b);

} // namespace q_sp


#endif // Q_SIDE_PANEL__MATH_HPP
