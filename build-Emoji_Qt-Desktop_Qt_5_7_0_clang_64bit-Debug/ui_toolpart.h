/********************************************************************************
** Form generated from reading UI file 'toolpart.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLPART_H
#define UI_TOOLPART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <view/colorlabel.h>

QT_BEGIN_NAMESPACE

class Ui_ToolPart
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QLabel *bluePerLab;
    QSlider *greenSlider;
    QSlider *redSlider;
    QLabel *greenLab;
    QLabel *blueLab;
    QLabel *redLab;
    QSlider *blueSlider;
    QLabel *greenPerLab;
    QLabel *redPerLab;
    QLabel *imgLab;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *turnGray;
    QPushButton *zoomOut;
    QLabel *zoomLab;
    QPushButton *zoomIn;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *compress;
    QDoubleSpinBox *compressSpin;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *fontLab;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QComboBox *verComb;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QComboBox *horiComb;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_16;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_3;
    ColorLabel *colorLab;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_4;
    QToolButton *toolButton;
    QToolButton *toolButton_3;
    QToolButton *toolButton_2;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_17;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QFontComboBox *fontComboBox;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_18;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QSpinBox *sizeSpin;
    QCheckBox *autoMoveComb;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_19;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_6;
    QComboBox *hotComb;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *hotEdit;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *ToolPart)
    {
        if (ToolPart->objectName().isEmpty())
            ToolPart->setObjectName(QStringLiteral("ToolPart"));
        ToolPart->resize(316, 647);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ToolPart->sizePolicy().hasHeightForWidth());
        ToolPart->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(170, 170, 170, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(238, 238, 238, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
        ToolPart->setPalette(palette);
        ToolPart->setStyleSheet(QLatin1String("#ToolPart{\n"
"background:#eee;\n"
"border-left:1px solid #ccc;\n"
"color:#aaa;\n"
"}"));
        verticalLayout = new QVBoxLayout(ToolPart);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        scrollArea = new QScrollArea(ToolPart);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setStyleSheet(QLatin1String("QScrollArea{\n"
"	border:none;\n"
"}"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 308, 639));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 12, 0, 0);
        frame = new QFrame(scrollAreaWidgetContents);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(0, 0));
        frame->setStyleSheet(QStringLiteral("#frame{border:none;background:#f9f9f9;}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(6, 6, 6, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(2);
        gridLayout_2->setVerticalSpacing(16);
        gridLayout_2->setContentsMargins(-1, -1, -1, 12);
        bluePerLab = new QLabel(frame);
        bluePerLab->setObjectName(QStringLiteral("bluePerLab"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(bluePerLab->sizePolicy().hasHeightForWidth());
        bluePerLab->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(bluePerLab, 4, 2, 1, 1);

        greenSlider = new QSlider(frame);
        greenSlider->setObjectName(QStringLiteral("greenSlider"));
        greenSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(greenSlider, 3, 1, 1, 1);

        redSlider = new QSlider(frame);
        redSlider->setObjectName(QStringLiteral("redSlider"));
        redSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(redSlider, 2, 1, 1, 1);

        greenLab = new QLabel(frame);
        greenLab->setObjectName(QStringLiteral("greenLab"));
        sizePolicy2.setHeightForWidth(greenLab->sizePolicy().hasHeightForWidth());
        greenLab->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(greenLab, 3, 0, 1, 1);

        blueLab = new QLabel(frame);
        blueLab->setObjectName(QStringLiteral("blueLab"));
        sizePolicy2.setHeightForWidth(blueLab->sizePolicy().hasHeightForWidth());
        blueLab->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(blueLab, 4, 0, 1, 1);

        redLab = new QLabel(frame);
        redLab->setObjectName(QStringLiteral("redLab"));
        sizePolicy2.setHeightForWidth(redLab->sizePolicy().hasHeightForWidth());
        redLab->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(redLab, 2, 0, 1, 1);

        blueSlider = new QSlider(frame);
        blueSlider->setObjectName(QStringLiteral("blueSlider"));
        blueSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(blueSlider, 4, 1, 1, 1);

        greenPerLab = new QLabel(frame);
        greenPerLab->setObjectName(QStringLiteral("greenPerLab"));

        gridLayout_2->addWidget(greenPerLab, 3, 2, 1, 1);

        redPerLab = new QLabel(frame);
        redPerLab->setObjectName(QStringLiteral("redPerLab"));
        redPerLab->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(redPerLab, 2, 2, 1, 1);

        imgLab = new QLabel(frame);
        imgLab->setObjectName(QStringLiteral("imgLab"));
        sizePolicy.setHeightForWidth(imgLab->sizePolicy().hasHeightForWidth());
        imgLab->setSizePolicy(sizePolicy);
        QPalette palette1;
        QBrush brush3(QColor(76, 76, 76, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        QBrush brush4(QColor(255, 255, 255, 127));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        imgLab->setPalette(palette1);
        imgLab->setStyleSheet(QLatin1String("#imgLab{\n"
"border:1px solid #ccc;\n"
"border-top:none;\n"
"border-left:none;\n"
"border-right:none;\n"
"padding:6px 4px;\n"
"}\n"
""));

        gridLayout_2->addWidget(imgLab, 0, 0, 1, 3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        turnGray = new QCheckBox(frame);
        turnGray->setObjectName(QStringLiteral("turnGray"));

        horizontalLayout_3->addWidget(turnGray);

        zoomOut = new QPushButton(frame);
        zoomOut->setObjectName(QStringLiteral("zoomOut"));
        zoomOut->setFocusPolicy(Qt::ClickFocus);
        zoomOut->setStyleSheet(QLatin1String("#zoomOut{\n"
"border-radius:10px;\n"
"width:20px;\n"
"height:20px;\n"
"background-color:white;\n"
"}\n"
"#zoomOut:hover{\n"
"background-color:#4a90e2;\n"
"color:white;\n"
"}\n"
"#zoomOut:pressed{\n"
"background-color:#3980d1;\n"
"color:white;\n"
"}"));

        horizontalLayout_3->addWidget(zoomOut);

        zoomLab = new QLabel(frame);
        zoomLab->setObjectName(QStringLiteral("zoomLab"));

        horizontalLayout_3->addWidget(zoomLab);

        zoomIn = new QPushButton(frame);
        zoomIn->setObjectName(QStringLiteral("zoomIn"));
        zoomIn->setFocusPolicy(Qt::ClickFocus);
        zoomIn->setStyleSheet(QLatin1String("#zoomIn{\n"
"\n"
"border-radius:12px;\n"
"width:24px;\n"
"height:24px;\n"
"background-color:white;\n"
"}\n"
"#zoomIn:hover{\n"
"background-color:#d0021b;\n"
"color:white\n"
"}\n"
"#zoomIn:select{\n"
"background-color:yellow;\n"
"}"));

        horizontalLayout_3->addWidget(zoomIn);

        horizontalLayout_3->setStretch(0, 1);

        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        compress = new QCheckBox(frame);
        compress->setObjectName(QStringLiteral("compress"));

        horizontalLayout_4->addWidget(compress);

        compressSpin = new QDoubleSpinBox(frame);
        compressSpin->setObjectName(QStringLiteral("compressSpin"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(compressSpin->sizePolicy().hasHeightForWidth());
        compressSpin->setSizePolicy(sizePolicy3);
        compressSpin->setMinimumSize(QSize(80, 0));
        compressSpin->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_4->addWidget(compressSpin);


        gridLayout_2->addLayout(horizontalLayout_4, 5, 0, 1, 3);


        horizontalLayout->addLayout(gridLayout_2);


        verticalLayout_2->addWidget(frame);

        frame_2 = new QFrame(scrollAreaWidgetContents);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setStyleSheet(QLatin1String("#frame_2{border:none;background:#555;}\n"
"QFrame{background:#666; color:#fff;border-radius:5px;}\n"
"QComboBox{\n"
"min-height:24px;\n"
"background:#444;\n"
"border:1px solid #1e90ff;\n"
"border-radius:5px;\n"
"\n"
"}\n"
"QComboBox::drop-down{\n"
"	background:#1e90ff;\n"
"	border-radius:3px;\n"
"	min-height:24px;\n"
"	margin:0px;\n"
"}\n"
"QComboBox::down-arrow{\n"
"	width: 0px;  \n"
"    height: 0px;  \n"
"    border-top: 8px solid #ccc;  \n"
"    border-right:5px solid #1e90ff;\n"
"	border-left:5px solid #1e90ff;\n"
"\n"
"}\n"
""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(6, 6, 6, 0);
        fontLab = new QLabel(frame_2);
        fontLab->setObjectName(QStringLiteral("fontLab"));
        sizePolicy.setHeightForWidth(fontLab->sizePolicy().hasHeightForWidth());
        fontLab->setSizePolicy(sizePolicy);
        fontLab->setStyleSheet(QLatin1String("#fontLab{\n"
"border:4px solid #ccc;\n"
"border-top:none;\n"
"border-left:none;\n"
"border-right:none;\n"
"padding:12px 4px;\n"
"background:#3a3a3a;\n"
"border-radius:5px;\n"
"color:#ccc;\n"
"}\n"
""));

        verticalLayout_3->addWidget(fontLab);

        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setStyleSheet(QStringLiteral(""));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_15 = new QHBoxLayout(frame_3);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(4, 6, 4, 6);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(16);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, -1, -1, -1);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(label_2);

        verComb = new QComboBox(frame_3);
        verComb->setObjectName(QStringLiteral("verComb"));
        sizePolicy1.setHeightForWidth(verComb->sizePolicy().hasHeightForWidth());
        verComb->setSizePolicy(sizePolicy1);
        verComb->setMaximumSize(QSize(1800, 16777215));

        horizontalLayout_7->addWidget(verComb);


        horizontalLayout_12->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label = new QLabel(frame_3);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(label);

        horiComb = new QComboBox(frame_3);
        horiComb->setObjectName(QStringLiteral("horiComb"));
        horiComb->setMaximumSize(QSize(1800, 16777215));

        horizontalLayout_6->addWidget(horiComb);


        horizontalLayout_12->addLayout(horizontalLayout_6);


        horizontalLayout_15->addLayout(horizontalLayout_12);


        verticalLayout_3->addWidget(frame_3);

        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setStyleSheet(QStringLiteral(""));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_16 = new QHBoxLayout(frame_4);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(4, 6, 4, 6);
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(-1, -1, 0, -1);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(1);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_3 = new QLabel(frame_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(label_3);

        colorLab = new ColorLabel(frame_4);
        colorLab->setObjectName(QStringLiteral("colorLab"));
        sizePolicy2.setHeightForWidth(colorLab->sizePolicy().hasHeightForWidth());
        colorLab->setSizePolicy(sizePolicy2);
        QPalette palette2;
        QBrush brush5(QColor(255, 255, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        QBrush brush6(QColor(102, 102, 102, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        colorLab->setPalette(palette2);
        colorLab->setStyleSheet(QLatin1String("#colorLab{\n"
"min-width:24px;\n"
"	min-height:24px;\n"
"	border:1px solid #ccc;\n"
"	border-radius:5px;\n"
"}"));

        horizontalLayout_9->addWidget(colorLab);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 1);

        horizontalLayout_14->addLayout(horizontalLayout_9);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(4);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_4 = new QLabel(frame_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);

        horizontalLayout_10->addWidget(label_4);

        toolButton = new QToolButton(frame_4);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setStyleSheet(QLatin1String("QToolButton{\n"
"	min-width:24px;\n"
"	min-height:24px;\n"
"	max-width:24px;\n"
"	max-height:24px;\n"
"	border:1px solid #ccc;\n"
"	color:#ccc;\n"
"	border-radius:5px;\n"
"}\n"
"QToolButton:checked{\n"
"	background:#aaa;\n"
"	color:white;\n"
"}"));
        toolButton->setCheckable(true);

        horizontalLayout_10->addWidget(toolButton);

        toolButton_3 = new QToolButton(frame_4);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setStyleSheet(QLatin1String("QToolButton{\n"
"	min-width:24px;\n"
"	min-height:24px;\n"
"	max-width:24px;\n"
"	max-height:24px;\n"
"	border:1px solid #ccc;\n"
"	color:#ccc;\n"
"	border-radius:5px;\n"
"}\n"
"QToolButton:checked{\n"
"	background:#aaa;\n"
"	color:white;\n"
"}"));
        toolButton_3->setCheckable(true);

        horizontalLayout_10->addWidget(toolButton_3);

        toolButton_2 = new QToolButton(frame_4);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setStyleSheet(QLatin1String("QToolButton{\n"
"	min-width:24px;\n"
"	min-height:24px;\n"
"	max-width:24px;\n"
"	max-height:24px;\n"
"	border:1px solid #ccc;\n"
"	color:#ccc;\n"
"	border-radius:5px;\n"
"}\n"
"QToolButton:checked{\n"
"	background:#aaa;\n"
"	color:white;\n"
"}"));
        toolButton_2->setCheckable(true);

        horizontalLayout_10->addWidget(toolButton_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);


        horizontalLayout_14->addLayout(horizontalLayout_10);


        horizontalLayout_16->addLayout(horizontalLayout_14);


        verticalLayout_3->addWidget(frame_4);

        frame_5 = new QFrame(frame_2);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setStyleSheet(QStringLiteral(""));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_17 = new QHBoxLayout(frame_5);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(4, 6, 4, 6);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_8 = new QLabel(frame_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(label_8);

        fontComboBox = new QFontComboBox(frame_5);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        sizePolicy1.setHeightForWidth(fontComboBox->sizePolicy().hasHeightForWidth());
        fontComboBox->setSizePolicy(sizePolicy1);
        fontComboBox->setMinimumSize(QSize(240, 26));
        fontComboBox->setMaximumSize(QSize(2400, 16777215));
        fontComboBox->setFocusPolicy(Qt::ClickFocus);
        fontComboBox->setStyleSheet(QLatin1String("QFontComboBox{\n"
"	border-radius:0px;\n"
"}\n"
"QFontComboBox::drop-down{\n"
"	border-radius:0px;\n"
"}"));

        horizontalLayout_2->addWidget(fontComboBox);


        horizontalLayout_17->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(frame_5);

        frame_6 = new QFrame(frame_2);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setStyleSheet(QStringLiteral(""));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_18 = new QHBoxLayout(frame_6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(4, 6, 4, 6);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(1);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetFixedSize);
        label_7 = new QLabel(frame_6);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(label_7);

        sizeSpin = new QSpinBox(frame_6);
        sizeSpin->setObjectName(QStringLiteral("sizeSpin"));
        sizePolicy3.setHeightForWidth(sizeSpin->sizePolicy().hasHeightForWidth());
        sizeSpin->setSizePolicy(sizePolicy3);
        sizeSpin->setMinimumSize(QSize(80, 0));
        sizeSpin->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_5->addWidget(sizeSpin);

        autoMoveComb = new QCheckBox(frame_6);
        autoMoveComb->setObjectName(QStringLiteral("autoMoveComb"));
        autoMoveComb->setStyleSheet(QStringLiteral("margin-left:16px"));

        horizontalLayout_5->addWidget(autoMoveComb);


        horizontalLayout_18->addLayout(horizontalLayout_5);


        verticalLayout_3->addWidget(frame_6);

        frame_7 = new QFrame(frame_2);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_19 = new QHBoxLayout(frame_7);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(4, 6, 4, 6);
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(2);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_6 = new QLabel(frame_7);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        horizontalLayout_13->addWidget(label_6, 0, Qt::AlignLeft);

        hotComb = new QComboBox(frame_7);
        hotComb->setObjectName(QStringLiteral("hotComb"));
        sizePolicy1.setHeightForWidth(hotComb->sizePolicy().hasHeightForWidth());
        hotComb->setSizePolicy(sizePolicy1);
        hotComb->setMinimumSize(QSize(0, 26));
        hotComb->setFrame(true);

        horizontalLayout_13->addWidget(hotComb);


        horizontalLayout_19->addLayout(horizontalLayout_13);


        verticalLayout_3->addWidget(frame_7);

        frame_8 = new QFrame(frame_2);
        frame_8->setObjectName(QStringLiteral("frame_8"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        horizontalLayout_8 = new QHBoxLayout(frame_8);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(4, 6, 4, 6);
        hotEdit = new QLineEdit(frame_8);
        hotEdit->setObjectName(QStringLiteral("hotEdit"));
        hotEdit->setFocusPolicy(Qt::ClickFocus);
        hotEdit->setStyleSheet(QLatin1String("#hotEdit{\n"
"	border:1px solid #ccc;\n"
"	min-height:24px;\n"
"	border-radius:5px;\n"
"}\n"
"#hotEdit:focus{\n"
"	border:1px solid #00bfff;\n"
"}"));

        horizontalLayout_8->addWidget(hotEdit);


        verticalLayout_3->addWidget(frame_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_2->addWidget(frame_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(ToolPart);

        QMetaObject::connectSlotsByName(ToolPart);
    } // setupUi

    void retranslateUi(QDialog *ToolPart)
    {
        ToolPart->setWindowTitle(QApplication::translate("ToolPart", "Dialog", 0));
        bluePerLab->setText(QApplication::translate("ToolPart", "50%", 0));
        greenLab->setText(QApplication::translate("ToolPart", "\347\273\277\350\211\262\357\274\232", 0));
        blueLab->setText(QApplication::translate("ToolPart", "\350\223\235\350\211\262\357\274\232", 0));
        redLab->setText(QApplication::translate("ToolPart", "\347\272\242\350\211\262\357\274\232", 0));
        greenPerLab->setText(QApplication::translate("ToolPart", "50%", 0));
        redPerLab->setText(QApplication::translate("ToolPart", "50%", 0));
        imgLab->setText(QApplication::translate("ToolPart", "\345\233\276\347\211\207", 0));
        turnGray->setText(QApplication::translate("ToolPart", "\350\275\254\347\201\260\345\272\246\345\233\276", 0));
        zoomOut->setText(QApplication::translate("ToolPart", "\357\274\215", 0));
        zoomLab->setText(QApplication::translate("ToolPart", "100%", 0));
        zoomIn->setText(QApplication::translate("ToolPart", "\357\274\213", 0));
        compress->setText(QApplication::translate("ToolPart", "\345\216\213\347\274\251\345\233\276\347\211\207", 0));
        fontLab->setText(QApplication::translate("ToolPart", "\346\226\207\345\255\227", 0));
        label_2->setText(QApplication::translate("ToolPart", "\345\236\202\347\233\264\357\274\232", 0));
        label->setText(QApplication::translate("ToolPart", "\346\260\264\345\271\263\357\274\232", 0));
        label_3->setText(QApplication::translate("ToolPart", "\351\242\234\350\211\262\357\274\232", 0));
        colorLab->setText(QString());
        label_4->setText(QApplication::translate("ToolPart", "\346\240\267\345\274\217\357\274\232", 0));
        toolButton->setText(QApplication::translate("ToolPart", "B", 0));
        toolButton_3->setText(QApplication::translate("ToolPart", "/", 0));
        toolButton_2->setText(QApplication::translate("ToolPart", "__", 0));
        label_8->setText(QApplication::translate("ToolPart", "\345\255\227\344\275\223\357\274\232", 0));
        label_7->setText(QApplication::translate("ToolPart", "\345\244\247\345\260\217\357\274\232", 0));
        autoMoveComb->setText(QApplication::translate("ToolPart", "\350\207\252\347\224\261\347\247\273\345\212\250", 0));
        label_6->setText(QApplication::translate("ToolPart", "\347\203\255\351\227\250\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class ToolPart: public Ui_ToolPart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLPART_H
