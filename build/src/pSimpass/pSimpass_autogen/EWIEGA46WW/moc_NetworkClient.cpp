/****************************************************************************
** Meta object code from reading C++ file 'NetworkClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/pSimpass/NetworkClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NetworkClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NetworkClient_t {
    QByteArrayData data[12];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetworkClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetworkClient_t qt_meta_stringdata_NetworkClient = {
    {
QT_MOC_LITERAL(0, 0, 13), // "NetworkClient"
QT_MOC_LITERAL(1, 14, 15), // "MessageReceived"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 3), // "msg"
QT_MOC_LITERAL(4, 35, 19), // "MessageReceivedTest"
QT_MOC_LITERAL(5, 55, 4), // "type"
QT_MOC_LITERAL(6, 60, 20), // "std::vector<QString>"
QT_MOC_LITERAL(7, 81, 9), // "Connected"
QT_MOC_LITERAL(8, 91, 12), // "Disconnected"
QT_MOC_LITERAL(9, 104, 12), // "NetworkError"
QT_MOC_LITERAL(10, 117, 14), // "ReceiveTCPData"
QT_MOC_LITERAL(11, 132, 14) // "ReceiveUDPData"

    },
    "NetworkClient\0MessageReceived\0\0msg\0"
    "MessageReceivedTest\0type\0std::vector<QString>\0"
    "Connected\0Disconnected\0NetworkError\0"
    "ReceiveTCPData\0ReceiveUDPData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetworkClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    2,   52,    2, 0x06 /* Public */,
       7,    0,   57,    2, 0x06 /* Public */,
       8,    0,   58,    2, 0x06 /* Public */,
       9,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   60,    2, 0x09 /* Protected */,
      11,    0,   61,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 6,    5,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NetworkClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NetworkClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->MessageReceived((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 1: _t->MessageReceivedTest((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const std::vector<QString>(*)>(_a[2]))); break;
        case 2: _t->Connected(); break;
        case 3: _t->Disconnected(); break;
        case 4: _t->NetworkError(); break;
        case 5: _t->ReceiveTCPData(); break;
        case 6: _t->ReceiveUDPData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NetworkClient::*)(const QStringList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkClient::MessageReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NetworkClient::*)(const QString & , const std::vector<QString> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkClient::MessageReceivedTest)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NetworkClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkClient::Connected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NetworkClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkClient::Disconnected)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (NetworkClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkClient::NetworkError)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NetworkClient::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_NetworkClient.data,
    qt_meta_data_NetworkClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NetworkClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetworkClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NetworkClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void NetworkClient::MessageReceived(const QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetworkClient::MessageReceivedTest(const QString & _t1, const std::vector<QString> & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NetworkClient::Connected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void NetworkClient::Disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void NetworkClient::NetworkError()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
