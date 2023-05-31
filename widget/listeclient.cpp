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
#include <QHBoxLayout>


listeClient::listeClient(QWidget *parent) :
        QWidget(parent), ui(new Ui::listeClient) {
    ui->setupUi(this);
    this->liste = new QTableWidget(this);
    liste->resize(800,600);
    for(int i=0;i<4;i++){
        liste->insertColumn(i);
    }
    createContent();

    QStringList column;

    column << "Prenom" << "Nom" << "Mail" << "Supprimer";
    this->liste->setHorizontalHeaderLabels(column);
}

listeClient::~listeClient() {
    delete ui;
}

listeClient::DeleteButton::DeleteButton(int client ,QWidget *parent):QPushButton(parent){

    this->id = client;
    this->setText("Supprimer");
}

void listeClient::DeleteButton::hitButton(const QPoint & pos)
{
    try{
        qDebug() << "Essai de suppression du client" <<"\n";
        qDebug() << this->id << "\n";
        ClientDAO * dao = new ClientDAO();
        dao->remove(this->id);
        ((listeClient*)this->parent())->refreshList();
    }catch(...){
        qDebug() << "Erreur lors de la suppression du client\n";

    }

}

void listeClient::createContent() {
    refreshList();
}

void listeClient::refreshList(){
    ClientDAO clientDao;
    QList<Client> clients= clientDao.getAll();
    this->liste->setRowCount(clients.size());
    int k(0);
    for (Client c : clients) {

        liste->setItem(k,0,new QTableWidgetItem(c.getNom()));
        liste->setItem(k,1,new QTableWidgetItem(c.getPrenom()));
        liste->setItem(k,2,new QTableWidgetItem(c.getMail()));
        QWidget* pWidget = new QWidget();
        QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
        listeClient::DeleteButton * btn_del=new listeClient::DeleteButton(c.getId(),liste);

        pLayout->addWidget(btn_del);

        liste->setCellWidget(k,3,pWidget);

        k++;
    }
    liste->show();

    /*for(int i = 0; i < clients.size();i++)
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


    }*/
}