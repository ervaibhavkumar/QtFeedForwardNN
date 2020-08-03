#include "window.h"
#include "config.h"
#include "circle.h"
#include "utilities.h"

#include <QDebug>

Window::Window(QSize size, QGraphicsView *parent)
    : QGraphicsView(parent),
      windowSize(size)
{
    QGraphicsScene *scene = new QGraphicsScene();
    setScene(scene);

    scene->setSceneRect(0,0,windowSize.width(),windowSize.height());
    setBackgroundBrush(QColor("black"));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowTitle("Feed forward NN visualization with C== and QT");

    trainingData = new QList<Training>();
}

void Window::Start() {
    prepareTrainingData();
}

void Window::prepareTrainingData() {
    for (auto i = 0; i < trainItems; i++) {
        double x = Utilities::getRandomNum(xMin, xMax);
        double y = Utilities::getRandomNum(yMin, yMax);

        auto output = [] (double slope, double x, double intercept) {
            return (slope * x + intercept);
        };

        v_d input {x, y, 1.0};
        double answer = y < output(trainingSlope, x, trainingIntercept) ? -1 : 1;

        Training *train = new Training(input, answer);

        trainingData->push_back(*train);

        QColor color =  calculateColor(answer);


        double mappedX = Utilities::mapNumbers(x, (double) xMin, (double) xMax, 0.0, (double) windowSize.width());
        double mappedY = Utilities::mapNumbers(y, (double) yMin, (double) yMax, 0.0, (double) windowSize.height());
        Circle *c = new Circle(QPoint(mappedX, mappedY), color);
        scene()->addItem(c);
        scene()->update();
    }
}

QColor Window::calculateColor(double input) {
    if (input > 0.0) {
        return  QColor("green");
    }
    else {
        return QColor("red");
    }
}
