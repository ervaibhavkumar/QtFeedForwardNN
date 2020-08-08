#ifndef LINE_H
#define LINE_H

#include <QGraphicsWidget>

class Line : public QGraphicsWidget
{
public:
    Line(QPoint start, QPoint end, QColor color, QGraphicsWidget *parent = nullptr);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    QPoint startPoint;
    QPoint endPoint;
    QColor circleColor;
};

#endif // LINE_H
