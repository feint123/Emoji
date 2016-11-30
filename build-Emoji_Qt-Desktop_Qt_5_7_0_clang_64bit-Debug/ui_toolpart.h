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
    QLabel *label_11;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_3;
    QSlider *horizontalSlider_3;
    QLabel *label_10;
    QLabel *label;
    QLabel *imgLab;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox;
    QPushButton *zoomIn;
    QLabel *label_2;
    QPushButton *zoomOut;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox_2;
    QDoubleSpinBox *doubleSpinBox;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_3;
    QComboBox *comboBox_2;
    QLabel *label_8;
    QFontComboBox *fontComboBox;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_7;
    QComboBox *comboBox;
    QLabel *fontLab;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *spinBox;
    QCheckBox *checkBox_3;

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
        QBrush brush(QColor(238, 238, 238, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        ToolPart->setPalette(palette);
        ToolPart->setStyleSheet(QLatin1String("#ToolPart{\n"
"background:#eee;\n"
"border-left:1px solid #666;\n"
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
        label_11 = new QLabel(frame);
        label_11->setObjectName(QStringLiteral("label_11"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_11, 4, 2, 1, 1);

        horizontalSlider_2 = new QSlider(frame);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_2, 3, 1, 1, 1);

        horizontalSlider = new QSlider(frame);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider, 2, 1, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        horizontalSlider_3 = new QSlider(frame);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_3, 4, 1, 1, 1);

        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 3, 2, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(label, 2, 2, 1, 1);

        imgLab = new QLabel(frame);
        imgLab->setObjectName(QStringLiteral("imgLab"));
        sizePolicy.setHeightForWidth(imgLab->sizePolicy().hasHeightForWidth());
        imgLab->setSizePolicy(sizePolicy);
        QPalette palette1;
        QBrush brush1(QColor(76, 76, 76, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QBrush brush2(QColor(255, 255, 255, 127));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        imgLab->setPalette(palette1);
        imgLab->setStyleSheet(QLatin1String("#imgLab{\n"
"border:1px solid #666;\n"
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
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_3->addWidget(checkBox);

        zoomIn = new QPushButton(frame);
        zoomIn->setObjectName(QStringLiteral("zoomIn"));
        zoomIn->setFocusPolicy(Qt::ClickFocus);
        zoomIn->setStyleSheet(QLatin1String("#zoomIn{\n"
"border-radius:10px;\n"
"width:20px;\n"
"height:20px;\n"
"background-color:white;\n"
"}\n"
"#zoomIn:hover{\n"
"background-color:#4a90e2;\n"
"color:white;\n"
"}\n"
"#zoomIn:pressed{\n"
"background-color:#3980d1;\n"
"color:white;\n"
"}"));

        horizontalLayout_3->addWidget(zoomIn);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        zoomOut = new QPushButton(frame);
        zoomOut->setObjectName(QStringLiteral("zoomOut"));
        zoomOut->setFocusPolicy(Qt::ClickFocus);
        zoomOut->setStyleSheet(QLatin1String("#zoomOut{\n"
"\n"
"border-radius:12px;\n"
"width:24px;\n"
"height:24px;\n"
"background-color:white;\n"
"}\n"
"#zoomOut:hover{\n"
"background-color:#d0021b;\n"
"color:white\n"
"}\n"
"#zoomOut:select{\n"
"background-color:yellow;\n"
"}"));

        horizontalLayout_3->addWidget(zoomOut);

        horizontalLayout_3->setStretch(0, 1);

        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        checkBox_2 = new QCheckBox(frame);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        horizontalLayout_4->addWidget(checkBox_2);

        doubleSpinBox = new QDoubleSpinBox(frame);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(doubleSpinBox->sizePolicy().hasHeightForWidth());
        doubleSpinBox->setSizePolicy(sizePolicy3);
        doubleSpinBox->setMinimumSize(QSize(80, 0));
        doubleSpinBox->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_4->addWidget(doubleSpinBox);


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
        comboBox_2 = new QComboBox(frame_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        sizePolicy3.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(comboBox_2, 5, 1, 1, 2);

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

        comboBox = new QComboBox(frame_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy3.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy3);
        comboBox->setFrame(true);

        gridLayout_3->addWidget(comboBox, 2, 1, 1, 2);

        fontLab = new QLabel(frame_2);
        fontLab->setObjectName(QStringLiteral("fontLab"));
        sizePolicy.setHeightForWidth(fontLab->sizePolicy().hasHeightForWidth());
        fontLab->setSizePolicy(sizePolicy);
        fontLab->setStyleSheet(QLatin1String("#fontLab{\n"
"border:1px solid #666;\n"
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
        spinBox = new QSpinBox(frame_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        sizePolicy3.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy3);
        spinBox->setMinimumSize(QSize(80, 0));
        spinBox->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_5->addWidget(spinBox);

        checkBox_3 = new QCheckBox(frame_2);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setStyleSheet(QStringLiteral("margin-left:16px"));

        horizontalLayout_5->addWidget(checkBox_3);


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
        label_11->setText(QApplication::translate("ToolPart", "100%", 0));
        label_4->setText(QApplication::translate("ToolPart", "\347\273\277\350\211\262\357\274\232", 0));
        label_5->setText(QApplication::translate("ToolPart", "\350\223\235\350\211\262\357\274\232", 0));
        label_3->setText(QApplication::translate("ToolPart", "\347\272\242\350\211\262\357\274\232", 0));
        label_10->setText(QApplication::translate("ToolPart", "100%", 0));
        label->setText(QApplication::translate("ToolPart", "100%", 0));
        imgLab->setText(QApplication::translate("ToolPart", "\345\233\276\347\211\207", 0));
        checkBox->setText(QApplication::translate("ToolPart", "\350\275\254\347\201\260\345\272\246\345\233\276", 0));
        zoomIn->setText(QApplication::translate("ToolPart", "\357\274\215", 0));
        label_2->setText(QApplication::translate("ToolPart", "100%", 0));
        zoomOut->setText(QApplication::translate("ToolPart", "\357\274\213", 0));
        checkBox_2->setText(QApplication::translate("ToolPart", "\345\216\213\347\274\251\345\233\276\347\211\207", 0));
        label_8->setText(QApplication::translate("ToolPart", "\345\255\227\344\275\223\357\274\232", 0));
        label_6->setText(QApplication::translate("ToolPart", "\347\203\255\351\227\250\357\274\232", 0));
        label_9->setText(QApplication::translate("ToolPart", "\344\275\215\347\275\256\357\274\232", 0));
        label_7->setText(QApplication::translate("ToolPart", "\345\244\247\345\260\217\357\274\232", 0));
        fontLab->setText(QApplication::translate("ToolPart", "\346\226\207\345\255\227", 0));
        checkBox_3->setText(QApplication::translate("ToolPart", "\350\207\252\347\224\261\347\247\273\345\212\250", 0));
    } // retranslateUi

};

namespace Ui {
    class ToolPart: public Ui_ToolPart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLPART_H
