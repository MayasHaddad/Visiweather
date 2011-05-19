#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H
#include <QString>
//#include <QObject>
#include <QtNetwork/QHttp>
#include <QComboBox>
class autocomplete : public QObject
{
     Q_OBJECT

public:
    autocomplete();
    void connexion(QString);
    QStringList getListeVilles(QString);
    void addCache(QString,QStringList);
    bool InCache(QString);
    QString getFormatquery(QString);
signals:
    void requettereussie(QString);
public slots:
    QStringList traitementChaine(int,bool);
private :
        QHttp *QhttpClient;
        QStringList *ListeVilles;
        std::map<QString , QStringList> cache;
        std::map<QString , QString> formatquery;
        std::map<int , QString> mapdebut;
};

#endif // AUTOCOMPLETE_H
