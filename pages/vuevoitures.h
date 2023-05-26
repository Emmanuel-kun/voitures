//
// Created by Administrateur on 25/05/2023.
//

#ifndef VOITURES_VUEVOITURES_H
#define VOITURES_VUEVOITURES_H

#include <QWidget>
#include <QVBoxLayout>
#include "../widget/listevoiture.h"
//#include "../widget/formvoiture.h"


QT_BEGIN_NAMESPACE
namespace Ui { class vueVoitures; }
QT_END_NAMESPACE

class vueVoitures : public QWidget {
Q_OBJECT

public:
    explicit vueVoitures(QWidget *parent = nullptr);

    ~vueVoitures() override;

private:
    Ui::vueVoitures *ui;
    listeVoiture *liste;
    //formVoiture *form;
    QVBoxLayout *vBoxLayout;
    void createContent();
};


#endif //VOITURES_VUEVOITURES_H
