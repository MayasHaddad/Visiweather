/****************************************************************************
** Meta object code from reading C++ file 'settingswindow.h'
**
** Created: Sat 30. Apr 01:42:36 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../settings_dialog/settingswindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_settingsWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      32,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_settingsWindow[] = {
    "settingsWindow\0\0ville_choisie()\0"
    "fonctionner_en_hors_connex()\0"
};

const QMetaObject settingsWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_settingsWindow,
      qt_meta_data_settingsWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &settingsWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *settingsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *settingsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_settingsWindow))
        return static_cast<void*>(const_cast< settingsWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int settingsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: ville_choisie(); break;
        case 1: fonctionner_en_hors_connex(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
