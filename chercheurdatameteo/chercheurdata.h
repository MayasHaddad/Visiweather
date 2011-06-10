#ifndef CHERCHEURDATA_H
#define CHERCHEURDATA_H
#include<QStringList>
#include<QString>
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QXmlItem>
#include <QXmlQuery>
#include <QXmlResultItems>
#include <QThread>

class Chercheurdata
{
public:
    Chercheurdata();
void ExecuteRequete(QString);
private:
    void CreeFichierNewData();
    void EcrisDansFichierData();
    QString *place;
    QFile fichiernewdata;
    QFile fichiercontiendata;
};

#endif // CHERCHEURDATA_H
