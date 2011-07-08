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
        else place="none"; // Lancement de l'application sans localisation
     }
    else // argument "place" existant: sauvegarder dans le fichier last_place.txt
    {
        QFile file("last_place.txt");
        file.open(QIODevice::WriteOnly);
        file.write(place.toUtf8());
       file.close();
    }

    qml_interface w(place);
    w.affiche();
    return a.exec();
}
