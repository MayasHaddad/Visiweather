/****************************************************************************
** Meta object code from reading C++ file 'dataloader.h'
**
** Created: Thu 7. Jul 22:28:42 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../interface_qml/dataloader.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataloader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dataloader[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_dataloader[] = {
    "dataloader\0\0replyFinished(QNetworkReply*)\0"
};

const QMetaObject dataloader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_dataloader,
      qt_meta_data_dataloader, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dataloader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dataloader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dataloader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dataloader))
        return static_cast<void*>(const_cast< dataloader*>(this));
    return QObject::qt_metacast(_clname);
}

int dataloader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
