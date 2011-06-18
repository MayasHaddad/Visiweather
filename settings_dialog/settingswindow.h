#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QDialog>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QProcess>
#include <QCompleter>
#include <QMessageBox>
#include <QListWidget>
#include <QComboBox>
class autocomplete;
class settingsWindow : public QMainWindow
{
    Q_OBJECT

public:
    settingsWindow(QWidget *parent = 0);
    void retranslateUi(QMainWindow *settingsWindow);
    QString get_concat();
    bool eventFilter(QObject *obj, QEvent *ev);
    ~settingsWindow();
signals:
    void cdanslcache(QString);
public slots:
    void ville_choisie();
    void fonctionner_en_hors_connex();
    void recup_channel();
    void creeCompleter(QString);
    void reConnec(QString);
     void setext(QString);
     void hidelist();
private:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *layoutWidget_2;
    QGridLayout *grandlayout;
    QGridLayout *Layout_choix;
    QLabel *labelChoisirVille;
    QHBoxLayout *layoutLineEditPushButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *labelVilleOk;
    QCheckBox *checkBox;
    QStatusBar *statusbar;
    QString new_label;
    std::map<QString , QCompleter *> completer;
    QProcess *process;
    QStringList wordList;
    QListWidget*list;
    autocomplete *complete;
    bool lance;
};

#endif // SETTINGSWINDOW_H
