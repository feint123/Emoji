/********************************************************************************
** Form generated from reading UI file 'showpane.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWPANE_H
#define UI_SHOWPANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "widget/label/colorlabel.h"

QT_BEGIN_NAMESPACE

class Ui_ShowPane
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    ColorLabel *label;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    ColorLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    ColorLabel *label_6;
    ColorLabel *label_5;
    ColorLabel *label_4;
    ColorLabel *label_7;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    ColorLabel *label_10;
    ColorLabel *label_9;
    ColorLabel *label_8;
    QSpacerItem *horizontalSpacer;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *gridLayout;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *label_11;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ShowPane)
    {
        if (ShowPane->objectName().isEmpty())
            ShowPane->setObjectName(QStringLiteral("ShowPane"));
        ShowPane->resize(670, 424);
        ShowPane->setStyleSheet(QLatin1String("ColorLabel{\n"
"	min-height:32px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(ShowPane);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new ColorLabel(ShowPane);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QLatin1String("background:#262829;\n"
"color:white;\n"
"text-align:center;\n"
"padding:8px;"));

        verticalLayout->addWidget(label);

        frame = new QFrame(ShowPane);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QStringLiteral("background:#4a4a4a;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(label_3, 0, Qt::AlignTop);


        verticalLayout->addWidget(frame);

        label_2 = new ColorLabel(ShowPane);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setStyleSheet(QLatin1String("background:#262829;\n"
"color:white;\n"
"text-align:center;\n"
"padding:8px;"));

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new ColorLabel(ShowPane);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setStyleSheet(QLatin1String("background:#d21011;\n"
"color:white;\n"
"text-align:center;\n"
"padding:4px;"));

        horizontalLayout_2->addWidget(label_6, 0, Qt::AlignTop);

        label_5 = new ColorLabel(ShowPane);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QLatin1String("background:white;\n"
"color:#333;\n"
"text-align:center;\n"
"padding:4px;"));

        horizontalLayout_2->addWidget(label_5, 0, Qt::AlignTop);

        label_4 = new ColorLabel(ShowPane);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QLatin1String("background:#d21011;\n"
"color:white;\n"
"text-align:center;\n"
"padding:4px;"));

        horizontalLayout_2->addWidget(label_4, 0, Qt::AlignTop);

        label_7 = new ColorLabel(ShowPane);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QLatin1String("background:#d21011;\n"
"color:white;\n"
"text-align:center;\n"
"padding:4px;"));

        horizontalLayout_2->addWidget(label_7, 0, Qt::AlignTop);


        verticalLayout_2->addLayout(horizontalLayout_2);

        frame_2 = new QFrame(ShowPane);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setStyleSheet(QStringLiteral("background:white;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(8);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 12);
        label_10 = new ColorLabel(frame_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setStyleSheet(QLatin1String("border-radius:8px;\n"
"background:#edd663;\n"
"color:white;\n"
"padding:2px;"));

        horizontalLayout_3->addWidget(label_10, 0, Qt::AlignHCenter|Qt::AlignTop);

        label_9 = new ColorLabel(frame_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QLatin1String("border-radius:8px;\n"
"background:#edd663;\n"
"color:white;\n"
"padding:2px;"));

        horizontalLayout_3->addWidget(label_9, 0, Qt::AlignHCenter|Qt::AlignTop);

        label_8 = new ColorLabel(frame_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QLatin1String("border-radius:8px;\n"
"background:#edd663;\n"
"color:white;\n"
"padding:2px;"));

        horizontalLayout_3->addWidget(label_8, 0, Qt::AlignHCenter|Qt::AlignTop);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout_3);

        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setMaximumSize(QSize(16777215, 200));
        frame_3->setStyleSheet(QStringLiteral("background:#1b7cff;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_13 = new QLabel(frame_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 3, 0, 1, 1);

        label_12 = new QLabel(frame_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_12, 1, 0, 1, 1);

        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_11, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 1);


        horizontalLayout_4->addLayout(gridLayout);


        verticalLayout_4->addWidget(frame_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        verticalLayout_4->setStretch(1, 1);

        verticalLayout_2->addWidget(frame_2);

        verticalLayout_2->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);

        retranslateUi(ShowPane);

        QMetaObject::connectSlotsByName(ShowPane);
    } // setupUi

    void retranslateUi(QWidget *ShowPane)
    {
        ShowPane->setWindowTitle(QApplication::translate("ShowPane", "Form", 0));
        label->setText(QApplication::translate("ShowPane", "\344\270\200\347\272\247\350\217\234\345\215\225", 0));
        label_3->setText(QApplication::translate("ShowPane", "\344\272\214\347\272\247\350\217\234\345\215\225", 0));
        label_2->setText(QApplication::translate("ShowPane", "\344\270\200\347\272\247\350\217\234\345\215\225", 0));
        label_6->setText(QApplication::translate("ShowPane", "Tab1", 0));
        label_5->setText(QApplication::translate("ShowPane", "Tab2", 0));
        label_4->setText(QApplication::translate("ShowPane", "Tab3", 0));
        label_7->setText(QApplication::translate("ShowPane", "Tab4", 0));
        label_10->setText(QApplication::translate("ShowPane", "Tag1", 0));
        label_9->setText(QApplication::translate("ShowPane", "TextLabel", 0));
        label_8->setText(QApplication::translate("ShowPane", "TextLabel", 0));
        label_13->setText(QApplication::translate("ShowPane", "1900-01-01", 0));
        label_12->setText(QApplication::translate("ShowPane", "\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\n"
"\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\n"
"\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\n"
"\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\350\277\231\346\230\257\346\221\230\350\246\201\357"
                        "\274\214\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\n"
"\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214\350\277\231\346\230\257\346\221\230\350\246\201\357\274\214", 0));
        label_11->setText(QApplication::translate("ShowPane", "\350\277\231\346\230\257\346\240\207\351\242\230", 0));
    } // retranslateUi

};

namespace Ui {
    class ShowPane: public Ui_ShowPane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWPANE_H
