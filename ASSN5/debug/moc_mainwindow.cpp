/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[341];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "destroyed"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 3), // "obj"
QT_MOC_LITERAL(4, 26, 10), // "myfunction"
QT_MOC_LITERAL(5, 37, 23), // "on_Watch_button_clicked"
QT_MOC_LITERAL(6, 61, 12), // "startClicked"
QT_MOC_LITERAL(7, 74, 11), // "stopClicked"
QT_MOC_LITERAL(8, 86, 12), // "resetClicked"
QT_MOC_LITERAL(9, 99, 11), // "update_time"
QT_MOC_LITERAL(10, 111, 18), // "timer_startClicked"
QT_MOC_LITERAL(11, 130, 17), // "timer_stopClicked"
QT_MOC_LITERAL(12, 148, 18), // "timer_resetClicked"
QT_MOC_LITERAL(13, 167, 20), // "timer_hour_upClicked"
QT_MOC_LITERAL(14, 188, 19), // "timer_min_upClicked"
QT_MOC_LITERAL(15, 208, 19), // "timer_sec_upClicked"
QT_MOC_LITERAL(16, 228, 22), // "timer_hour_downClicked"
QT_MOC_LITERAL(17, 251, 21), // "timer_min_downClicked"
QT_MOC_LITERAL(18, 273, 21), // "timer_sec_downClicked"
QT_MOC_LITERAL(19, 295, 12), // "timer_update"
QT_MOC_LITERAL(20, 308, 26), // "on_tabWidget_tabBarClicked"
QT_MOC_LITERAL(21, 335, 5) // "index"

    },
    "MainWindow\0destroyed\0\0obj\0myfunction\0"
    "on_Watch_button_clicked\0startClicked\0"
    "stopClicked\0resetClicked\0update_time\0"
    "timer_startClicked\0timer_stopClicked\0"
    "timer_resetClicked\0timer_hour_upClicked\0"
    "timer_min_upClicked\0timer_sec_upClicked\0"
    "timer_hour_downClicked\0timer_min_downClicked\0"
    "timer_sec_downClicked\0timer_update\0"
    "on_tabWidget_tabBarClicked\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       1,    0,  112,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  113,    2, 0x08 /* Private */,
       5,    0,  114,    2, 0x08 /* Private */,
       6,    0,  115,    2, 0x08 /* Private */,
       7,    0,  116,    2, 0x08 /* Private */,
       8,    0,  117,    2, 0x08 /* Private */,
       9,    0,  118,    2, 0x08 /* Private */,
      10,    0,  119,    2, 0x08 /* Private */,
      11,    0,  120,    2, 0x08 /* Private */,
      12,    0,  121,    2, 0x08 /* Private */,
      13,    0,  122,    2, 0x08 /* Private */,
      14,    0,  123,    2, 0x08 /* Private */,
      15,    0,  124,    2, 0x08 /* Private */,
      16,    0,  125,    2, 0x08 /* Private */,
      17,    0,  126,    2, 0x08 /* Private */,
      18,    0,  127,    2, 0x08 /* Private */,
      19,    0,  128,    2, 0x08 /* Private */,
      20,    1,  129,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QObjectStar,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->destroyed((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 1: _t->destroyed(); break;
        case 2: _t->myfunction(); break;
        case 3: _t->on_Watch_button_clicked(); break;
        case 4: _t->startClicked(); break;
        case 5: _t->stopClicked(); break;
        case 6: _t->resetClicked(); break;
        case 7: _t->update_time(); break;
        case 8: _t->timer_startClicked(); break;
        case 9: _t->timer_stopClicked(); break;
        case 10: _t->timer_resetClicked(); break;
        case 11: _t->timer_hour_upClicked(); break;
        case 12: _t->timer_min_upClicked(); break;
        case 13: _t->timer_sec_upClicked(); break;
        case 14: _t->timer_hour_downClicked(); break;
        case 15: _t->timer_min_downClicked(); break;
        case 16: _t->timer_sec_downClicked(); break;
        case 17: _t->timer_update(); break;
        case 18: _t->on_tabWidget_tabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QObject * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::destroyed)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::destroyed(QObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
