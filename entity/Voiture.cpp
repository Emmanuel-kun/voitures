//
// Created by Administrateur on 25/05/2023.
//

#include "Voiture.h"

Voiture::Voiture(const QString marque, const QString modele, const int anneeFabrication, const float prix): marque_(marque),modele_(modele), anneeFabrication_(anneeFabrication),prix_(prix) {};
Voiture::Voiture(const int id, const QString marque, const QString modele, const int anneeFabrication, const float prix): id_(id), marque_(marque),modele_(modele), anneeFabrication_(anneeFabrication),prix_(prix) {};
int Voiture::id() const{return id_;};
void Voiture::setId(const int id){id_=id;};

QString Voiture::marque() const {return marque_;};
QString Voiture::modele() const {return modele_;};
int Voiture::anneeFabrication() const {return anneeFabrication_;};
float Voiture::prix() const {return prix_;};