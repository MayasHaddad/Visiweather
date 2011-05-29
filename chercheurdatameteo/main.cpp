#include <QtCore/QCoreApplication>
#include "chercheurdata.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    chercheurdata chercher(QString(argv[1]));
    return a.exec();
}
