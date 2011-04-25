#include <QtGui/QApplication>
#include <QDeclarativeView>
#include "visiweather.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Visiweather w;
#if defined(Q_WS_S60)
    w.showMaximized();
#else
    w.show();
#endif

    return a.exec();
}
