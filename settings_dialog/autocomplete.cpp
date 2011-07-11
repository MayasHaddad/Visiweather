#include "autocomplete.h"
#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValueIterator>
#include <QMessageBox>
#include <QtNetwork>

autocomplete::autocomplete()
{
    ListeVilles= new QStringList("no data");
    req = new QNetworkAccessManager(this);
    QObject::connect(req, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(finishedSlot(QNetworkReply*)));

}

void autocomplete::connexion(QString debut)
{
   if(!(debut.startsWith(" ") || debut.isEmpty()))
   {
       this->debut=debut;
       QUrl url= QUrl(QString("http://www.yr.no/_/websvc/jsonforslagsboks.aspx?s="+debut));
       QNetworkRequest request=QNetworkRequest(url);
       req->get(request);
   }
}

QStringList autocomplete::finishedSlot(QNetworkReply* reply)
{
    if(reply->error()==QNetworkReply::NoError)
    {
        QByteArray result;
        result =reply->readAll();
        QStringList liste;
        QScriptValue sc;
        QScriptEngine engine;
        sc = engine.evaluate(QString(result));
        QRegExp formatValid("/sted/(.+/){3}");
        QRegExpValidator v(formatValid,this);
        QString *str=new QString();
        int h=0;
        if (sc.isArray())
        {
                 QScriptValueIterator it(sc.property(1));
                 while (it.hasNext()) {
                     it.next();
                     *str=QString::fromUtf8(it.value().property(1).toString().toAscii());
                     if (v.validate(*str,h)==QValidator::Acceptable)
                     {
                    liste << QString::fromUtf8(it.value().property(0).toString().toAscii())+","+it.value().property(3).toString();
                    // liste de correspondance des villes et /place/
                    formatquery[QString::fromUtf8(it.value().property(0).toString().toAscii())+","+it.value().property(3).toString()]=QString::fromUtf8(it.value().property(1).toString().toAscii());
                     }
                     }
        }
        addCache(debut,liste);
   emit requetereussie((debut));
        return liste;
    } else
        QMessageBox::information(NULL, "Titre de la fenêtre", "il y a une erreur "+reply->errorString());
    return QStringList();
}


QStringList autocomplete::getListeVilles(QString debut)
{
    return cache[debut];
}

void autocomplete::addCache(QString cle, QStringList wordlist)
{
    cache[cle]=wordlist;
}

bool autocomplete::InCache(QString debut)
{
    return cache.count(debut);
}

QString autocomplete::getFormatquery(QString formatutilisateur)
{
    return formatquery[formatutilisateur].remove("/sted/");
}

void autocomplete::setListeCourrante(QListWidget* listecourrant)
{
    this->currentListWidget=listecourrant;
}
QListWidget* autocomplete::ListeCourrante()
{
    return this->currentListWidget;
}
