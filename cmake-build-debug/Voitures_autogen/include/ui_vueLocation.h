/********************************************************************************
** Form generated from reading UI file 'vuelocation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VUELOCATION_H
#define UI_VUELOCATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_vueLocation
{
public:

    void setupUi(QWidget *vueLocation)
    {
        if (vueLocation->objectName().isEmpty())
            vueLocation->setObjectName(QString::fromUtf8("vueLocation"));
        vueLocation->resize(400, 300);

        retranslateUi(vueLocation);

        QMetaObject::connectSlotsByName(vueLocation);
    } // setupUi

    void retranslateUi(QWidget *vueLocation)
    {
        vueLocation->setWindowTitle(QCoreApplication::translate("vueLocation", "vueLocation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class vueLocation: public Ui_vueLocation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VUELOCATION_H
