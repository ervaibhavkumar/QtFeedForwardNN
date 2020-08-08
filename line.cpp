#include "line.h"

#include <QPainter>

Line::Line(QPoint start, QPoint end, QColor color, QGraphicsWidget *parent)
    : QGraphicsWidget(parent),
      startPoint(start),
      endPoint(end),
      circleColor(color)
{

}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(circleColor, 3));
    painter->setBrush(QColor(circleColor));
    painter->drawLine(startPoint.x(), startPoint.y(), endPoint.x(), endPoint.y());
}

