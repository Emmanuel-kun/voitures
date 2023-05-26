/********************************************************************************
** Form generated from reading UI file 'vuevoitures.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VUEVOITURES_H
#define UI_VUEVOITURES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_vueVoitures
{
public:

    void setupUi(QWidget *vueVoitures)
    {
        if (vueVoitures->objectName().isEmpty())
            vueVoitures->setObjectName(QString::fromUtf8("vueVoitures"));
        vueVoitures->resize(400, 300);

        retranslateUi(vueVoitures);

        QMetaObject::connectSlotsByName(vueVoitures);
    } // setupUi

    void retranslateUi(QWidget *vueVoitures)
    {
        vueVoitures->setWindowTitle(QCoreApplication::translate("vueVoitures", "vueVoitures", nullptr));
    } // retranslateUi

};

namespace Ui {
    class vueVoitures: public Ui_vueVoitures {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VUEVOITURES_H
