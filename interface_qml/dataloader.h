#ifndef DATALOADER_H
#define DATALOADER_H
#include "qml_interface.h"
#include "receiver.h"
#define NewConnection 1
#define LastConnection 0

class dataloader : public QObject
{
    Q_OBJECT
public:
    dataloader(){}
    void fetchForecast(QString,qml_interface*,int connexion = LastConnection );
public slots:
    void replyFinished(QNetworkReply*);
};

#endif // DATALOADER_H
