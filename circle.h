#ifndef CIRCLE_H
#define CIRCLE_H

#include <QGraphicsWidget>

class Circle : public QGraphicsWidget
{
public:
    Circle(QPoint point, QColor color, QGraphicsWidget *parent = nullptr);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    QPoint circlePoint;
    QColor circleColor;
};

#endif // CIRCLE_H
