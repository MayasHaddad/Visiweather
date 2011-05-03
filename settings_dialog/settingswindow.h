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
class settingsWindow : public QMainWindow
{
    Q_OBJECT

public:
    settingsWindow(QWidget *parent = 0);
    void retranslateUi(QMainWindow *settingsWindow);
    QString get_concat();
    ~settingsWindow();
public slots:
    void ville_choisie();
    void fonctionner_en_hors_connex();
    void recup_channel();
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
    QCompleter *completer;
    QProcess *process;
    QStringList wordList;
    bool lance;
};

#endif // SETTINGSWINDOW_H
