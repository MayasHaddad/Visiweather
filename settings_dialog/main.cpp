#include <QtGui/QApplication>
#include "settingswindow.h"
#include <QNetworkConfiguration>
#include <QNetworkConfigurationManager>
#include <QtNetwork>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    settingsWindow w;
#if defined(Q_WS_S60)
    //qt_SetDefaultIapName(qt_OfferIapDialog());
//    QList<QNetworkConfiguration> liste;
//    liste = QNetworkConfigurationManager::allConfigurations (QNetworkConfiguration::Discovered );
//    QNetworkSession network = new QNetworkSession();
//   /* QList<int>liste;
//    l*/iste << 1 << 2 << 3 << 4;
    w.showMaximized();
#else
    w.show();
#endif

    return a.exec();
}
