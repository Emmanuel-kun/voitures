/********************************************************************************
** Form generated from reading UI file 'listevoiture.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTEVOITURE_H
#define UI_LISTEVOITURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_listeVoiture
{
public:

    void setupUi(QWidget *listeVoiture)
    {
        if (listeVoiture->objectName().isEmpty())
            listeVoiture->setObjectName(QString::fromUtf8("listeVoiture"));
        listeVoiture->resize(400, 300);

        retranslateUi(listeVoiture);

        QMetaObject::connectSlotsByName(listeVoiture);
    } // setupUi

    void retranslateUi(QWidget *listeVoiture)
    {
        listeVoiture->setWindowTitle(QCoreApplication::translate("listeVoiture", "listeVoiture", nullptr));
    } // retranslateUi

};

namespace Ui {
    class listeVoiture: public Ui_listeVoiture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTEVOITURE_H
