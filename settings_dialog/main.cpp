#include <QtGui/QApplication>
#include "settingswindow.h"
#include <QNetworkConfiguration>
#include <QNetworkConfigurationManager>
#include <QtNetwork>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    settingsWindow w;
    w.setOrientation(settingsWindow::ScreenOrientationLockLandscape);
    w.show();
    return a.exec();
}
