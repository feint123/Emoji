/********************************************************************************
** Form generated from reading UI file 'imagepart.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEPART_H
#define UI_IMAGEPART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImagePart
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *frame;
    QVBoxLayout *verticalLayout;
    QLabel *tipLabel;

    void setupUi(QDialog *ImagePart)
    {
        if (ImagePart->objectName().isEmpty())
            ImagePart->setObjectName(QStringLiteral("ImagePart"));
        ImagePart->resize(506, 376);
        ImagePart->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(ImagePart);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 1, 1);
        frame = new QWidget(ImagePart);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QStringLiteral("QWidget{border:0px solid #ccc;border-right:1px solid #ccc;border-bottom:1px solid #ccc;}"));
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tipLabel = new QLabel(frame);
        tipLabel->setObjectName(QStringLiteral("tipLabel"));
        tipLabel->setStyleSheet(QString::fromUtf8("#tipLabel{\n"
"max-height:24px;\n"
"background:#feffbb\357\274\233\n"
"}"));

        verticalLayout->addWidget(tipLabel);


        horizontalLayout->addWidget(frame);


        retranslateUi(ImagePart);

        QMetaObject::connectSlotsByName(ImagePart);
    } // setupUi

    void retranslateUi(QDialog *ImagePart)
    {
        ImagePart->setWindowTitle(QApplication::translate("ImagePart", "Dialog", 0));
        tipLabel->setText(QApplication::translate("ImagePart", "\350\257\267\345\234\250\345\217\263\344\276\247\351\200\211\346\213\251\346\210\226\347\274\226\350\276\221\344\275\240\346\211\200\351\234\200\350\246\201\347\232\204\346\226\207\345\255\227", 0));
    } // retranslateUi

};

namespace Ui {
    class ImagePart: public Ui_ImagePart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEPART_H
