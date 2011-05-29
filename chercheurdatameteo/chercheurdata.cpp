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

chercheurdata::chercheurdata(QString place)
{
   // place= new QString(places.at(1));
    this->ExecuteRequette(place); // "Italia/Toscana/Firenze"
}

void chercheurdata::ExecuteRequette(QString place)
{
    QString url = QString("http://www.yr.no/place/%1/forecast.xml").arg(place);
    QXmlQuery query;
    query.bindVariable("url", QXmlItem(QVariant(url)));
    query.setQuery(query_string);

    if (query.isValid()) {
        fichiernewdata = new QFile("newdata.txt");
        fichiercontiendata = new QFile("weatherdata.txt");
        query.evaluateTo(fichiercontiendata);
    }

}

void chercheurdata::CreeFichierNewData()
{

}

void chercheurdata::EcrisDansFichierData()
{

}
