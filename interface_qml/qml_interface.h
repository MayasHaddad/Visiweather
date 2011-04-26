#ifndef QML_INTERFACE_H
#define QML_INTERFACE_H

#include <QtGui/QMainWindow>
#include <QDeclarativeView>

class qml_interface : public QMainWindow
{
    Q_OBJECT

public:
    qml_interface(QWidget *parent = 0);
    ~qml_interface();
private:
    QDeclarativeView *view;
};

#endif // QML_INTERFACE_H
