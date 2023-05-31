//
// Created by Administrateur on 25/05/2023.
//

#ifndef VOITURES_VUELOCATION_H
#define VOITURES_VUELOCATION_H

#include <QWidget>
#include <QVBoxLayout>
#include "../widget/listeclient.h"

#include "../widget/listevoiture.h"


QT_BEGIN_NAMESPACE
namespace Ui { class vueLocation; }
QT_END_NAMESPACE

class vueLocation : public QWidget {
Q_OBJECT

public:
    explicit vueLocation(QWidget *parent = nullptr);

    ~vueLocation() override;
    void createContent();

private:
    Ui::vueLocation *ui;
    listeClient * listeCli;
    listeVoiture * listeVoi;
    QVBoxLayout *vBoxLayout;
};


#endif //VOITURES_VUELOCATION_H
