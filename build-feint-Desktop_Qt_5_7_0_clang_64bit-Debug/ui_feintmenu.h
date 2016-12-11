/********************************************************************************
** Form generated from reading UI file 'feintmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEINTMENU_H
#define UI_FEINTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FeintMenu
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *basic;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *nameLab;
    QLabel *introLab;
    QLabel *portrait;

    void setupUi(QWidget *FeintMenu)
    {
        if (FeintMenu->objectName().isEmpty())
            FeintMenu->setObjectName(QStringLiteral("FeintMenu"));
        FeintMenu->resize(250, 479);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FeintMenu->sizePolicy().hasHeightForWidth());
        FeintMenu->setSizePolicy(sizePolicy);
        FeintMenu->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(FeintMenu);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        basic = new QFrame(FeintMenu);
        basic->setObjectName(QStringLiteral("basic"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(basic->sizePolicy().hasHeightForWidth());
        basic->setSizePolicy(sizePolicy1);
        basic->setMinimumSize(QSize(250, 0));
        basic->setFrameShape(QFrame::StyledPanel);
        basic->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(basic);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(basic);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setMinimumSize(QSize(250, 145));
        frame->setStyleSheet(QLatin1String("QFrame{\n"
"	border:none;\n"
"	background:url(:/header.png);\n"
"}\n"
"#portrait{\n"
"border:1px solid #fff;\n"
"min-width:50px;\n"
"min-height:50px;\n"
"max-width:50px;\n"
"max-height:50px;\n"
"border-radius:25px;\n"
"}\n"
"\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(12);
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(12, 24, -1, 0);
        nameLab = new QLabel(frame);
        nameLab->setObjectName(QStringLiteral("nameLab"));
        nameLab->setStyleSheet(QStringLiteral("font-size:20pt;color:white;background:rgb();"));

        gridLayout->addWidget(nameLab, 0, 1, 1, 1);

        introLab = new QLabel(frame);
        introLab->setObjectName(QStringLiteral("introLab"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(introLab->sizePolicy().hasHeightForWidth());
        introLab->setSizePolicy(sizePolicy3);
        introLab->setStyleSheet(QStringLiteral("color:white;background:rgb();font-size:12pt;"));
        introLab->setIndent(8);

        gridLayout->addWidget(introLab, 1, 0, 1, 2);

        portrait = new QLabel(frame);
        portrait->setObjectName(QStringLiteral("portrait"));
        portrait->setStyleSheet(QStringLiteral("background-image:url(:/sound.png);"));
        portrait->setFrameShadow(QFrame::Plain);
        portrait->setScaledContents(true);

        gridLayout->addWidget(portrait, 0, 0, 1, 1);


        verticalLayout_2->addWidget(frame);


        verticalLayout->addWidget(basic);


        retranslateUi(FeintMenu);

        QMetaObject::connectSlotsByName(FeintMenu);
    } // setupUi

    void retranslateUi(QWidget *FeintMenu)
    {
        FeintMenu->setWindowTitle(QApplication::translate("FeintMenu", "Form", 0));
        nameLab->setText(QApplication::translate("FeintMenu", "None", 0));
        introLab->setText(QApplication::translate("FeintMenu", "None", 0));
        portrait->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FeintMenu: public Ui_FeintMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEINTMENU_H
