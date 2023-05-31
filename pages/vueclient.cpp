//
// Created by Administrateur on 25/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_vueClient.h" resolved

#include "vueclient.h"
#include "ui_vueClient.h"


vueClient::vueClient(QWidget *parent) :
        QWidget(parent), ui(new Ui::vueClient) {
    ui->setupUi(this);
    createContent();
}

vueClient::~vueClient() {
    delete ui;
}

void vueClient::createContent()
{
    listeCli = new listeClient(this);
    //form = new formVoiture(this);
    gridLayout = new QGridLayout(this);
    gridLayout->addWidget(listeCli,0,0,6,5);

    labelNom= new QLabel("Nom : ", this);
    textNom = new QLineEdit(this);
    gridLayout->addWidget(labelNom,5,0,2,1);
    gridLayout->addWidget(textNom,5,2,4,1);

    labelPrenom= new QLabel("Prenom : ", this);
    textPrenom = new QLineEdit(this);
    gridLayout->addWidget(labelPrenom,6,0,2,1);
    gridLayout->addWidget(textPrenom,6,2,4,1);

    labelEmail= new QLabel("Email : ", this);
    textEmail = new QLineEdit(this);
    gridLayout->addWidget(labelEmail,7,0,2,1);
    gridLayout->addWidget(textEmail,7,2,4,1);

    addButton= new QPushButton("Ajouter", this);
    QObject::connect(addButton, &QPushButton::clicked, this, &vueClient::handleClientAdded);
    gridLayout->addWidget(addButton,8,0,3,1);


}

void vueClient::handleClientAdded(){
    try{
        ClientDAO clientDao;
        Client cli= Client(textNom->text(),textPrenom->text(),textEmail->text());
        clientDao.add(cli);
        qDebug() << "Ajout du client" << cli.getPrenom() <<cli.getNom();
        listeCli->refreshList();
    }catch(...){
        qDebug() << "Erreur lors de l'ajout du client\n";
    }
}
