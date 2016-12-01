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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ToolPart
{
public:
    QVBoxLayout *verticalLayout;
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
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_3;
    QComboBox *placeComb;
    QLabel *label_8;
    QFontComboBox *fontComboBox;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_7;
    QComboBox *hotComb;
    QLabel *fontLab;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *sizeSpin;
    QCheckBox *autoMoveComb;

    void setupUi(QDialog *ToolPart)
    {
        if (ToolPart->objectName().isEmpty())
            ToolPart->setObjectName(QStringLiteral("ToolPart"));
        ToolPart->resize(241, 569);
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
        verticalLayout->setContentsMargins(4, 6, 0, -1);
        frame = new QFrame(ToolPart);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(237, 0));
        frame->setStyleSheet(QStringLiteral("#frame{border:none;background:#f9f9f9;}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(6, 6, 12, 0);
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


        verticalLayout->addWidget(frame);

        frame_2 = new QFrame(ToolPart);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setStyleSheet(QStringLiteral("#frame_2{border:none;background:#f9f9f9;}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(6, 6, 6, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(2);
        gridLayout_3->setVerticalSpacing(16);
        gridLayout_3->setContentsMargins(-1, -1, -1, 12);
        placeComb = new QComboBox(frame_2);
        placeComb->setObjectName(QStringLiteral("placeComb"));
        sizePolicy3.setHeightForWidth(placeComb->sizePolicy().hasHeightForWidth());
        placeComb->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(placeComb, 5, 1, 1, 2);

        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(label_8, 4, 0, 1, 1);

        fontComboBox = new QFontComboBox(frame_2);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        sizePolicy3.setHeightForWidth(fontComboBox->sizePolicy().hasHeightForWidth());
        fontComboBox->setSizePolicy(sizePolicy3);
        fontComboBox->setMaximumSize(QSize(180, 16777215));
        fontComboBox->setFocusPolicy(Qt::ClickFocus);

        gridLayout_3->addWidget(fontComboBox, 4, 1, 1, 2);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(label_6, 2, 0, 1, 1);

        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy2.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(label_9, 5, 0, 1, 1);

        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(label_7, 3, 0, 1, 1);

        hotComb = new QComboBox(frame_2);
        hotComb->setObjectName(QStringLiteral("hotComb"));
        sizePolicy3.setHeightForWidth(hotComb->sizePolicy().hasHeightForWidth());
        hotComb->setSizePolicy(sizePolicy3);
        hotComb->setFrame(true);

        gridLayout_3->addWidget(hotComb, 2, 1, 1, 2);

        fontLab = new QLabel(frame_2);
        fontLab->setObjectName(QStringLiteral("fontLab"));
        sizePolicy.setHeightForWidth(fontLab->sizePolicy().hasHeightForWidth());
        fontLab->setSizePolicy(sizePolicy);
        fontLab->setStyleSheet(QLatin1String("#fontLab{\n"
"border:1px solid #ccc;\n"
"border-top:none;\n"
"border-left:none;\n"
"border-right:none;\n"
"padding:6px 4px;\n"
"}\n"
""));

        gridLayout_3->addWidget(fontLab, 0, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 6, 2, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetFixedSize);
        sizeSpin = new QSpinBox(frame_2);
        sizeSpin->setObjectName(QStringLiteral("sizeSpin"));
        sizePolicy3.setHeightForWidth(sizeSpin->sizePolicy().hasHeightForWidth());
        sizeSpin->setSizePolicy(sizePolicy3);
        sizeSpin->setMinimumSize(QSize(80, 0));
        sizeSpin->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_5->addWidget(sizeSpin);

        autoMoveComb = new QCheckBox(frame_2);
        autoMoveComb->setObjectName(QStringLiteral("autoMoveComb"));
        autoMoveComb->setStyleSheet(QStringLiteral("margin-left:16px"));

        horizontalLayout_5->addWidget(autoMoveComb);


        gridLayout_3->addLayout(horizontalLayout_5, 3, 1, 1, 2);

        gridLayout_3->setColumnStretch(0, 1);

        horizontalLayout_2->addLayout(gridLayout_3);


        verticalLayout->addWidget(frame_2);


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
        label_8->setText(QApplication::translate("ToolPart", "\345\255\227\344\275\223\357\274\232", 0));
        label_6->setText(QApplication::translate("ToolPart", "\347\203\255\351\227\250\357\274\232", 0));
        label_9->setText(QApplication::translate("ToolPart", "\344\275\215\347\275\256\357\274\232", 0));
        label_7->setText(QApplication::translate("ToolPart", "\345\244\247\345\260\217\357\274\232", 0));
        fontLab->setText(QApplication::translate("ToolPart", "\346\226\207\345\255\227", 0));
        autoMoveComb->setText(QApplication::translate("ToolPart", "\350\207\252\347\224\261\347\247\273\345\212\250", 0));
    } // retranslateUi

};

namespace Ui {
    class ToolPart: public Ui_ToolPart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLPART_H
