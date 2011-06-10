#include <QtGui/QApplication>
#include <QFile>
#include "qml_interface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString place = argv[1];
    if (place.isNull())
    {
        QFile file("place.txt");
        if (file.exists("place.txt")){
        file.open(QIODevice::ReadOnly);
        char cont[128];
        file.readLine(cont,sizeof(cont));
        place= QString(cont);
    }
        else return 1;
    }
    else
    {
//        QFile file("place.txt");
//        file.open(QIODevice::WriteOnly);
//        char cont[128];
//        cont= place.toLatin1();
//        QByteArray ba(cont);
//        file.write(ba);
    }
    qml_interface w(place);
#if defined(Q_WS_S60)
    w.showMaximized();
#else
    w.showMaximized();
#endif

    return a.exec();
}
