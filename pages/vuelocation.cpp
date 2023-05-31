//
// Created by Administrateur on 25/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_vueLocation.h" resolved

#include "vuelocation.h"
#include "ui_vueLocation.h"


vueLocation::vueLocation(QWidget *parent) :
        QWidget(parent), ui(new Ui::vueLocation) {
    ui->setupUi(this);
    createContent();
}

vueLocation::~vueLocation() {
    delete ui;
}


void vueLocation::createContent()
{
    listeCli= new listeClient(this);
    listeVoi = new listeVoiture(this);
    //form = new formVoiture(this);
    vBoxLayout = new QVBoxLayout(this);
    vBoxLayout->addWidget(listeCli);
    vBoxLayout->addWidget(listeVoi);

}