/****************************************************************************
** Meta object code from reading C++ file 'settingswindow.h'
**
** Created: Thu 19. May 22:22:32 2011
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
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   15,   15,   15, 0x0a,
      53,   15,   15,   15, 0x0a,
      82,   15,   15,   15, 0x0a,
      98,   15,   15,   15, 0x0a,
     121,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_settingsWindow[] = {
    "settingsWindow\0\0cdanslcache(QString)\0"
    "ville_choisie()\0fonctionner_en_hors_connex()\0"
    "recup_channel()\0creeCompleter(QString)\0"
    "reConnec(QString)\0"
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
        case 0: cdanslcache((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: ville_choisie(); break;
        case 2: fonctionner_en_hors_connex(); break;
        case 3: recup_channel(); break;
        case 4: creeCompleter((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: reConnec((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void settingsWindow::cdanslcache(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
