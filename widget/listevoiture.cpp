//
// Created by Administrateur on 26/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_listeVoiture.h" resolved

#include "listevoiture.h"
#include "ui_listeVoiture.h"
#include "QDebug"

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
    liste->resize(800,600);
    QStringList headers;
    headers << "ID" << "Marque" << "Modèle" << "DateFab" << "Prix";
    for(int i=0;i<5;i++){
        liste->insertColumn(i);
    }
    liste->setHorizontalHeaderLabels(headers);
    //qDebug() << this->parent()->parent() << "\n";
    //qDebug() << ((mainWindow*) this->parent()->parent())->db_ << "\n";

    //qDebug() << *((mainWindow*) this->parent()->parent())->db_ << "\n";
    VoitureDAO voitureDao;
    QList<Voiture> voitures = voitureDao.getAll();
    liste->setRowCount(voitures.size());
    int k(0);
    for (Voiture v : voitures) {
        liste->setItem(k,0,new QTableWidgetItem(QString::number(v.id())));
        liste->setItem(k,1,new QTableWidgetItem(v.marque()));
        liste->setItem(k,2,new QTableWidgetItem(v.modele()));
        liste->setItem(k,3,new QTableWidgetItem(QString::number(v.anneeFabrication())));
        liste->setItem(k,4,new QTableWidgetItem(QString::number(v.prix())));
        k++;
    }
    liste->show();
}


void listeVoiture::addVoiture(Voiture &voiture) {
    //Recup voiture de form
    int k = liste->rowCount()+1;
    liste->setRowCount(k);
    liste->setItem(k,0,new QTableWidgetItem(QString::number(voiture.id())));
    liste->setItem(k,1,new QTableWidgetItem(voiture.marque()));
    liste->setItem(k,2,new QTableWidgetItem(voiture.modele()));
    liste->setItem(k,3,new QTableWidgetItem(QString::number((voiture.anneeFabrication()))));
    liste->setItem(k,4,new QTableWidgetItem(QString::number((voiture.prix()))));

}

//void listeVoiture::handleVoitureDeleted(){};

