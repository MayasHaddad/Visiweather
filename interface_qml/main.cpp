#include <QtGui/QApplication>
#include "qml_interface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qml_interface w;
#if defined(Q_WS_S60)
    w.showMaximized();
#else
    w.show();
#endif

    return a.exec();
}
