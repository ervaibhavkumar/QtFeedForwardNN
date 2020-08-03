#include "circle.h"

#include <QPainter>

Circle::Circle(QPoint point, QColor color, QGraphicsWidget *parent)
    : QGraphicsWidget(parent),
      circlePoint(point),
      circleColor(color)
{

}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(circleColor));
    painter->setBrush(QColor(circleColor));
    painter->drawEllipse(circlePoint, 4 , 4);
}


