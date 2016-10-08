/****************************************************************************
** Meta object code from reading C++ file 'bezierqt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/bezierqt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bezierqt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BezierQt_t {
    QByteArrayData data[9];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BezierQt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BezierQt_t qt_meta_stringdata_BezierQt = {
    {
QT_MOC_LITERAL(0, 0, 8), // "BezierQt"
QT_MOC_LITERAL(1, 9, 7), // "newForm"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 7), // "newSoul"
QT_MOC_LITERAL(4, 26, 9), // "modeCurve"
QT_MOC_LITERAL(5, 36, 13), // "modeExtrusion"
QT_MOC_LITERAL(6, 50, 11), // "modeFacette"
QT_MOC_LITERAL(7, 62, 4), // "quit"
QT_MOC_LITERAL(8, 67, 12) // "UpdateData3D"

    },
    "BezierQt\0newForm\0\0newSoul\0modeCurve\0"
    "modeExtrusion\0modeFacette\0quit\0"
    "UpdateData3D"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BezierQt[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BezierQt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BezierQt *_t = static_cast<BezierQt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newForm(); break;
        case 1: _t->newSoul(); break;
        case 2: _t->modeCurve(); break;
        case 3: _t->modeExtrusion(); break;
        case 4: _t->modeFacette(); break;
        case 5: _t->quit(); break;
        case 6: _t->UpdateData3D(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject BezierQt::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_BezierQt.data,
      qt_meta_data_BezierQt,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BezierQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BezierQt::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BezierQt.stringdata0))
        return static_cast<void*>(const_cast< BezierQt*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int BezierQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
