#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H
#include <QString>
//#include <QObject>
#include <QtNetwork/QHttp>
#include <QComboBox>
#include <QListWidget>
#include <QtNetwork>
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
    QListWidget* ListeCourrante();
    void setListeCourrante(QListWidget*);
signals:
    void requetereussie(QString);
public slots:
    QStringList traitementChaine(int,bool);
    QStringList finishedSlot(QNetworkReply*);
private :
        QHttp *QhttpClient;
        QStringList *ListeVilles;
        std::map<QString , QStringList> cache;
        std::map<QString , QString> formatquery;
         QString debut;
         QNetworkAccessManager *req;
         QListWidget *currentListWidget;
};

#endif // AUTOCOMPLETE_H
