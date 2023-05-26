//
// Created by Administrateur on 25/05/2023.
//

#include "ClientDAO.h"

void ClientDAO::init() const{

    QSqlQuery query;

    if (!query.exec("CREATE TABLE client (id INTEGER PRIMARY KEY, nom TEXT, prenom TEXT, email TEXT)")) {
        // Gérer l'erreur de création de la table
    }
}

bool ClientDAO::add(Client& contact){
    db_.open();
    QSqlQuery query = QSqlQuery(db_);
    query.prepare("INSERT INTO client (nom,prenom,mail)");
    query.bindValue(":nom", contact.getNom());
    query.bindValue(":prenom", contact.getPrenom());
    query.bindValue(":mail", contact.getMail());

    bool result = query.exec();
    QVariant id = query.lastInsertId();
    if(id.isValid()) {
        contact.setId(id.toInt());
    }
    if(!result) {
        QSqlError error = query.lastError();
        qDebug() << error.text();
    }
    db_.close();
    return result;
}


bool ClientDAO::remove(const int id){
    db_.open();
    QSqlQuery query = QSqlQuery(db_);
    query.prepare("DELETE FROM Client where id = :id");
    query.bindValue(":id", id);
    bool result = query.exec();
    if(!result) {
        QSqlError error = query.lastError();
        qDebug() << error.text();
    }
    db_.close();
    return result;
}

QList<Client> ClientDAO::getAll(){
    QSqlQuery query;
    QList<Client> qlContact;
    if (!query.exec("SELECT * FROM client")) {

    }
    while (query.next()) {
        qlContact << Client();
    }
    return qlContact;
}



Client ClientDAO::get(const int id){
    QSqlQuery query;
    if (!query.exec("SELECT * FROM client")) {

    }
    while (query.next()) {
        return Client();
    }
    throw "Contact not found";
}