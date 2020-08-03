#ifndef WINDOW_H
#define WINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include "training.h"

class Window : public QGraphicsView
{
public:
    Window(QSize size, QGraphicsView *parent = nullptr);
    void Start();

private:
    void prepareTrainingData();
    QColor calculateColor(double input);

    QSize windowSize;
    QList<Training> *trainingData;
};

#endif // WINDOW_H
