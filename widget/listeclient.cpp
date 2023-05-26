//
// Created by Administrateur on 26/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_listeClient.h" resolved

#include "listeclient.h"
#include "ui_listeClient.h"
#include <vector>
#include "../entity/Client.h"
#include <Qstring>
#include "../dao/ClientDAO.h"

listeClient::listeClient(QWidget *parent) :
        QWidget(parent), ui(new Ui::listeClient) {
    ui->setupUi(this);

    this->liste = new QTableWidget(this);
    this->liste->insertColumn(3);
    QStringList column;

    column << "Prenom" << "Nom" << "Mail" << "Supprimer";
    this->liste->setVerticalHeaderLabels(column);
}

listeClient::~listeClient() {
    delete ui;
}

listeClient::DeleteButton::DeleteButton(int client ,QWidget *parent):QPushButton(parent){

    this->id = client;
    this->setText("Supprimer");
}

void listeClient::DeleteButton::keyPressEvent(QKeyEvent *e)
{
    ClientDAO * dao = new ClientDAO(parent()->parent()->db_);
    dao->remove(this->id);

}

void listeClient::createContent(std::vector<Client> clients) {

    this->liste->insertRow(clients.size());

    for(int i = 0; i < clients.size();i++)
    {
        QString nom = clients[i].getNom();
        QString prenom = clients[i].getPrenom();
        QString mail = clients[i].getMail();

        QTableWidgetItem * n = new QTableWidgetItem();
        n->setText(nom);

        QTableWidgetItem * p = new QTableWidgetItem();
        n->setText(prenom);

        QTableWidgetItem * m = new QTableWidgetItem();
        n->setText(mail);

        DeleteButton * b = new DeleteButton(clients[i].getId());
        liste->setCellWidget(i,3,(QWidget*)b);

        this->liste->setItem(i,0,p);
        this->liste->setItem(i,1,n);
        this->liste->setItem(i,2,m);


    }

}

void addClient(Client c)
{

}