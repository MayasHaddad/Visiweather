/****************************************************************************
** Meta object code from reading C++ file 'autocomplete.h'
**
** Created: Fri 8. Jul 07:15:40 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../settings_dialog/autocomplete.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'autocomplete.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_autocomplete[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,   50,   38,   13, 0x0a,
      79,   13,   38,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_autocomplete[] = {
    "autocomplete\0\0requetereussie(QString)\0"
    "QStringList\0,\0traitementChaine(int,bool)\0"
    "finishedSlot(QNetworkReply*)\0"
};

const QMetaObject autocomplete::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_autocomplete,
      qt_meta_data_autocomplete, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &autocomplete::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *autocomplete::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *autocomplete::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_autocomplete))
        return static_cast<void*>(const_cast< autocomplete*>(this));
    return QObject::qt_metacast(_clname);
}

int autocomplete::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: requetereussie((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: { QStringList _r = traitementChaine((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 2: { QStringList _r = finishedSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void autocomplete::requetereussie(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE