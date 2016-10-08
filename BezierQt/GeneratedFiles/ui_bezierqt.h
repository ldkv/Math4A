/********************************************************************************
** Form generated from reading UI file 'bezierqt.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEZIERQT_H
#define UI_BEZIERQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BezierQtClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *centralHLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *boxForm;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *boxFormLayout;
    QGroupBox *boxSoul;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *boxSoulLayout;
    QGroupBox *boxSurface;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *boxSurfaceLayout;
    QStatusBar *statusBar;
    QDockWidget *dockConfig;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *CreationBox;
    QVBoxLayout *verticalLayout_11;
    QPushButton *buttonCreateForm;
    QCheckBox *checkClosedForm;
    QPushButton *buttonCreateSoul;
    QCheckBox *checkClosedSoul;
    QGroupBox *TypeExtrusionBox;
    QVBoxLayout *verticalLayout_10;
    QRadioButton *radioCornerCutting;
    QRadioButton *radioCasteljau;
    QGroupBox *TypeCurveBox;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *radioSimple;
    QRadioButton *radioRevolution;
    QRadioButton *radioGeneral;
    QVBoxLayout *verticalLayout_6;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *coeffEdit;
    QLabel *label;
    QLineEdit *pasEdit;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_12;
    QRadioButton *radioRectangle;
    QRadioButton *radioTriangle;
    QSpacerItem *verticalSpacer;
    QPushButton *buttonQuit;

    void setupUi(QMainWindow *BezierQtClass)
    {
        if (BezierQtClass->objectName().isEmpty())
            BezierQtClass->setObjectName(QStringLiteral("BezierQtClass"));
        BezierQtClass->resize(1123, 792);
        centralWidget = new QWidget(BezierQtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        centralHLayout = new QHBoxLayout();
        centralHLayout->setSpacing(6);
        centralHLayout->setObjectName(QStringLiteral("centralHLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        boxForm = new QGroupBox(widget);
        boxForm->setObjectName(QStringLiteral("boxForm"));
        verticalLayout_5 = new QVBoxLayout(boxForm);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        boxFormLayout = new QVBoxLayout();
        boxFormLayout->setSpacing(6);
        boxFormLayout->setObjectName(QStringLiteral("boxFormLayout"));

        verticalLayout_5->addLayout(boxFormLayout);


        verticalLayout->addWidget(boxForm);


        verticalLayout_2->addLayout(verticalLayout);

        boxSoul = new QGroupBox(widget);
        boxSoul->setObjectName(QStringLiteral("boxSoul"));
        verticalLayout_8 = new QVBoxLayout(boxSoul);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        boxSoulLayout = new QVBoxLayout();
        boxSoulLayout->setSpacing(6);
        boxSoulLayout->setObjectName(QStringLiteral("boxSoulLayout"));

        verticalLayout_8->addLayout(boxSoulLayout);


        verticalLayout_2->addWidget(boxSoul);


        centralHLayout->addWidget(widget);

        boxSurface = new QGroupBox(centralWidget);
        boxSurface->setObjectName(QStringLiteral("boxSurface"));
        verticalLayout_9 = new QVBoxLayout(boxSurface);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        boxSurfaceLayout = new QVBoxLayout();
        boxSurfaceLayout->setSpacing(6);
        boxSurfaceLayout->setObjectName(QStringLiteral("boxSurfaceLayout"));

        verticalLayout_9->addLayout(boxSurfaceLayout);


        centralHLayout->addWidget(boxSurface);


        horizontalLayout->addLayout(centralHLayout);

        BezierQtClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(BezierQtClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        BezierQtClass->setStatusBar(statusBar);
        dockConfig = new QDockWidget(BezierQtClass);
        dockConfig->setObjectName(QStringLiteral("dockConfig"));
        dockConfig->setEnabled(true);
        QFont font;
        font.setPointSize(8);
        dockConfig->setFont(font);
        dockConfig->setAutoFillBackground(false);
        dockConfig->setFloating(false);
        dockConfig->setFeatures(QDockWidget::NoDockWidgetFeatures);
        dockConfig->setAllowedAreas(Qt::LeftDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        CreationBox = new QGroupBox(dockWidgetContents);
        CreationBox->setObjectName(QStringLiteral("CreationBox"));
        verticalLayout_11 = new QVBoxLayout(CreationBox);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        buttonCreateForm = new QPushButton(CreationBox);
        buttonCreateForm->setObjectName(QStringLiteral("buttonCreateForm"));
        buttonCreateForm->setCheckable(true);

        verticalLayout_11->addWidget(buttonCreateForm);

        checkClosedForm = new QCheckBox(CreationBox);
        checkClosedForm->setObjectName(QStringLiteral("checkClosedForm"));
        checkClosedForm->setChecked(true);

        verticalLayout_11->addWidget(checkClosedForm);

        buttonCreateSoul = new QPushButton(CreationBox);
        buttonCreateSoul->setObjectName(QStringLiteral("buttonCreateSoul"));
        buttonCreateSoul->setCheckable(true);

        verticalLayout_11->addWidget(buttonCreateSoul);

        checkClosedSoul = new QCheckBox(CreationBox);
        checkClosedSoul->setObjectName(QStringLiteral("checkClosedSoul"));
        checkClosedSoul->setChecked(true);

        verticalLayout_11->addWidget(checkClosedSoul);


        verticalLayout_4->addWidget(CreationBox);

        TypeExtrusionBox = new QGroupBox(dockWidgetContents);
        TypeExtrusionBox->setObjectName(QStringLiteral("TypeExtrusionBox"));
        verticalLayout_10 = new QVBoxLayout(TypeExtrusionBox);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        radioCornerCutting = new QRadioButton(TypeExtrusionBox);
        radioCornerCutting->setObjectName(QStringLiteral("radioCornerCutting"));
        radioCornerCutting->setChecked(true);

        verticalLayout_10->addWidget(radioCornerCutting);

        radioCasteljau = new QRadioButton(TypeExtrusionBox);
        radioCasteljau->setObjectName(QStringLiteral("radioCasteljau"));

        verticalLayout_10->addWidget(radioCasteljau);


        verticalLayout_4->addWidget(TypeExtrusionBox);

        TypeCurveBox = new QGroupBox(dockWidgetContents);
        TypeCurveBox->setObjectName(QStringLiteral("TypeCurveBox"));
        verticalLayout_7 = new QVBoxLayout(TypeCurveBox);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        radioSimple = new QRadioButton(TypeCurveBox);
        radioSimple->setObjectName(QStringLiteral("radioSimple"));
        radioSimple->setChecked(true);

        verticalLayout_7->addWidget(radioSimple);

        radioRevolution = new QRadioButton(TypeCurveBox);
        radioRevolution->setObjectName(QStringLiteral("radioRevolution"));

        verticalLayout_7->addWidget(radioRevolution);

        radioGeneral = new QRadioButton(TypeCurveBox);
        radioGeneral->setObjectName(QStringLiteral("radioGeneral"));

        verticalLayout_7->addWidget(radioGeneral);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(TypeCurveBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        coeffEdit = new QLineEdit(TypeCurveBox);
        coeffEdit->setObjectName(QStringLiteral("coeffEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, coeffEdit);

        label = new QLabel(TypeCurveBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        pasEdit = new QLineEdit(TypeCurveBox);
        pasEdit->setObjectName(QStringLiteral("pasEdit"));
        pasEdit->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);

        formLayout->setWidget(1, QFormLayout::FieldRole, pasEdit);


        verticalLayout_6->addLayout(formLayout);


        verticalLayout_7->addLayout(verticalLayout_6);


        verticalLayout_4->addWidget(TypeCurveBox);

        groupBox = new QGroupBox(dockWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_12 = new QVBoxLayout(groupBox);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        radioRectangle = new QRadioButton(groupBox);
        radioRectangle->setObjectName(QStringLiteral("radioRectangle"));
        radioRectangle->setChecked(true);

        verticalLayout_12->addWidget(radioRectangle);

        radioTriangle = new QRadioButton(groupBox);
        radioTriangle->setObjectName(QStringLiteral("radioTriangle"));
        radioTriangle->setChecked(false);

        verticalLayout_12->addWidget(radioTriangle);


        verticalLayout_4->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        buttonQuit = new QPushButton(dockWidgetContents);
        buttonQuit->setObjectName(QStringLiteral("buttonQuit"));

        verticalLayout_4->addWidget(buttonQuit);


        verticalLayout_3->addLayout(verticalLayout_4);

        dockConfig->setWidget(dockWidgetContents);
        BezierQtClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockConfig);

        retranslateUi(BezierQtClass);

        QMetaObject::connectSlotsByName(BezierQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *BezierQtClass)
    {
        BezierQtClass->setWindowTitle(QApplication::translate("BezierQtClass", "BezierQt", 0));
        boxForm->setTitle(QApplication::translate("BezierQtClass", "Forme", 0));
        boxSoul->setTitle(QApplication::translate("BezierQtClass", "\303\202me", 0));
        boxSurface->setTitle(QApplication::translate("BezierQtClass", "Surface 3D", 0));
        dockConfig->setWindowTitle(QApplication::translate("BezierQtClass", "Configuration", 0));
        CreationBox->setTitle(QApplication::translate("BezierQtClass", "Cr\303\251ation", 0));
        buttonCreateForm->setText(QApplication::translate("BezierQtClass", "Cr\303\251er nouvelle forme", 0));
        checkClosedForm->setText(QApplication::translate("BezierQtClass", "Forme ferm\303\251e", 0));
        buttonCreateSoul->setText(QApplication::translate("BezierQtClass", "Cr\303\251er nouvelle \303\242me", 0));
        checkClosedSoul->setText(QApplication::translate("BezierQtClass", "\303\202me ferm\303\251e", 0));
        TypeExtrusionBox->setTitle(QApplication::translate("BezierQtClass", "Type de courbes", 0));
        radioCornerCutting->setText(QApplication::translate("BezierQtClass", "Corner Cutting", 0));
        radioCasteljau->setText(QApplication::translate("BezierQtClass", "De Casteljau", 0));
        TypeCurveBox->setTitle(QApplication::translate("BezierQtClass", "Type d'extrusion", 0));
        radioSimple->setText(QApplication::translate("BezierQtClass", "Simple", 0));
        radioRevolution->setText(QApplication::translate("BezierQtClass", "R\303\251volution", 0));
        radioGeneral->setText(QApplication::translate("BezierQtClass", "G\303\251n\303\251rale", 0));
        label_2->setText(QApplication::translate("BezierQtClass", "Agrandissement", 0));
        label->setText(QApplication::translate("BezierQtClass", "Pas d'extrusion", 0));
        groupBox->setTitle(QApplication::translate("BezierQtClass", "Facettisation", 0));
        radioRectangle->setText(QApplication::translate("BezierQtClass", "Rectangulaire", 0));
        radioTriangle->setText(QApplication::translate("BezierQtClass", "Triangulaire", 0));
        buttonQuit->setText(QApplication::translate("BezierQtClass", "Quitter", 0));
    } // retranslateUi

};

namespace Ui {
    class BezierQtClass: public Ui_BezierQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEZIERQT_H
