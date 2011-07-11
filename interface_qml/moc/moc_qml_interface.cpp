/****************************************************************************
** Meta object code from reading C++ file 'qml_interface.h'
**
** Created: Sun 10. Jul 00:56:32 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qml_interface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qml_interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qml_interface[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      24,   14,   14,   14, 0x05,
      37,   14,   14,   14, 0x05,
      44,   14,   14,   14, 0x05,
      54,   14,   14,   14, 0x05,
      63,   14,   14,   14, 0x05,
      70,   14,   14,   14, 0x05,
      80,   14,   14,   14, 0x05,
      87,   14,   14,   14, 0x05,
      93,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     101,   14,   14,   14, 0x0a,

 // methods: signature, parameters, type, tag, flags
     122,   14,  114,   14, 0x02,
     137,   14,  114,   14, 0x02,
     156,   14,  114,   14, 0x02,
     173,   14,  114,   14, 0x02,
     183,   14,  114,   14, 0x02,
     193,   14,  114,   14, 0x02,
     203,   14,  114,   14, 0x02,
     213,   14,  114,   14, 0x02,
     223,   14,  114,   14, 0x02,
     233,   14,  114,   14, 0x02,
     243,   14,  114,   14, 0x02,
     259,   14,  114,   14, 0x02,
     274,   14,  114,   14, 0x02,
     286,   14,   14,   14, 0x02,
     299,   14,  295,   14, 0x02,
     317,   14,   14,   14, 0x02,
     329,   14,  114,   14, 0x02,
     348,   14,  114,   14, 0x02,
     356,   14,  114,   14, 0x02,
     363,   14,  114,   14, 0x02,
     381,   14,  114,   14, 0x02,
     394,   14,   14,   14, 0x02,
     410,   14,   14,   14, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_qml_interface[] = {
    "qml_interface\0\0itFogz()\0destroyAll()\0"
    "fair()\0pCloudy()\0cloudy()\0rain()\0"
    "thunder()\0snow()\0day()\0night()\0"
    "updateSlot()\0QString\0getWindSpeed()\0"
    "getWindDirection()\0getTemperature()\0"
    "getTime()\0depsurx()\0arvsurx()\0depsury()\0"
    "arvsury()\0depsurz()\0arvsurz()\0"
    "getNextUpdate()\0getFrequence()\0"
    "getSymbol()\0ItFogs()\0int\0getPositionCiel()\0"
    "setSymbol()\0getRandomInteger()\0getDe()\0"
    "getA()\0getLocalisation()\0getCountry()\0"
    "thunderEmetor()\0setNightOrDay()\0"
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
        case 8: day(); break;
        case 9: night(); break;
        case 10: updateSlot(); break;
        case 11: { QString _r = getWindSpeed();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 12: { QString _r = getWindDirection();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 13: { QString _r = getTemperature();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 14: { QString _r = getTime();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 15: { QString _r = depsurx();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 16: { QString _r = arvsurx();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 17: { QString _r = depsury();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 18: { QString _r = arvsury();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 19: { QString _r = depsurz();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 20: { QString _r = arvsurz();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 21: { QString _r = getNextUpdate();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 22: { QString _r = getFrequence();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 23: { QString _r = getSymbol();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 24: ItFogs(); break;
        case 25: { int _r = getPositionCiel();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 26: setSymbol(); break;
        case 27: { QString _r = getRandomInteger();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 28: { QString _r = getDe();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 29: { QString _r = getA();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 30: { QString _r = getLocalisation();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 31: { QString _r = getCountry();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 32: thunderEmetor(); break;
        case 33: setNightOrDay(); break;
        default: ;
        }
        _id -= 34;
    }
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

// SIGNAL 8
void qml_interface::day()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void qml_interface::night()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}
QT_END_MOC_NAMESPACE
