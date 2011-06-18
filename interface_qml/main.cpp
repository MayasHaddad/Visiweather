#include <QtGui/QApplication>
#include <QFile>
#include "qml_interface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString place = argv[1];
    if (place.isNull())
    {
        QFile file("last_place.txt");
        if (file.exists("last_place.txt")){
        file.open(QIODevice::ReadOnly);
        char cont[128];
        file.readLine(cont,sizeof(cont));
        place= QString(cont);
    }
        else return 1;
    }
    else // argument place existant: sauvegarder
    {
        QFile file("last_place.txt");
        file.open(QIODevice::WriteOnly);
        file.write(place.toUtf8());
       file.close();
    }
    qml_interface w(place);
w.affiche();
//#if defined(Q_WS_S60)
//    w.showMaximized();
//#else
//    w.showMaximized();
//#endif

    return a.exec();
}
