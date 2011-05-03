#include "qml_interface.h"

qml_interface::qml_interface(QWidget *parent)
    : QMainWindow(parent)
{
    view= new QDeclarativeView(this);
    std::cout << "interface qml fermé";
    view->setSource(QUrl("InterfaceAnime.qml"));
    view->show();
}

qml_interface::~qml_interface()
{

}
