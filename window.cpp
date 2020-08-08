#include "window.h"
#include "config.h"
#include "circle.h"
#include "utilities.h"

#include <random>

#include <QTimer>
#include <QDebug>

Window::Window(QSize size, QGraphicsView *parent)
    : QGraphicsView(parent),
      windowSize(size)
{
    QGraphicsScene *scene = new QGraphicsScene();
    setScene(scene);

    scene->setSceneRect(0,0,windowSize.width() - 10,windowSize.height() - 10);
    setBackgroundBrush(QColor("black"));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowTitle("Feed forward NN visualization with C== and QT");

    trainingData = new QList<Training>();
}

void Window::Start() {
    prepareTrainingData();
    nn = new NN(hiddenUnits, learningRate);
    plotGuess();
    train();
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
    std::random_shuffle (trainingData->begin(), trainingData->end());
}

QColor Window::calculateColor(double input) {
    if (input > 0.0) {
        return  QColor("green");
    }
    else {
        return QColor("red");
    }
}

void Window::plotGuess() {
    v_d weights = nn->getWeights();
    double x1 = (double) xMin;
    double y1 = (-weights[2] - weights[0] * x1) / weights[1];
    double x2 = (double) xMax;
    double y2 = (-weights[2] - weights[0] * x2) / weights[1];

    x1 = Utilities::mapNumbers(x1, (double) xMin, (double) xMax, 0.0, (double) windowSize.width());
    y1 = Utilities::mapNumbers(y1, (double) yMin, (double) yMax, 0.0, (double) windowSize.height());
    x2 = Utilities::mapNumbers(x2, (double) xMin, (double) xMax, 0.0, (double) windowSize.width());
    y2 = Utilities::mapNumbers(y2, (double) yMin, (double) yMax, 0.0, (double) windowSize.width());

    y1 = y1 > 0 ? y1 : 0;
    y2 = y2 > 0 ? y2 : 0;

    y1 = y1 < windowSize.height() ? y1 : windowSize.height();
    y2 = y2 < windowSize.height() ? y2 : windowSize.height();

    drawGuess(QPoint(x1, y1), QPoint(x2, y2));
}

void Window::drawGuess(QPoint start, QPoint end) {
    if (guess != nullptr) {
        scene()->removeItem(guess);
        delete guess;
    }
    guess = new Line(start, end, QColor("blue"));
    scene()->addItem(guess);
    scene()->update();
}

void Window::train() {
    QTimer* timer = new QTimer();
    timer->setInterval(10);
    connect(timer, &QTimer::timeout, this, [=](){
            Training item = trainingData->at(trainingItem);
            nn->train(item.getInput(), item.getOutput());
            plotGuess();
            trainingItem++;
//            if (trainingItem == trainItems) timer->stop();
            trainingItem %= trainItems;
    });
    timer->start();
}
