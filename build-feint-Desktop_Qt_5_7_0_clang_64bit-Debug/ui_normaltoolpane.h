/********************************************************************************
** Form generated from reading UI file 'normaltoolpane.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NORMALTOOLPANE_H
#define UI_NORMALTOOLPANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "widget/label/colorlabel.h"

QT_BEGIN_NAMESPACE

class Ui_NormalToolPane
{
public:
    QHBoxLayout *hboxLayout;
    QToolBox *toolBox;
    QWidget *colorPage;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame;
    QVBoxLayout *verticalLayout_;
    QPushButton *pushButton;
    QFrame *hightColor;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QGridLayout *gridLayout_2;
    QLabel *label_10;
    QLabel *label_13;
    ColorLabel *label_18;
    ColorLabel *label_16;
    ColorLabel *label_17;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_3;
    ColorLabel *label_15;
    ColorLabel *label_8;
    ColorLabel *label_6;
    QLabel *label_11;
    QLabel *label_9;
    QLabel *label_12;
    QLabel *label_14;
    ColorLabel *label_19;
    QLabel *label_2;
    QGridLayout *gridLayout_3;
    QLabel *label_7;
    QSpacerItem *verticalSpacer;
    QWidget *audioPage;
    QHBoxLayout *horizontalLayout_4;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame_2;
    QWidget *filePage;

    void setupUi(QWidget *NormalToolPane)
    {
        if (NormalToolPane->objectName().isEmpty())
            NormalToolPane->setObjectName(QStringLiteral("NormalToolPane"));
        NormalToolPane->resize(249, 556);
        NormalToolPane->setStyleSheet(QStringLiteral(""));
        hboxLayout = new QHBoxLayout(NormalToolPane);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        toolBox = new QToolBox(NormalToolPane);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setMaximumSize(QSize(16777215, 16777215));
        toolBox->setToolTipDuration(1);
        toolBox->setStyleSheet(QLatin1String("QToolBox::tab{\n"
"	border:1px solid #333;\n"
"	color:#ccc;\n"
"	font-size:12px;\n"
"	background:#262829;\n"
"\n"
"\n"
"}\n"
"QToolBoxButton{\n"
"	min-height:36px;\n"
"}\n"
"QToolBox::tab:selected{\n"
"	font-weight:bold;\n"
"	color:#fff;\n"
"}"));
        toolBox->setFrameShadow(QFrame::Plain);
        toolBox->setMidLineWidth(1);
        colorPage = new QWidget();
        colorPage->setObjectName(QStringLiteral("colorPage"));
        colorPage->setGeometry(QRect(0, 0, 249, 448));
        horizontalLayout_2 = new QHBoxLayout(colorPage);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(colorPage);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setFocusPolicy(Qt::ClickFocus);
        scrollArea->setStyleSheet(QLatin1String("QScrollArea{border:none;}\n"
""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 249, 448));
        scrollAreaWidgetContents->setStyleSheet(QStringLiteral("QWidget{border:none;}"));
        horizontalLayout_3 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(scrollAreaWidgetContents);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFocusPolicy(Qt::ClickFocus);
        frame->setStyleSheet(QLatin1String("QFrame{\n"
"	background:#404244;\n"
"	border:none;\n"
"}\n"
"QFrame:focus{\n"
"	border:2px solid #59a9fb;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_ = new QVBoxLayout(frame);
        verticalLayout_->setSpacing(6);
        verticalLayout_->setObjectName(QStringLiteral("verticalLayout_"));
        verticalLayout_->setContentsMargins(4, -1, 4, -1);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setStyleSheet(QStringLiteral("color:#3c7ec5;padding:0px 4px;"));

        verticalLayout_->addWidget(pushButton, 0, Qt::AlignLeft);

        hightColor = new QFrame(frame);
        hightColor->setObjectName(QStringLiteral("hightColor"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(hightColor->sizePolicy().hasHeightForWidth());
        hightColor->setSizePolicy(sizePolicy1);
        hightColor->setStyleSheet(QLatin1String("\n"
"QFrame{\n"
"	border-top:1px solid #2a69dd;\n"
"}\n"
"QLabel{\n"
"	color:#377be2;\n"
"	border:none;\n"
"}\n"
"ColorLabel{\n"
"	max-height:20px;\n"
"	border:1px solid #fff;\n"
"}"));
        hightColor->setFrameShape(QFrame::StyledPanel);
        hightColor->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(hightColor);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(hightColor);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(label);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(4);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_10 = new QLabel(hightColor);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 2, 0, 1, 1);

        label_13 = new QLabel(hightColor);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_2->addWidget(label_13, 4, 2, 1, 1);

        label_18 = new ColorLabel(hightColor);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_2->addWidget(label_18, 5, 2, 1, 1);

        label_16 = new ColorLabel(hightColor);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_2->addWidget(label_16, 3, 2, 1, 1);

        label_17 = new ColorLabel(hightColor);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_2->addWidget(label_17, 5, 1, 1, 1);

        label_5 = new QLabel(hightColor);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 0, 2, 1, 1);

        label_4 = new QLabel(hightColor);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 0, 1, 1, 1);

        label_3 = new QLabel(hightColor);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        label_15 = new ColorLabel(hightColor);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_2->addWidget(label_15, 3, 1, 1, 1);

        label_8 = new ColorLabel(hightColor);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 1, 2, 1, 1);

        label_6 = new ColorLabel(hightColor);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 1, 1, 1, 1);

        label_11 = new QLabel(hightColor);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 2, 2, 1, 1);

        label_9 = new QLabel(hightColor);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 2, 1, 1, 1);

        label_12 = new QLabel(hightColor);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_2->addWidget(label_12, 4, 1, 1, 1);

        label_14 = new QLabel(hightColor);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_2->addWidget(label_14, 6, 1, 1, 1);

        label_19 = new ColorLabel(hightColor);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_2->addWidget(label_19, 7, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        label_2 = new QLabel(hightColor);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(label_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_7 = new QLabel(hightColor);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout_->addWidget(hightColor);


        horizontalLayout_3->addWidget(frame);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        toolBox->addItem(colorPage, QString::fromUtf8("\351\242\234\350\211\262"));
        audioPage = new QWidget();
        audioPage->setObjectName(QStringLiteral("audioPage"));
        audioPage->setGeometry(QRect(0, 0, 249, 448));
        horizontalLayout_4 = new QHBoxLayout(audioPage);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        scrollArea_2 = new QScrollArea(audioPage);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setStyleSheet(QLatin1String("QScrollArea{border:none;}\n"
""));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 249, 448));
        scrollAreaWidgetContents_2->setStyleSheet(QStringLiteral(""));
        horizontalLayout_5 = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(scrollAreaWidgetContents_2);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setStyleSheet(QLatin1String("QFrame{\n"
"\n"
"	background:#404244;\n"
"	border:none;\n"
"}\n"
"QFrame:focus{\n"
"	border:2px solid #59a9fb;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        horizontalLayout_5->addWidget(frame_2);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_4->addWidget(scrollArea_2);

        toolBox->addItem(audioPage, QString::fromUtf8("\345\243\260\351\237\263"));
        filePage = new QWidget();
        filePage->setObjectName(QStringLiteral("filePage"));
        filePage->setGeometry(QRect(0, 0, 249, 448));
        toolBox->addItem(filePage, QString::fromUtf8("\346\226\207\344\273\266"));

        hboxLayout->addWidget(toolBox);


        retranslateUi(NormalToolPane);

        toolBox->setCurrentIndex(0);
        toolBox->layout()->setSpacing(0);


        QMetaObject::connectSlotsByName(NormalToolPane);
    } // setupUi

    void retranslateUi(QWidget *NormalToolPane)
    {
        NormalToolPane->setWindowTitle(QApplication::translate("NormalToolPane", "Form", 0));
        pushButton->setText(QApplication::translate("NormalToolPane", "\351\253\230\347\272\247", 0));
        label->setText(QApplication::translate("NormalToolPane", "\346\226\207\345\255\227", 0));
        label_10->setText(QApplication::translate("NormalToolPane", "\351\246\226\351\241\265\357\274\232", 0));
        label_13->setText(QApplication::translate("NormalToolPane", "\346\221\230\350\246\201", 0));
        label_18->setText(QString());
        label_16->setText(QString());
        label_17->setText(QString());
        label_5->setText(QApplication::translate("NormalToolPane", "\344\272\214\347\272\247\350\217\234\345\215\225", 0));
        label_4->setText(QApplication::translate("NormalToolPane", "\344\270\200\347\272\247\350\217\234\345\215\225", 0));
        label_3->setText(QApplication::translate("NormalToolPane", "\350\217\234\345\215\225\357\274\232", 0));
        label_15->setText(QString());
        label_8->setText(QString());
        label_6->setText(QString());
        label_11->setText(QApplication::translate("NormalToolPane", "\346\240\207\347\255\276", 0));
        label_9->setText(QApplication::translate("NormalToolPane", "\347\261\273\345\236\213", 0));
        label_12->setText(QApplication::translate("NormalToolPane", "\346\240\207\351\242\230", 0));
        label_14->setText(QApplication::translate("NormalToolPane", "\345\205\266\344\273\226", 0));
        label_19->setText(QString());
        label_2->setText(QApplication::translate("NormalToolPane", "\350\203\214\346\231\257", 0));
        label_7->setText(QApplication::translate("NormalToolPane", "TextLabel", 0));
        toolBox->setItemText(toolBox->indexOf(colorPage), QApplication::translate("NormalToolPane", "\351\242\234\350\211\262", 0));
        toolBox->setItemText(toolBox->indexOf(audioPage), QApplication::translate("NormalToolPane", "\345\243\260\351\237\263", 0));
        toolBox->setItemText(toolBox->indexOf(filePage), QApplication::translate("NormalToolPane", "\346\226\207\344\273\266", 0));
    } // retranslateUi

};

namespace Ui {
    class NormalToolPane: public Ui_NormalToolPane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NORMALTOOLPANE_H
