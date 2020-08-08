#ifndef WINDOW_H
#define WINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include "training.h"
#include "nn.h"
#include "line.h"

class Window : public QGraphicsView
{
public:
    Window(QSize size, QGraphicsView *parent = nullptr);
    void Start();

private:
    void prepareTrainingData();
    QColor calculateColor(double input);
    void plotGuess();
    void drawGuess(QPoint start, QPoint end);
    void train();

    QSize windowSize;
    QList<Training> *trainingData;
    NN *nn;
    Line *guess = nullptr;
    int trainingItem = 0;
};

#endif // WINDOW_H
