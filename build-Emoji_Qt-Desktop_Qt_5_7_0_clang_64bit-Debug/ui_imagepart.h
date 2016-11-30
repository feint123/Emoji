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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ImagePart
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *ImagePart)
    {
        if (ImagePart->objectName().isEmpty())
            ImagePart->setObjectName(QStringLiteral("ImagePart"));
        ImagePart->resize(400, 300);
        pushButton = new QPushButton(ImagePart);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(170, 140, 75, 23));

        retranslateUi(ImagePart);

        QMetaObject::connectSlotsByName(ImagePart);
    } // setupUi

    void retranslateUi(QDialog *ImagePart)
    {
        ImagePart->setWindowTitle(QApplication::translate("ImagePart", "Dialog", 0));
        pushButton->setText(QApplication::translate("ImagePart", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class ImagePart: public Ui_ImagePart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEPART_H
