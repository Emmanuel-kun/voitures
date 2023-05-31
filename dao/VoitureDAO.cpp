//
// Created by Administrateur on 25/05/2023.
//

#include "VoitureDAO.h"

VoitureDAO::VoitureDAO(){init();}

void VoitureDAO::init() const{

    DB::db_.open();
    QSqlQuery query = QSqlQuery(DB::db_);

    if (!query.exec("CREATE TABLE IF NOT EXISTS Voiture (id INTEGER PRIMARY KEY, marque TEXT, modele TEXT, anneeFabrication INTEGER, prix DOUBLE)")) {
        // Gérer l'erreur de création de la table
    }
    DB::db_.close();
}

bool VoitureDAO::add(Voiture& voiture){
    QSqlQuery query;
    DB::db_.open();
    query = QSqlQuery(DB::db_);
    query.prepare("INSERT INTO voiture (marque,modele,anneeFabrication,prix) VALUES (:marque,:modele,:anneeFab,:prix)");
    query.bindValue(":marque", voiture.marque());
    query.bindValue(":modele", voiture.modele());
    query.bindValue(":anneeFab",voiture.anneeFabrication());
    query.bindValue(":prix",voiture.prix());

    bool result = query.exec();
    QVariant id = query.lastInsertId();
    if(id.isValid()) {
        voiture.setId(id.toInt());
    }
    if(!result) {
        QSqlError error = query.lastError();
        qDebug() << error.text();
    }
    DB::db_.close();
    return true;
}


bool VoitureDAO::remove(const int id){
    QSqlQuery query;
    DB::db_.open();
    query = QSqlQuery(DB::db_);
    query.prepare("DELETE FROM voiture WHERE id=:id");
    query.bindValue(":id", id);

    bool result = query.exec();
    if(!result) {
        QSqlError error = query.lastError();
        qDebug() << error.text();
    }
    DB::db_.close();
    return true;
}

QList<Voiture> VoitureDAO::getAll(){
    QSqlQuery query;
    DB::db_.open();
    query = QSqlQuery(DB::db_);
    QList<Voiture> qlVoiture;
    if (!query.exec("SELECT * FROM voiture")) {
        QSqlError error = query.lastError();
        qDebug() << error.text();
    }
    while (query.next()) {
        qlVoiture << Voiture(query.value("id").toInt(),query.value("marque").toString(), query.value("modele").toString(), query.value("anneeFabrication").toInt(), query.value("prix").toFloat());
    }
    return qlVoiture;
}



Voiture VoitureDAO::get(const int id){
    QSqlQuery query;
    DB::db_.open();
    query = QSqlQuery(DB::db_);
    query.prepare("SELECT * FROM voiture WHERE id=:id");
    query.bindValue(":id", id);

    bool result = query.exec();
    if(!result) {
        QSqlError error = query.lastError();
        qDebug() << error.text();
    }
    while (query.next()) {
        return Voiture(query.value("id").toInt(),query.value("marque").toString(), query.value("modele").toString(), query.value("anneeFabrication").toInt(), query.value("prix").toFloat());
    }
    DB::db_.close();
    throw "No voiture found";
}

