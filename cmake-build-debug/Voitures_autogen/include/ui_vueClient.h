/********************************************************************************
** Form generated from reading UI file 'vueclient.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VUECLIENT_H
#define UI_VUECLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_vueClient
{
public:

    void setupUi(QWidget *vueClient)
    {
        if (vueClient->objectName().isEmpty())
            vueClient->setObjectName(QString::fromUtf8("vueClient"));
        vueClient->resize(400, 300);

        retranslateUi(vueClient);

        QMetaObject::connectSlotsByName(vueClient);
    } // setupUi

    void retranslateUi(QWidget *vueClient)
    {
        vueClient->setWindowTitle(QCoreApplication::translate("vueClient", "vueClient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class vueClient: public Ui_vueClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VUECLIENT_H
