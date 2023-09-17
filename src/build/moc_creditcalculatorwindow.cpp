/****************************************************************************
** Meta object code from reading C++ file 'creditcalculatorwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../calc/creditcalculatorwindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'creditcalculatorwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSCreditCalculatorWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSCreditCalculatorWindowENDCLASS = QtMocHelpers::stringData(
    "CreditCalculatorWindow",
    "switchToMainCalculator",
    "",
    "calculate",
    "showAllRows",
    "handleBackButton",
    "insertTableRow",
    "row",
    "monthlyPayment",
    "principalPayment",
    "interestPayment",
    "balanceOwed"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCreditCalculatorWindowENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[23];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[12];
    char stringdata5[17];
    char stringdata6[15];
    char stringdata7[4];
    char stringdata8[15];
    char stringdata9[17];
    char stringdata10[16];
    char stringdata11[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCreditCalculatorWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCreditCalculatorWindowENDCLASS_t qt_meta_stringdata_CLASSCreditCalculatorWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 22),  // "CreditCalculatorWindow"
        QT_MOC_LITERAL(23, 22),  // "switchToMainCalculator"
        QT_MOC_LITERAL(46, 0),  // ""
        QT_MOC_LITERAL(47, 9),  // "calculate"
        QT_MOC_LITERAL(57, 11),  // "showAllRows"
        QT_MOC_LITERAL(69, 16),  // "handleBackButton"
        QT_MOC_LITERAL(86, 14),  // "insertTableRow"
        QT_MOC_LITERAL(101, 3),  // "row"
        QT_MOC_LITERAL(105, 14),  // "monthlyPayment"
        QT_MOC_LITERAL(120, 16),  // "principalPayment"
        QT_MOC_LITERAL(137, 15),  // "interestPayment"
        QT_MOC_LITERAL(153, 11)   // "balanceOwed"
    },
    "CreditCalculatorWindow",
    "switchToMainCalculator",
    "",
    "calculate",
    "showAllRows",
    "handleBackButton",
    "insertTableRow",
    "row",
    "monthlyPayment",
    "principalPayment",
    "interestPayment",
    "balanceOwed"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCreditCalculatorWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    5,   48,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    7,    8,    9,   10,   11,

       0        // eod
};

Q_CONSTINIT const QMetaObject CreditCalculatorWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSCreditCalculatorWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCreditCalculatorWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCreditCalculatorWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CreditCalculatorWindow, std::true_type>,
        // method 'switchToMainCalculator'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'calculate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showAllRows'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleBackButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'insertTableRow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>
    >,
    nullptr
} };

void CreditCalculatorWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CreditCalculatorWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->switchToMainCalculator(); break;
        case 1: _t->calculate(); break;
        case 2: _t->showAllRows(); break;
        case 3: _t->handleBackButton(); break;
        case 4: _t->insertTableRow((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CreditCalculatorWindow::*)();
            if (_t _q_method = &CreditCalculatorWindow::switchToMainCalculator; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *CreditCalculatorWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreditCalculatorWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCreditCalculatorWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CreditCalculatorWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CreditCalculatorWindow::switchToMainCalculator()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
