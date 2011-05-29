#ifndef CHERCHEURDATA_H
#define CHERCHEURDATA_H
#include<QStringList>
#include<QString>
#include <iostream>
#include <fstream>
#include <QFile>
class chercheurdata
{
    Q_OBJECT
public:
    chercheurdata(QString);
    void ExecuteRequette(QString);
public slots:
    void CreeFichierNewData();
    void EcrisDansFichierData();
private:
    QString *place;
    QFile fichiernewdata;
    QFile fichiercontiendata;
};

#endif // CHERCHEURDATA_H
