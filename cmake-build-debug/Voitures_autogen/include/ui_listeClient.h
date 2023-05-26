/********************************************************************************
** Form generated from reading UI file 'listeclient.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTECLIENT_H
#define UI_LISTECLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_listeClient
{
public:

    void setupUi(QWidget *listeClient)
    {
        if (listeClient->objectName().isEmpty())
            listeClient->setObjectName(QString::fromUtf8("listeClient"));
        listeClient->resize(400, 300);

        retranslateUi(listeClient);

        QMetaObject::connectSlotsByName(listeClient);
    } // setupUi

    void retranslateUi(QWidget *listeClient)
    {
        listeClient->setWindowTitle(QCoreApplication::translate("listeClient", "listeClient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class listeClient: public Ui_listeClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTECLIENT_H
