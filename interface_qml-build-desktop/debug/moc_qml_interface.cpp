/****************************************************************************
** Meta object code from reading C++ file 'qml_interface.h'
**
** Created: Sat 18. Jun 12:29:33 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../interface_qml/qml_interface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qml_interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qml_interface[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       1,  104, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   14,   15,   14, 0x05,
      28,   14,   15,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   14,   14,   14, 0x0a,
      51,   14,   14,   14, 0x0a,

 // methods: signature, parameters, type, tag, flags
      89,   14,   81,   14, 0x02,
     104,   14,   81,   14, 0x02,
     123,   14,   81,   14, 0x02,
     135,   14,   81,   14, 0x02,
     152,   14,   81,   14, 0x02,
     162,   14,   81,   14, 0x02,
     172,   14,   81,   14, 0x02,
     182,   14,   81,   14, 0x02,
     192,   14,   81,   14, 0x02,
     202,   14,   81,   14, 0x02,
     212,   14,   81,   14, 0x02,
     222,   14,   81,   14, 0x02,
     238,   14,   14,   14, 0x02,
     247,   14,   15,   14, 0x02,

 // properties: name, type, flags
     274,  265, 0x00495009,

 // properties: notify_signal_id
       0,

       0        // eod
};

static const char qt_meta_stringdata_qml_interface[] = {
    "qml_interface\0\0int\0ItFogz()\0ItRains()\0"
    "updateSlot()\0replyFinished(QNetworkReply*)\0"
    "QString\0getWindSpeed()\0getWindDirection()\0"
    "getSymbol()\0getTemperature()\0getTime()\0"
    "depsurx()\0arvsurx()\0depsury()\0arvsury()\0"
    "depsurz()\0arvsurz()\0getNextUpdate()\0"
    "ItFogs()\0getPositionCiel()\0Forecast\0"
    "getCurrentForecast\0"
};

const QMetaObject qml_interface::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_qml_interface,
      qt_meta_data_qml_interface, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qml_interface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qml_interface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qml_interface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qml_interface))
        return static_cast<void*>(const_cast< qml_interface*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int qml_interface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { int _r = ItFogz();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = ItRains();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: updateSlot(); break;
        case 3: replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: { QString _r = getWindSpeed();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: { QString _r = getWindDirection();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: { QString _r = getSymbol();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 7: { QString _r = getTemperature();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 8: { QString _r = getTime();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 9: { QString _r = depsurx();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 10: { QString _r = arvsurx();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 11: { QString _r = depsury();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 12: { QString _r = arvsury();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 13: { QString _r = depsurz();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 14: { QString _r = arvsurz();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 15: { QString _r = getNextUpdate();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 16: ItFogs(); break;
        case 17: { int _r = getPositionCiel();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 18;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< Forecast*>(_v) = getCurrentForecast(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
int qml_interface::ItFogz()
{
    int _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
int qml_interface::ItRains()
{
    int _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
