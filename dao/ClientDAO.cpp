//
// Created by Administrateur on 25/05/2023.
//

#include "ClientDAO.h"

ClientDAO::ClientDAO(){init();}

void ClientDAO::init() const{

    DB::db_.open();
    QSqlQuery query = QSqlQuery(DB::db_);

    if (!query.exec("CREATE TABLE IF NOT EXISTS client (id INTEGER PRIMARY KEY, nom TEXT, prenom TEXT, email TEXT)")) {
        // Gérer l'erreur de création de la table
    }
    DB::db_.close();
}

bool ClientDAO::add(Client& contact){
    DB::db_.open();
    QSqlQuery query = QSqlQuery(DB::db_);
    query.prepare("INSERT INTO client (nom,prenom,email) VALUES (:nom,:prenom,:email)");
    query.bindValue(":nom", contact.getNom());
    query.bindValue(":prenom", contact.getPrenom());
    query.bindValue(":email", contact.getMail());

    bool result = query.exec();
    QVariant id = query.lastInsertId();
    if(id.isValid()) {
        contact.setId(id.toInt());
    }
    if(!result) {
        QSqlError error = query.lastError();
        qDebug() << error.text();
    }

    DB::db_.close();
    return result;
}


bool ClientDAO::remove(const int id){
    DB::db_.open();
    QSqlQuery query = QSqlQuery(DB::db_);
    query.prepare("DELETE FROM client where id = :id");
    query.bindValue(":id", id);
    bool result = query.exec();
    if(!result) {
        QSqlError error = query.lastError();
        qDebug() << error.text();
    }
    DB::db_.close();
    return result;
}

QList<Client> ClientDAO::getAll(){
    DB::db_.open();
    QSqlQuery query;
    QList<Client> qlContact;

    if (!query.exec("SELECT * FROM client")) {

    }
    while (query.next()) {

        qlContact << Client(query.value("id").toInt(),query.value("nom").toString(), query.value("prenom").toString(), query.value("email").toString());
    }
    DB::db_.close();
    return qlContact;
}



Client ClientDAO::get(const int id){
    DB::db_.open();
    QSqlQuery query= QSqlQuery(DB::db_);
    if (!query.exec("SELECT * FROM client")) {

    }
    while (query.next()) {
        return Client(query.value("id").toInt(),query.value("nom").toString(), query.value("prenom").toString(), query.value("email").toString());
    }
    throw "Contact not found";
}