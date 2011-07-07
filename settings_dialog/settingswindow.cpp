#include "settingswindow.h"
#include "autocomplete.h"
#include <QtNetwork>
#include <QEvent>
#include <QKeyEvent>
settingsWindow::settingsWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(360, 390);
    QFont font;
    font.setFamily(QString::fromUtf8("Arial"));
    setFont(font);
    setLayoutDirection(Qt::LeftToRight);
    setAutoFillBackground(true);
    centralwidget = new QWidget(this);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    verticalLayoutWidget_2 = new QWidget(centralwidget);
    verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
    verticalLayoutWidget_2->setGeometry(QRect(20, 20, 229, 231));
    layoutWidget_2 = new QVBoxLayout(verticalLayoutWidget_2);
    layoutWidget_2->setSpacing(30);
    layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
    layoutWidget_2->setSizeConstraint(QLayout::SetFixedSize);
    layoutWidget_2->setContentsMargins(0, 0, 0, 0);
    grandlayout = new QGridLayout();
    grandlayout->setSpacing(10);
    grandlayout->setObjectName(QString::fromUtf8("grandlayout"));
    grandlayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    grandlayout->setContentsMargins(0, 0, -1, -1);
    Layout_choix = new QGridLayout();
    Layout_choix->setObjectName(QString::fromUtf8("Layout_choix"));
    labelChoisirVille = new QLabel(verticalLayoutWidget_2);
    labelChoisirVille->setObjectName(QString::fromUtf8("labelChoisirVille"));

    complete = new autocomplete();

    Layout_choix->addWidget(labelChoisirVille, 0, 0, 1, 1);
    layoutLineEditPushButton = new QHBoxLayout();
    layoutLineEditPushButton->setObjectName(QString::fromUtf8("layoutLineEditPushButton"));
    lineEdit = new QLineEdit(verticalLayoutWidget_2);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
    lineEdit->setFrame(false);
    lineEdit->setDragEnabled(false);
    layoutLineEditPushButton->addWidget(lineEdit);
    pushButton = new QPushButton(verticalLayoutWidget_2);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));

    layoutLineEditPushButton->addWidget(pushButton);
    Layout_choix->addLayout(layoutLineEditPushButton, 1, 0, 1, 1);

    list = new QListWidget(this);
    //list->installEventFilter(this);
    list->hide();

    grandlayout->addLayout(Layout_choix, 0, 0, 1, 1);

    labelVilleOk = new QLabel(verticalLayoutWidget_2);
    labelVilleOk->setObjectName(QString::fromUtf8("labelVilleOk"));

    grandlayout->addWidget(labelVilleOk, 1, 0, 1, 1);

    QLabel *labelYrNo = new QLabel(verticalLayoutWidget_2);
    labelYrNo->setText("Weather forecast from yr.no,<br/> delivered by the Norwegian Meteorological Institute and the NRK");
    grandlayout->addWidget(labelYrNo, 1, 0, 1, 1);
    layoutWidget_2->addLayout(grandlayout);

    checkBox = new QCheckBox(verticalLayoutWidget_2);
    checkBox->setObjectName(QString::fromUtf8("checkBox"));

    layoutWidget_2->addWidget(checkBox);

    setCentralWidget(centralwidget);
    statusbar = new QStatusBar(this);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    setStatusBar(statusbar);

    retranslateUi(this);
    QObject::connect(pushButton, SIGNAL(clicked()), this, SLOT(ville_choisie()));
    QObject::connect(checkBox, SIGNAL(toggled(bool)), this, SLOT(fonctionner_en_hors_connex()));
    QObject::connect(complete,SIGNAL(requetereussie(QString)),this,SLOT(creeCompleter(QString)));
    QObject::connect(this,SIGNAL(cdanslcache(QString)),this,SLOT(creeCompleter(QString)));
    QObject::connect(lineEdit,SIGNAL(textEdited(QString)),this,SLOT(reConnec(QString)));
    QObject::connect(list,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(hidelist(QListWidgetItem*)));
    QMetaObject::connectSlotsByName(this);
    process = new QProcess();
    lance=false;
}

