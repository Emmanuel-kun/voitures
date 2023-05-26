//
// Created by Administrateur on 25/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_vueVoitures.h" resolved

#include "vuevoitures.h"
#include "ui_vueVoitures.h"


vueVoitures::vueVoitures(QWidget *parent) :
        QWidget(parent), ui(new Ui::vueVoitures) {
    ui->setupUi(this);
}

vueVoitures::~vueVoitures() {
    delete ui;
}

void vueVoitures::createContent() {
    liste = new listeVoiture(this);
    //form = new formVoiture(this);
    vBoxLayout = new QVBoxLayout(this);
    vBoxLayout->addWidget(liste);

}