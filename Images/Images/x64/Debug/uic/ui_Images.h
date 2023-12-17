/********************************************************************************
** Form generated from reading UI file 'Images.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGES_H
#define UI_IMAGES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImagesClass
{
public:

    void setupUi(QWidget *ImagesClass)
    {
        if (ImagesClass->objectName().isEmpty())
            ImagesClass->setObjectName("ImagesClass");
        ImagesClass->resize(600, 400);

        retranslateUi(ImagesClass);

        QMetaObject::connectSlotsByName(ImagesClass);
    } // setupUi

    void retranslateUi(QWidget *ImagesClass)
    {
        ImagesClass->setWindowTitle(QCoreApplication::translate("ImagesClass", "Images", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImagesClass: public Ui_ImagesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGES_H