void settingsWindow::retranslateUi(QMainWindow *settingsWindow)
{
    setWindowTitle(QApplication::translate("settingsWindow", "settingsWindow", 0, QApplication::UnicodeUTF8));
    labelChoisirVille->setText(QApplication::translate("settingsWindow", "Choisir une localisation g\303\251ographique", 0, QApplication::UnicodeUTF8));
    lineEdit->setInputMask(QString());
    lineEdit->setText(QString());
//  lineEdit->setPlaceholderText(QApplication::translate("settingsWindow", "Saisir une localisation", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("settingsWindow", "Aller", 0, QApplication::UnicodeUTF8));
    labelVilleOk->setText(QString());
    checkBox->setText(QApplication::translate("settingsWindow", "fonctionner en mode hors connexion", 0, QApplication::UnicodeUTF8));
}

QString settingsWindow::get_concat()
{
   new_label= lineEdit->text();
   if (new_label != "")
   new_label += " a été choisie";
   return new_label;
}

void settingsWindow::ville_choisie()
{
    labelVilleOk->setText(complete->getFormatquery(lineEdit->text()));
      QStringList place;
      place.append(complete->getFormatquery(lineEdit->text()));
   process->startDetached("C:\\Visiweather1\\interface_qml-build-desktop\\debug\\interface_qml.exe",place);
}

void settingsWindow::fonctionner_en_hors_connex()
{
   if(checkBox->isChecked() && lance==false)
    {
  //  process->setWorkingDirectory ("C:\\Visiweather1\\interface_qml-build-desktop");
    process->startDetached("C:\\Visiweather1\\interface_qml-build-desktop\\release\\interface_qml.exe");
    lance=true;
    process->setReadChannel(QProcess::StandardOutput);
    QObject::connect(process, SIGNAL(readyRead()), this, SLOT(recup_channel()));
    }
   /*else
   {
     process->close();
   }*/
}

void settingsWindow::recup_channel()
{
    char data[256];
    //process->readData(data,256);
    labelVilleOk->setText(data);
    QDialog *win=new QDialog(this);
    win->show();
    lance=false;
}

void settingsWindow::creeCompleter(QString debut)
{
    if(complete->ListeCourrante())
    {
        complete->ListeCourrante();
    }
    wordList = complete->getListeVilles(debut);
    if(!wordList.isEmpty())
    {
        wordList.removeLast();
        complete->setListeCourrante(list);
    list->addItems(wordList);
    list->move(lineEdit->x()+20,lineEdit->y()+50);
    list->setFixedSize(lineEdit->width(),150);
    list->show();
    lineEdit->setFocus();
    }
}

void settingsWindow::reConnec(QString nouvotext)     // une fois le completer créé la premiere fois Il doit etre recréé apres qu'une touche a ete tapée
{
    if(list->isVisible())
    {
        list->clear();
        list->hide();
    }
    if(complete->InCache(nouvotext)) emit cdanslcache(nouvotext);
    else
        complete->connexion(nouvotext);
}

 void settingsWindow::setext(QString ville)
 {
    lineEdit->setText(ville);
 }

 void settingsWindow::hidelist(QListWidgetItem* item)
 {
     lineEdit->setText(item->text());
   list->hide();
 }

 bool settingsWindow::eventFilter(QObject *obj, QEvent *ev)
 {
     if (obj != list)
     {
         return false;
     }
     if (ev->type() == QEvent::MouseButtonPress) {
         list->hide();
         lineEdit->setFocus();
         return true;
     }
     if (ev->type() == QEvent::KeyPress) {

         bool consumed = false;
         int key = static_cast<QKeyEvent*>(ev)->key();
         switch (key) {
         case Qt::Key_Enter:
         case Qt::Key_Return:
             consumed = true;

         case Qt::Key_Escape:
             lineEdit->setFocus();
             list->hide();
             consumed = true;

         case Qt::Key_Up:
         case Qt::Key_Down:
         case Qt::Key_Home:
         case Qt::Key_End:
         case Qt::Key_PageUp:
         case Qt::Key_PageDown:
             break;

         default:
             lineEdit->setFocus();
             lineEdit->event(ev);
             list->hide();
             break;
         }

         return consumed;
     }

     return false;
 }


settingsWindow::~settingsWindow()
{

}
