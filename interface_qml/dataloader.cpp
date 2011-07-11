#include "dataloader.h"
#include <QtNetwork>
#include <QtXmlPatterns>
#include <QtGui>
#define MaRequete "declare variable $url external;\n" \
    "\n"\
    "doc($url)//name,\n" \
    "\n"\
    "doc($url)//country,\n" \
    "\n"\
    "doc($url)//nextupdate,\n" \
    "\n" \
    "doc($url)//sun,\n"\
    "for $time in doc($url)//tabular/time\n"\
    "    return <time>\n"\
    "       { $time/@from }\n"\
    "       { $time/@to }\n"\
    "        <symbol>\n"\
    " { $time/symbol/@number, $time/symbol/@name } \n"\
    "        </symbol>\n"\
    "        <windDirection>\n"\
    " { $time/windDirection/@code } \n"\
    "        </windDirection>\n"\
    "        <windSpeed>\n"\
    " { $time/windSpeed/@mps } \n"\
    "        </windSpeed>\n"\
    "       <temperature>\n"\
    "           { $time/temperature/@value, $time/temperature/@unit }\n"\
    "       </temperature>\n"\
    "       </time>"


void dataloader::fetchForecast(QString place,qml_interface* objet, int connexion)
{
   QString url;
   if (connexion == NewConnection)
   {
       url = QString("http://www.yr.no/place/%1/forecast.xml").arg(place);
       QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        connect(manager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(replyFinished(QNetworkReply*)));
        manager->get(QNetworkRequest(url));
   }
       else // Traiter le fichier local
   {
        QDir *nomfichier = new QDir();
        url= nomfichier->absoluteFilePath("forecast.xml");
   }
   QXmlQuery query;
    query.bindVariable("url", QXmlItem(QVariant(url)));
    query.setQuery(MaRequete);
    Receiver receiver(query.namePool());
    if (query.isValid()) {
            if (query.evaluateTo(&receiver))
              {
            objet->forecasts=receiver.forecasts;
            objet->nextUpdate=QDateTime::fromString(receiver.nextUpdate,"yyyy-MM-ddThh:mm:ss");
            objet->localisation=receiver.localisation;
            objet->country=receiver.country;
        }
     }
}

void dataloader::replyFinished(QNetworkReply* reponse)
{
    if(reponse->error()==QNetworkReply::NoError)
    {
    QByteArray xml=reponse->readAll();
    QFile myfile("forecast.xml");
    myfile.open(QIODevice::WriteOnly);
    myfile.write(xml);
    myfile.close();
    }
}

