#include "settingswindow.h"
#include "autocomplete.h"
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
    complete->connexion("");

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


    grandlayout->addLayout(Layout_choix, 0, 0, 1, 1);

    labelVilleOk = new QLabel(verticalLayoutWidget_2);
    labelVilleOk->setObjectName(QString::fromUtf8("labelVilleOk"));

    grandlayout->addWidget(labelVilleOk, 1, 0, 1, 1);


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
    QObject::connect(complete,SIGNAL(requettereussie(QString)),this,SLOT(creeCompleter(QString)));
    QObject::connect(this,SIGNAL(cdanslcache(QString)),this,SLOT(creeCompleter(QString)));
    QObject::connect(lineEdit,SIGNAL(textEdited(QString)),this,SLOT(reConnec(QString)));

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
    lineEdit->setPlaceholderText(QApplication::translate("settingsWindow", "Saisir une localisation", 0, QApplication::UnicodeUTF8));
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
}

void settingsWindow::fonctionner_en_hors_connex()
{
   if(checkBox->isChecked() && lance==false)
    {
  // process->setWorkingDirectory ("");
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
    /*
    char data[256];
    process->readData(data,256);
    labelVilleOk->setText(data);*/
    QDialog *win=new QDialog(this);
    win->show();
    lance=false;
}

void settingsWindow::creeCompleter(QString debut)
{
    wordList = complete->getListeVilles(lineEdit->text());
   //wordList <<"Hassi Messaoud" << "Tizi Ouzou" << "Bejaïa" << "Draâ Ben Khedda" << "Tizi Rached" << "Hassi Bahbah" << "Oran" << "Alger" << "Tamanrasset";
   completer[debut] = new QCompleter(wordList,lineEdit);
   completer[debut]->setCaseSensitivity(Qt::CaseInsensitive);
   lineEdit->setCompleter(completer[debut]);
   lineEdit->setFocus(Qt::OtherFocusReason);
}

void settingsWindow::reConnec(QString nouvotext)     // une fois le completer créé la premiere fois Il doit etre recréé apres qu'une touche a ete tapée
{
    lineEdit->setCompleter(0);
    if(complete->InCache(nouvotext)) emit cdanslcache(nouvotext);
    else complete->connexion(nouvotext);
}

settingsWindow::~settingsWindow()
{

}
