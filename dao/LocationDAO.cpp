//
// Created by Administrateur on 25/05/2023.
//

#include "LocationDAO.h"

LocationDAO::LocationDAO(){init();}


void LocationDAO::init() const{
    DB::db_.open();
    if(!DB::db_.tables().contains("Location")) {
        QSqlQuery query = QSqlQuery(DB::db_);
        bool result = query.exec("CREATE TABLE IF NOT EXISTS Location (id INTEGER PRIMARY KEY, client_id INTEGER, voiture_id INTEGER, date_debut DATETIME, date_fin DATETIME)");
        if(!result) {
            QSqlError error = query.lastError();
            qDebug() << error.text();
        }
    }
    DB::db_.close();
}

bool LocationDAO::add(Location& location){
    DB::db_.open();
    QSqlQuery query = QSqlQuery(DB::db_);
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
    DB::db_.close();
    return result;
}


bool LocationDAO::remove(const int id){
    DB::db_.open();
    QSqlQuery query = QSqlQuery(DB::db_);
    query.prepare("DELETE FROM Location where id = :id");
    query.bindValue(":id", id);
    bool result = query.exec();
    if(!result) {
        QSqlError error = query.lastError();
        qDebug() << error.text();
    }
    DB::db_.close();
    return result;
}

QList<Location> LocationDAO::getAll(){
    QList<Location> locations;
    DB::db_.open();
    QSqlQuery query = QSqlQuery(DB::db_);
    query.exec("SELECT * FROM Location");
    while(query.next()) {
        locations.append(Location(query.value("id").toInt(),query.value("client_id").toInt(), query.value("voiture_id").toInt(), query.value("date_debut").toString(), query.value("date_fin").toString()));
    }
    DB::db_.close();
    return locations;
}



Location LocationDAO::get(const int id){
    DB::db_.open();
    QSqlQuery query = QSqlQuery(DB::db_);
    query.prepare("SELECT * FROM Location WHERE id = :id");
    query.bindValue(":id", id);
    DB::db_.close();
    if(query.next()) {
        return Location(query.value("id").toInt(),query.value("client_id").toInt(), query.value("voiture_id").toInt(), query.value("date_debut").toString(), query.value("date_fin").toString());
    } else {
        DB::db_.close();
        return Location();
    }
}


QList<Location> LocationDAO::getVoitureFutureLocations(const Voiture& voiture){
    DB::db_.open();
    QList<Location> locations;
    QSqlQuery query = QSqlQuery(DB::db_);
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
    DB::db_.close();
    return locations;

}
