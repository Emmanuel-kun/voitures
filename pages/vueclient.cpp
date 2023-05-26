//
// Created by Administrateur on 25/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_vueClient.h" resolved

#include "vueclient.h"
#include "ui_vueClient.h"
#include "../widget/listeclient.h"

vueClient::vueClient(QWidget *parent) :
        QWidget(parent), ui(new Ui::vueClient) {
    ui->setupUi(this);
}

vueClient::~vueClient() {
    delete ui;
}

void vueClient::createContent()
{
    listeClient * l = new listeClient(this);
    
}