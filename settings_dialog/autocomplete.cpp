#include "autocomplete.h"
#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValueIterator>
#include <QMessageBox>
#include <QtNetwork>

autocomplete::autocomplete()
{
//    QhttpClient= new QHttp("www.yr.no");
    ListeVilles= new QStringList("no data");
    req = new QNetworkAccessManager(this);
    QObject::connect(req, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(finishedSlot(QNetworkReply*)));
//    connect(QhttpClient,SIGNAL(requestFinished(int,bool)), this, SLOT(traitementChaine(int,bool)));

}

void autocomplete::connexion(QString debut)
{
   if(!(debut.startsWith(" ") || debut.isEmpty()))
   {
       this->debut=debut;
       QUrl url= QUrl(QString("http://www.yr.no/_/websvc/jsonforslagsboks.aspx?s="+debut));
       QNetworkRequest request=QNetworkRequest(url);
       req->get(request);
     //   int valeur = QhttpClient->get(QString("/_/websvc/jsonforslagsboks.aspx?s="+debut));
  //  QMessageBox::information(NULL, "Titre de la fenêtre",QString(valeur));
    //mapdebut[valeur]=debut;
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
        if (sc.isArray())
        {
                 QScriptValueIterator it(sc.property(1));
                 while (it.hasNext()) {
                     it.next();
                    liste << it.value().property(0).toString()+","+it.value().property(3).toString();
                    // liste de correspondance des villes et /place/
                    formatquery[it.value().property(0).toString()+","+it.value().property(3).toString()]=it.value().property(1).toString();
                 }
        }
        addCache(debut,liste);
   emit requetereussie((debut));
        return liste;
    } else
        QMessageBox::information(NULL, "Titre de la fenêtre", "il y a une erreur "+reply->errorString());
    return QStringList();
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
        sc = engine.evaluate(QString(result));
       //liste <<  sc.property("result").toString ();
        if (sc.isArray())
        {
                 QScriptValueIterator it(sc.property(1));
                 while (it.hasNext()) {
                     it.next();
                    liste << it.value().property(0).toString()+","+it.value().property(3).toString();
                    // liste de correspondance des villes et /place/
                    formatquery[it.value().property(0).toString()+","+it.value().property(3).toString()]=it.value().property(1).toString();
                 }
        }
       /* QComboBox* combo = new QComboBox();
        combo->addItems(liste);
        combo->show();*/
       // QMessageBox::information(NULL, "Titre de la fenêtre",QString("[result:")+QString(result)+QString("]"));
   addCache(debut,liste);
   emit requetereussie((debut));
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
