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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImagePart
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *frame;
    QHBoxLayout *horizontalLayout_2;

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
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(frame);


        retranslateUi(ImagePart);

        QMetaObject::connectSlotsByName(ImagePart);
    } // setupUi

    void retranslateUi(QDialog *ImagePart)
    {
        ImagePart->setWindowTitle(QApplication::translate("ImagePart", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class ImagePart: public Ui_ImagePart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEPART_H
