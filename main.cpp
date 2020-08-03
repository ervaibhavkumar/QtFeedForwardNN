#include <QApplication>
#include <QScreen>

#include "window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Window *w = new Window(qApp->screens()[0]->size());
    w->showMaximized();
    w->Start();

    return a.exec();
}
