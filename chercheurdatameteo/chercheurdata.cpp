#include <QtXmlPatterns/QXmlQuery>
#include "chercheurdata.h"

#define query_string "declare variable $url external;\n" \
                     "\n" \
                     "doc($url)//sun,\n" \
                     "for $time in doc($url)//tabular/time\n" \
                     "    order by $time/@from\n" \
                     "    return <time>\n" \
                     "       { $time/@from }\n" \
                     "       <symbol>\n" \
                     "           { $time/symbol/@name, $time/symbol/@number }\n" \
                     "       </symbol>\n" \
                     "       <temperature>\n" \
                     "           { $time/temperature/@value, $time/temperature/@unit }\n" \
                     "       </temperature>\n" \
                     "       </time>\n"
using namespace std;
Chercheurdata::Chercheurdata()
{
}

void Chercheurdata::ExecuteRequete(QString place)
{
   // QString url = QString("http://www.yr.no/place/%1/forecast.xml").arg(place);
    QString url="C:\\Users\\mayas\\Desktop\\qq33-xquery\\queries\\forecast.xml";
    QXmlQuery query;
    query.bindVariable("url", QXmlItem(QVariant(url)));

    query.setQuery(query_string);

    Receiver receiver(query.namePool());

    if (query.isValid()) {
        if (query.evaluateTo(&receiver)) {
            foreach (const Forecast &forecast, receiver.forecasts) {
                std::cout << qPrintable(forecast.time["from"]) << std::endl;
                std::cout << qPrintable(forecast.temperature["value"] + " " + forecast.temperature["unit"]) << std::endl;
            }
        }
    }
}
void Chercheurdata::CreeFichierNewData()
{
}

void Chercheurdata::EcrisDansFichierData()
{

}
