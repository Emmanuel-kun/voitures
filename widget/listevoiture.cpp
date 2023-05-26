//
// Created by Administrateur on 26/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_listeVoiture.h" resolved

#include "listevoiture.h"
#include "ui_listeVoiture.h"
#include "../pages/mainwindow.h"

listeVoiture::listeVoiture(QWidget *parent) :
        QWidget(parent), ui(new Ui::listeVoiture) {
    ui->setupUi(this);
    createContent();
}

listeVoiture::~listeVoiture() {
    delete ui;
}

void listeVoiture::createContent() {
    liste = new QTableWidget(this);
    QStringList headers;
    headers << "ID" << "Marque" << "Modèle" << "DateFab" << "Prix";
    liste->insertColumn(5);
    liste->setHorizontalHeaderLabels(headers);
    this
    VoitureDAO voitureDao(((mainWindow*) this->parent()->parent())->db_);
    QList<Voiture> voitures = voitureDao.getAll();
    liste->setRowCount(voitures.size());
    int k(0);
    for (Voiture v : voitures) {
        liste->setItem(k,0,new QTableWidgetItem(v.id()));
        liste->setItem(k,1,new QTableWidgetItem(v.marque()));
        liste->setItem(k,2,new QTableWidgetItem(v.modele()));
        liste->setItem(k,3,new QTableWidgetItem(v.anneeFabrication()));
        liste->setItem(k,4,new QTableWidgetItem(v.prix()));
        k++;
    }
}


void listeVoiture::handleVoitureAdded(Voiture &voiture) {
    int k = liste->rowCount();
    liste->setRowCount(++k);
    liste->setItem(k,0,new QTableWidgetItem(voiture.id()));
    liste->setItem(k,1,new QTableWidgetItem(voiture.marque()));
    liste->setItem(k,2,new QTableWidgetItem(voiture.modele()));
    liste->setItem(k,3,new QTableWidgetItem(voiture.anneeFabrication()));
    liste->setItem(k,4,new QTableWidgetItem(voiture.prix()));

}

void listeVoiture::handleVoitureDeleted();

