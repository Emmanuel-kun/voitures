//
// Created by Administrateur on 25/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_vueVoitures.h" resolved

#include "vuevoitures.h"
#include "ui_vueVoitures.h"
#include "QDebug"

vueVoitures::vueVoitures(QWidget *parent) :
        QWidget(parent), ui(new Ui::vueVoitures) {
    ui->setupUi(this);
    createContent();
}

vueVoitures::~vueVoitures() {
    delete ui;
}

void vueVoitures::createContent() {
    liste = new listeVoiture(this);
    //form = new formVoiture(this);
    vBoxLayout = new QVBoxLayout(this);
    vBoxLayout->addWidget(liste);

    voitureForm = new QWidget(this);
    formLayout = new QFormLayout(voitureForm );
    marqueLine = new QLineEdit(voitureForm );
    modeleLine = new QLineEdit(voitureForm );
    anneeLine = new QLineEdit(voitureForm );
    prixLine = new QLineEdit(voitureForm );
    formLayout->addRow("Marque", marqueLine);
    formLayout->addRow("Modèle", modeleLine);
    formLayout->addRow("Année de fabr.", anneeLine);
    formLayout->addRow("Prix", prixLine);
    vBoxLayout->addWidget(voitureForm);

    buttons = new QWidget(this);
    hBoxLayout = new QHBoxLayout(buttons);
    ajouterButton = new QPushButton("Ajouter",buttons);
    supprimerButton = new QPushButton("Supprimer",buttons);
    hBoxLayout->addWidget(ajouterButton);
    hBoxLayout->addWidget(supprimerButton);
    vBoxLayout->addWidget(buttons);



    QObject::connect(ajouterButton, &QPushButton::clicked, this, &vueVoitures::handleVoitureAdded);
    QObject::connect(supprimerButton, &QPushButton::clicked, this, &vueVoitures::handleVoitureDeleted);
}

void vueVoitures::handleVoitureAdded() {
    VoitureDAO voitureDao;
    Voiture voiture = Voiture(marqueLine->text(),modeleLine->text(),anneeLine->text().toInt(), prixLine->text().toFloat());
    voitureDao.add(voiture);
    liste->addVoiture(voiture);
}

void vueVoitures::handleVoitureDeleted() {

}