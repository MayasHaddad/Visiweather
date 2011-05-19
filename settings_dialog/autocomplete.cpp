#include "autocomplete.h"
#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValueIterator>
#include <QMessageBox>
autocomplete::autocomplete()
{
    QhttpClient= new QHttp("www.yr.no");
    ListeVilles= new QStringList("no data");
    connect(QhttpClient,SIGNAL(requestFinished(int,bool)), this, SLOT(traitementChaine(int,bool)));
}

void autocomplete::connexion(QString debut)
{
    int valeur = QhttpClient->get(QString("/_/websvc/jsonforslagsboks.aspx?s="+debut));
  //  QMessageBox::information(NULL, "Titre de la fenêtre",QString(valeur));
    mapdebut[valeur]=debut;
}

QStringList autocomplete::traitementChaine(int i,bool erreur)
{
    if(erreur){
    QMessageBox::information(NULL, "Titre de la fenêtre", "il y a une erreur "+QhttpClient->errorString());
    return QStringList(); }
    QStringList liste;
        QByteArray result;
        result = QhttpClient->readAll();
        QScriptValue sc;
        QScriptEngine engine;
        sc = engine.evaluate(QString(result));// In new versions it may need to look like engine.evaluate("(" + QString(result) + ")");
       //liste <<  sc.property("result").toString ();
        if (sc.isArray())
        {
                 QScriptValueIterator it(sc.property(1));
                 while (it.hasNext()) {
                     it.next();
                    liste << it.value().property(0).toString()+","+it.value().property(3).toString();
                 }
        }
       /* QComboBox* combo = new QComboBox();
        combo->addItems(liste);
        combo->show();*/
       // QMessageBox::information(NULL, "Titre de la fenêtre",QString("[result:")+QString(result)+QString("]"));
   addCache(mapdebut[i],liste);
  // mapdebut.erase(i);
    emit requettereussie((mapdebut[i]));
        return liste;
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
