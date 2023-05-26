//
// Created by Administrateur on 25/05/2023.
//

#include "Location.h"

Location::Location(const int client_id, const int voiture_id, const QString date_debut, const QString date_fin): client_id_(client_id),voiture_id_(voiture_id), date_debut_(date_debut),date_fin_(date_fin) {};
Location::Location(const int id, const int client_id, const int voiture_id, const QString date_debut, const QString date_fin): id_(id), client_id_(client_id),voiture_id_(voiture_id), date_debut_(date_debut),date_fin_(date_fin) {};
void Location::setId(int id) {id_ = id;};
int Location::client_id() const {return client_id_;};
int Location::voiture_id() const {return voiture_id_;};
QString Location::date_debut() const {return date_debut_;};
QString Location::date_fin() const {return date_fin_;};