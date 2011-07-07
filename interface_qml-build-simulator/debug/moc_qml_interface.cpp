/****************************************************************************
** Meta object code from reading C++ file 'qml_interface.h'
**
** Created: Tue 28. Jun 14:37:10 2011
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
      27,   14, // methods
       1,  149, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      24,   14,   14,   14, 0x05,
      37,   14,   14,   14, 0x05,
      44,   14,   14,   14, 0x05,
      54,   14,   14,   14, 0x05,
      63,   14,   14,   14, 0x05,
      70,   14,   14,   14, 0x05,
      80,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      87,   14,   14,   14, 0x0a,
     100,   14,   14,   14, 0x0a,

 // methods: signature, parameters, type, tag, flags
     138,   14,  130,   14, 0x02,
     153,   14,  130,   14, 0x02,
     172,   14,  130,   14, 0x02,
     189,   14,  130,   14, 0x02,
     199,   14,  130,   14, 0x02,
     209,   14,  130,   14, 0x02,
     219,   14,  130,   14, 0x02,
     229,   14,  130,   14, 0x02,
     239,   14,  130,   14, 0x02,
     249,   14,  130,   14, 0x02,
     259,   14,  130,   14, 0x02,
     275,   14,  130,   14, 0x02,
     290,   14,  130,   14, 0x02,
     302,   14,   14,   14, 0x02,
     315,   14,  311,   14, 0x02,
     333,   14,   14,   14, 0x02,
     345,   14,  130,   14, 0x02,

 // properties: name, type, flags
     373,  364, 0x00095009,

 // properties: notify_signal_id
       0,

       0        // eod
};

static const char qt_meta_stringdata_qml_interface[] = {
    "qml_interface\0\0itFogz()\0destroyAll()\0"
    "fair()\0pCloudy()\0cloudy()\0rain()\0"
    "thunder()\0snow()\0updateSlot()\0"
    "replyFinished(QNetworkReply*)\0QString\0"
    "getWindSpeed()\0getWindDirection()\0"
    "getTemperature()\0getTime()\0depsurx()\0"
    "arvsurx()\0depsury()\0arvsury()\0depsurz()\0"
    "arvsurz()\0getNextUpdate()\0getFrequence()\0"
    "getSymbol()\0ItFogs()\0int\0getPositionCiel()\0"
    "setSymbol()\0getRandomInteger()\0Forecast\0"
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
        case 0: itFogz(); break;
        case 1: destroyAll(); break;
        case 2: fair(); break;
        case 3: pCloudy(); break;
        case 4: cloudy(); break;
        case 5: rain(); break;
        case 6: thunder(); break;
        case 7: snow(); break;
        case 8: updateSlot(); break;
        case 9: replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 10: { QString _r = getWindSpeed();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 11: { QString _r = getWindDirection();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 12: { QString _r = getTemperature();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 13: { QString _r = getTime();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 14: { QString _r = depsurx();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 15: { QString _r = arvsurx();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 16: { QString _r = depsury();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 17: { QString _r = arvsury();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 18: { QString _r = depsurz();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 19: { QString _r = arvsurz();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 20: { QString _r = getNextUpdate();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 21: { QString _r = getFrequence();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 22: { QString _r = getSymbol();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 23: ItFogs(); break;
        case 24: { int _r = getPositionCiel();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 25: setSymbol(); break;
        case 26: { QString _r = getRandomInteger();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 27;
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
void qml_interface::itFogz()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void qml_interface::destroyAll()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void qml_interface::fair()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void qml_interface::pCloudy()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void qml_interface::cloudy()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void qml_interface::rain()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void qml_interface::thunder()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void qml_interface::snow()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}
QT_END_MOC_NAMESPACE
