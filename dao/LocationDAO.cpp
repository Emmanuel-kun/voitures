//
// Created by Administrateur on 25/05/2023.
//

#include "LocationDAO.h"

void LocationDAO::init() const{
    db_.open();
    if(!db_.tables().contains("Location")) {
        QSqlQuery query = QSqlQuery(db_);
        bool result = query.exec("CREATE TABLE Location (id INTEGER PRIMARY KEY, client_id INTEGER, voiture_id INTEGER, date_debut DATETIME, date_fin DATETIME)");
        if(!result) {
            QSqlError error = query.lastError();
            qDebug() << error.text();
        }
    }
    db_.close();
}

bool LocationDAO::add(Location& location){
    db_.open();
    QSqlQuery query = QSqlQuery(db_);
    query.prepare("INSERT INTO location (client_id, voiture_id, date_debut, date_fin) values (:client_id, :voiture_id, :date_debut, :date_fin)");
    query.bindValue(":client_id", location.client_id());
    query.bindValue(":voiture_id", location.voiture_id());
    query.bindValue(":date_debut", location.date_debut());
    query.bindValue(":date_fin", location.date_fin());
    bool result = query.exec();
    QVariant id = query.lastInsertId();
    if(id.isValid()) {
        location.setId(id.toInt());
    }
    if(!result) {
        QSqlError error = query.lastError();
        qDebug() << error.text();
    }
    db_.close();
    return result;
}


bool LocationDAO::remove(const int id){
    db_.open();
    QSqlQuery query = QSqlQuery(db_);
    query.prepare("DELETE FROM Location where id = :id");
    query.bindValue(":id", id);
    bool result = query.exec();
    if(!result) {
        QSqlError error = query.lastError();
        qDebug() << error.text();
    }
    db_.close();
    return result;
}

QList<Location> LocationDAO::getAll(){
    QList<Location> locations;
    db_.open();
    QSqlQuery query = QSqlQuery(db_);
    query.exec("SELECT * FROM Location");
    while(query.next()) {
        locations.append(Location(query.value("id").toInt(),query.value("client_id").toInt(), query.value("voiture_id").toInt(), query.value("date_debut").toString(), query.value("date_fin").toString()));
    }
    db_.close();
    return locations;
}



Location LocationDAO::get(const int id){
    db_.open();
    QSqlQuery query = QSqlQuery(db_);
    query.prepare("SELECT * FROM Location WHERE id = :id");
    query.bindValue(":id", id);
    db_.close();
    if(query.next()) {
        return Location(query.value("id").toInt(),query.value("client_id").toInt(), query.value("voiture_id").toInt(), query.value("date_debut").toString(), query.value("date_fin").toString());
    } else {
        db_.close();
        return Location();
    }
}


QList<Location> LocationDAO::getVoitureFutureLocations(const Voiture& voiture){
    db_.open();
    QList<Location> locations;
    QSqlQuery query = QSqlQuery(db_);
    query.prepare("SELECT * FROM location WHERE voiture_id=:id AND date_fin>= CURDATE()");
    query.bindValue(":id", voiture.id());

    bool result = query.exec();
    if(!result) {
        QSqlError error = query.lastError();
        qDebug() << error.text();
    }
    while (query.next()) {
        locations.append(Location(query.value("id").toInt(),query.value("client_id").toInt(), query.value("voiture_id").toInt(), query.value("date_debut").toString(), query.value("date_fin").toString()));
    }
    db_.close();
    return locations;

}
