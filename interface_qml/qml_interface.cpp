#include "qml_interface.h"
#include <QFile>
#include <QtGui>
#include <QXmlQuery>

#include "receiver.h"
#define MaRequete "declare variable $url external;\n" \
    "\n" \
    "doc($url)//lastupdate,\n" \
    "\n"\
    "doc($url)//nextupdate,\n" \
    "\n" \
    "doc($url)//sun,\n"\
    "for $time in doc($url)//tabular/time\n"\
    "    return <time>\n"\
    "       { $time/@from }\n"\
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

qml_interface::qml_interface(QString place, QWidget *parent)
    : QMainWindow(parent)
{
    this->fetchForecast(place);
    Forecast nowForecast = this->getCurrentForecast(QDateTime::currentDateTime ());
    view= new QDeclarativeView(this);
    view->setSource(QUrl("InterfaceAnime.qml"));
    QObject *objet= view->rootObject();
    objet->setProperty("whey",2);
    view->show();
}

void qml_interface::fetchForecast(QString place)
{
        QString url = QString("http://www.yr.no/place/%1/forecast.xml").arg(place);
        QXmlQuery query;

     query.bindVariable("url", QXmlItem(QVariant(url)));

    query.setQuery(MaRequete);
    Receiver receiver(query.namePool());
    if (query.isValid()) {
        QFile file("forecast.txt");
        file.open(QIODevice::WriteOnly);
        query.evaluateTo(&file);

        if (query.evaluateTo(&receiver)) {
            leveSoleil=QDateTime::fromString(receiver.sun["rise"]);
            coucheSoleil=QDateTime::fromString(receiver.sun["set"]);
            this->forecasts=receiver.forecasts;
            }
        }
}

Forecast qml_interface::getCurrentForecast(QDateTime time)
{
    bool recent=false;
    Forecast currentForecast;
    foreach (const Forecast &forecast, this->forecasts)
    {
        if(time < QDateTime::fromString(forecast.time["from"]) && recent)
        {
            return currentForecast;
        }

        if(time > QDateTime::fromString(forecast.time["from"]))
        {
              recent=true;
              currentForecast = forecast;
            }
    }
}
qml_interface::~qml_interface()
{

}
