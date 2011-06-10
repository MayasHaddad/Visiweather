#include <QtCore/QCoreApplication>
#include "chercheurdata.h"
#include <QVariant>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Chercheurdata chercher;
    chercher.ExecuteRequete(QString(argv[1]));
    return a.exec();
}
