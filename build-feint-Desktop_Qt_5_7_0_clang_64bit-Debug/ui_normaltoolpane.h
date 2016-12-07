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
    QPushButton *pushDownBtn;
    QFrame *hightColor;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QGridLayout *gridLayout_2;
    ColorLabel *artiInfoText;
    QLabel *label_10;
    QLabel *label_13;
    QLabel *label_39;
    ColorLabel *tipText;
    QLabel *label_31;
    ColorLabel *comNameText;
    QLabel *label_33;
    ColorLabel *artiTextText;
    ColorLabel *tagText;
    ColorLabel *maintitleText;
    QLabel *label_34;
    QLabel *label_38;
    QLabel *label_32;
    ColorLabel *comTextText;
    QLabel *label_40;
    QLabel *label_41;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_3;
    ColorLabel *typeText;
    ColorLabel *secondmenuText;
    ColorLabel *firstmenuText;
    ColorLabel *otherText;
    QLabel *label_11;
    QLabel *label_9;
    QLabel *label_12;
    QLabel *label_14;
    ColorLabel *artiTitleText;
    ColorLabel *comInfoText;
    QLabel *label_2;
    QGridLayout *gridLayout_3;
    QLabel *label_7;
    ColorLabel *label_29;
    ColorLabel *label_28;
    QLabel *label_21;
    QLabel *label_25;
    QLabel *label_46;
    QLabel *label_47;
    QLabel *label_45;
    QLabel *label_24;
    QLabel *label_20;
    QLabel *label_22;
    ColorLabel *label_26;
    ColorLabel *label_27;
    QLabel *label_23;
    ColorLabel *label_30;
    ColorLabel *label_49;
    ColorLabel *label_48;
    QHBoxLayout *horizontalLayout;
    QPushButton *applyBtn;
    QPushButton *pushUpBtn;
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
        scrollAreaWidgetContents->setGeometry(QRect(0, -200, 234, 648));
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
        pushDownBtn = new QPushButton(frame);
        pushDownBtn->setObjectName(QStringLiteral("pushDownBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushDownBtn->sizePolicy().hasHeightForWidth());
        pushDownBtn->setSizePolicy(sizePolicy);
        pushDownBtn->setStyleSheet(QLatin1String("QPushButton{\n"
"color:#3c7ec5;\n"
"padding:0px 4px;\n"
"}\n"
"QPushButton:hover{\n"
"	border:1px solid #2a69dd;\n"
"}"));

        verticalLayout_->addWidget(pushDownBtn, 0, Qt::AlignLeft);

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
"	max-height:12px;\n"
"	border:1px solid #fff;\n"
"	border-radius:6px;\n"
"}"));
        hightColor->setFrameShape(QFrame::StyledPanel);
        hightColor->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(hightColor);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 12, 0, -1);
        label = new QLabel(hightColor);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QLatin1String("background:#262829;\n"
"padding:4px;\n"
"color:white;"));

        verticalLayout_2->addWidget(label);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(8);
        gridLayout_2->setVerticalSpacing(4);
        gridLayout_2->setContentsMargins(12, -1, 12, -1);
        artiInfoText = new ColorLabel(hightColor);
        artiInfoText->setObjectName(QStringLiteral("artiInfoText"));

        gridLayout_2->addWidget(artiInfoText, 9, 2, 1, 1);

        label_10 = new QLabel(hightColor);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 2, 0, 1, 1);

        label_13 = new QLabel(hightColor);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_2->addWidget(label_13, 4, 2, 1, 1);

        label_39 = new QLabel(hightColor);
        label_39->setObjectName(QStringLiteral("label_39"));

        gridLayout_2->addWidget(label_39, 12, 2, 1, 1);

        tipText = new ColorLabel(hightColor);
        tipText->setObjectName(QStringLiteral("tipText"));

        gridLayout_2->addWidget(tipText, 5, 2, 1, 1);

        label_31 = new QLabel(hightColor);
        label_31->setObjectName(QStringLiteral("label_31"));

        gridLayout_2->addWidget(label_31, 8, 0, 1, 1);

        comNameText = new ColorLabel(hightColor);
        comNameText->setObjectName(QStringLiteral("comNameText"));

        gridLayout_2->addWidget(comNameText, 13, 2, 1, 1);

        label_33 = new QLabel(hightColor);
        label_33->setObjectName(QStringLiteral("label_33"));

        gridLayout_2->addWidget(label_33, 8, 1, 1, 1);

        artiTextText = new ColorLabel(hightColor);
        artiTextText->setObjectName(QStringLiteral("artiTextText"));

        gridLayout_2->addWidget(artiTextText, 11, 1, 1, 1);

        tagText = new ColorLabel(hightColor);
        tagText->setObjectName(QStringLiteral("tagText"));

        gridLayout_2->addWidget(tagText, 3, 2, 1, 1);

        maintitleText = new ColorLabel(hightColor);
        maintitleText->setObjectName(QStringLiteral("maintitleText"));

        gridLayout_2->addWidget(maintitleText, 5, 1, 1, 1);

        label_34 = new QLabel(hightColor);
        label_34->setObjectName(QStringLiteral("label_34"));

        gridLayout_2->addWidget(label_34, 10, 1, 1, 1);

        label_38 = new QLabel(hightColor);
        label_38->setObjectName(QStringLiteral("label_38"));

        gridLayout_2->addWidget(label_38, 12, 1, 1, 1);

        label_32 = new QLabel(hightColor);
        label_32->setObjectName(QStringLiteral("label_32"));

        gridLayout_2->addWidget(label_32, 8, 2, 1, 1);

        comTextText = new ColorLabel(hightColor);
        comTextText->setObjectName(QStringLiteral("comTextText"));

        gridLayout_2->addWidget(comTextText, 13, 1, 1, 1);

        label_40 = new QLabel(hightColor);
        label_40->setObjectName(QStringLiteral("label_40"));

        gridLayout_2->addWidget(label_40, 14, 1, 1, 1);

        label_41 = new QLabel(hightColor);
        label_41->setObjectName(QStringLiteral("label_41"));

        gridLayout_2->addWidget(label_41, 12, 0, 1, 1);

        label_5 = new QLabel(hightColor);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 0, 2, 1, 1);

        label_4 = new QLabel(hightColor);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 0, 1, 1, 1);

        label_3 = new QLabel(hightColor);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        typeText = new ColorLabel(hightColor);
        typeText->setObjectName(QStringLiteral("typeText"));

        gridLayout_2->addWidget(typeText, 3, 1, 1, 1);

        secondmenuText = new ColorLabel(hightColor);
        secondmenuText->setObjectName(QStringLiteral("secondmenuText"));

        gridLayout_2->addWidget(secondmenuText, 1, 2, 1, 1);

        firstmenuText = new ColorLabel(hightColor);
        firstmenuText->setObjectName(QStringLiteral("firstmenuText"));

        gridLayout_2->addWidget(firstmenuText, 1, 1, 1, 1);

        otherText = new ColorLabel(hightColor);
        otherText->setObjectName(QStringLiteral("otherText"));

        gridLayout_2->addWidget(otherText, 7, 1, 1, 1);

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

        artiTitleText = new ColorLabel(hightColor);
        artiTitleText->setObjectName(QStringLiteral("artiTitleText"));

        gridLayout_2->addWidget(artiTitleText, 9, 1, 1, 1);

        comInfoText = new ColorLabel(hightColor);
        comInfoText->setObjectName(QStringLiteral("comInfoText"));

        gridLayout_2->addWidget(comInfoText, 15, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        label_2 = new QLabel(hightColor);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setStyleSheet(QLatin1String("background:#262829;\n"
"padding:4px;\n"
"color:#ccc;"));

        verticalLayout_2->addWidget(label_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(8);
        gridLayout_3->setVerticalSpacing(4);
        gridLayout_3->setContentsMargins(12, -1, 12, -1);
        label_7 = new QLabel(hightColor);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(label_7, 0, 0, 1, 1);

        label_29 = new ColorLabel(hightColor);
        label_29->setObjectName(QStringLiteral("label_29"));

        gridLayout_3->addWidget(label_29, 3, 2, 1, 1);

        label_28 = new ColorLabel(hightColor);
        label_28->setObjectName(QStringLiteral("label_28"));

        gridLayout_3->addWidget(label_28, 3, 1, 1, 1);

        label_21 = new QLabel(hightColor);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_3->addWidget(label_21, 0, 2, 1, 1);

        label_25 = new QLabel(hightColor);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_3->addWidget(label_25, 4, 1, 1, 1);

        label_46 = new QLabel(hightColor);
        label_46->setObjectName(QStringLiteral("label_46"));

        gridLayout_3->addWidget(label_46, 6, 1, 1, 1);

        label_47 = new QLabel(hightColor);
        label_47->setObjectName(QStringLiteral("label_47"));

        gridLayout_3->addWidget(label_47, 6, 2, 1, 1);

        label_45 = new QLabel(hightColor);
        label_45->setObjectName(QStringLiteral("label_45"));

        gridLayout_3->addWidget(label_45, 6, 0, 1, 1);

        label_24 = new QLabel(hightColor);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_3->addWidget(label_24, 2, 2, 1, 1);

        label_20 = new QLabel(hightColor);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_3->addWidget(label_20, 0, 1, 1, 1);

        label_22 = new QLabel(hightColor);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_3->addWidget(label_22, 2, 0, 1, 1);

        label_26 = new ColorLabel(hightColor);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_3->addWidget(label_26, 1, 1, 1, 1);

        label_27 = new ColorLabel(hightColor);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_3->addWidget(label_27, 1, 2, 1, 1);

        label_23 = new QLabel(hightColor);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_3->addWidget(label_23, 2, 1, 1, 1);

        label_30 = new ColorLabel(hightColor);
        label_30->setObjectName(QStringLiteral("label_30"));

        gridLayout_3->addWidget(label_30, 5, 1, 1, 1);

        label_49 = new ColorLabel(hightColor);
        label_49->setObjectName(QStringLiteral("label_49"));

        gridLayout_3->addWidget(label_49, 7, 2, 1, 1);

        label_48 = new ColorLabel(hightColor);
        label_48->setObjectName(QStringLiteral("label_48"));

        gridLayout_3->addWidget(label_48, 7, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 6, -1, -1);
        applyBtn = new QPushButton(hightColor);
        applyBtn->setObjectName(QStringLiteral("applyBtn"));
        applyBtn->setStyleSheet(QLatin1String("QPushButton{\n"
"	color:#2a69dd;\n"
"	padding:4px;\n"
"	border:1px solid #2a69dd;\n"
"	border-radius:4px;\n"
"}\n"
"QPushButton:hover{\n"
"	background:#262829;\n"
"	color:#ccc;\n"
"}"));

        horizontalLayout->addWidget(applyBtn);

        pushUpBtn = new QPushButton(hightColor);
        pushUpBtn->setObjectName(QStringLiteral("pushUpBtn"));
        pushUpBtn->setStyleSheet(QLatin1String("QPushButton{\n"
"	color:#2a69dd;\n"
"	padding:4px;\n"
"	border:1px solid #2a69dd;\n"
"	border-radius:4px;\n"
"}\n"
"QPushButton:hover{\n"
"	background:#262829;\n"
"	color:#ccc;\n"
"}"));

        horizontalLayout->addWidget(pushUpBtn);


        verticalLayout_2->addLayout(horizontalLayout);

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
        pushDownBtn->setText(QApplication::translate("NormalToolPane", "\351\253\230\347\272\247", 0));
        label->setText(QApplication::translate("NormalToolPane", "\346\226\207\345\255\227", 0));
        artiInfoText->setText(QString());
        label_10->setText(QApplication::translate("NormalToolPane", "\351\246\226\351\241\265\357\274\232", 0));
        label_13->setText(QApplication::translate("NormalToolPane", "\346\221\230\350\246\201", 0));
        label_39->setText(QApplication::translate("NormalToolPane", "\350\257\204\350\256\272\350\200\205", 0));
        tipText->setText(QString());
        label_31->setText(QApplication::translate("NormalToolPane", "\346\226\207\347\253\240\357\274\232", 0));
        comNameText->setText(QString());
        label_33->setText(QApplication::translate("NormalToolPane", "\346\240\207\351\242\230", 0));
        artiTextText->setText(QString());
        tagText->setText(QString());
        maintitleText->setText(QString());
        label_34->setText(QApplication::translate("NormalToolPane", "\346\255\243\346\226\207", 0));
        label_38->setText(QApplication::translate("NormalToolPane", "\346\266\210\346\201\257", 0));
        label_32->setText(QApplication::translate("NormalToolPane", "\344\277\241\346\201\257", 0));
        comTextText->setText(QString());
        label_40->setText(QApplication::translate("NormalToolPane", "\345\205\266\344\273\226", 0));
        label_41->setText(QApplication::translate("NormalToolPane", "\350\257\204\350\256\272\357\274\232", 0));
        label_5->setText(QApplication::translate("NormalToolPane", "\344\272\214\347\272\247\350\217\234\345\215\225", 0));
        label_4->setText(QApplication::translate("NormalToolPane", "\344\270\200\347\272\247\350\217\234\345\215\225", 0));
        label_3->setText(QApplication::translate("NormalToolPane", "\350\217\234\345\215\225\357\274\232", 0));
        typeText->setText(QString());
        secondmenuText->setText(QString());
        firstmenuText->setText(QString());
        otherText->setText(QString());
        label_11->setText(QApplication::translate("NormalToolPane", "\346\240\207\347\255\276", 0));
        label_9->setText(QApplication::translate("NormalToolPane", "\347\261\273\345\236\213", 0));
        label_12->setText(QApplication::translate("NormalToolPane", "\346\240\207\351\242\230", 0));
        label_14->setText(QApplication::translate("NormalToolPane", "\345\205\266\344\273\226", 0));
        artiTitleText->setText(QString());
        comInfoText->setText(QString());
        label_2->setText(QApplication::translate("NormalToolPane", "\350\203\214\346\231\257", 0));
        label_7->setText(QApplication::translate("NormalToolPane", "\350\217\234\345\215\225\357\274\232", 0));
        label_29->setText(QString());
        label_28->setText(QString());
        label_21->setText(QApplication::translate("NormalToolPane", "\344\272\214\347\272\247\350\217\234\345\215\225", 0));
        label_25->setText(QApplication::translate("NormalToolPane", "\344\270\273\350\203\214\346\231\257", 0));
        label_46->setText(QApplication::translate("NormalToolPane", "\346\226\207\347\253\240", 0));
        label_47->setText(QApplication::translate("NormalToolPane", "\350\257\204\350\256\272", 0));
        label_45->setText(QApplication::translate("NormalToolPane", "\345\206\205\346\266\265\357\274\232", 0));
        label_24->setText(QApplication::translate("NormalToolPane", "\345\215\241\347\211\207", 0));
        label_20->setText(QApplication::translate("NormalToolPane", "\344\270\200\347\272\247\350\217\234\345\215\225", 0));
        label_22->setText(QApplication::translate("NormalToolPane", "\351\246\226\351\241\265\357\274\232", 0));
        label_26->setText(QString());
        label_27->setText(QString());
        label_23->setText(QApplication::translate("NormalToolPane", "\351\200\211\351\241\271\345\215\241", 0));
        label_30->setText(QString());
        label_49->setText(QString());
        label_48->setText(QString());
        applyBtn->setText(QApplication::translate("NormalToolPane", "\345\272\224\347\224\250", 0));
        pushUpBtn->setText(QApplication::translate("NormalToolPane", "\346\224\266\350\265\267", 0));
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
