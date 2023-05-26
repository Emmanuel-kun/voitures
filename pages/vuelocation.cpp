//
// Created by Administrateur on 25/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_vueLocation.h" resolved

#include "vuelocation.h"
#include "ui_vueLocation.h"


vueLocation::vueLocation(QWidget *parent) :
        QWidget(parent), ui(new Ui::vueLocation) {
    ui->setupUi(this);
}

vueLocation::~vueLocation() {
    delete ui;
}
