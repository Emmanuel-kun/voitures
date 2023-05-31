//
// Created by Administrateur on 25/05/2023.
//

#ifndef VOITURES_VUEVOITURES_H
#define VOITURES_VUEVOITURES_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include "../widget/listevoiture.h"
//#include "mainwindow.h"


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
    QVBoxLayout *vBoxLayout;
    QWidget *voitureForm, *buttons;
    QFormLayout *formLayout;
    QLineEdit *marqueLine, *modeleLine, *anneeLine, *prixLine;
    QHBoxLayout *hBoxLayout;
    QPushButton *ajouterButton, *supprimerButton;

    void createContent();

public slots:
    void handleVoitureAdded();
    void handleVoitureDeleted();
};


#endif //VOITURES_VUEVOITURES_H
