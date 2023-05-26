//
// Created by Administrateur on 25/05/2023.
//

#include "Client.h"

QString Client::getNom() const
{
    return this->nom;
}
QString Client::getPrenom() const
{
    return this->prenom;
}
QString Client::getMail() const
{
    return this->email;
}
int Client::getId() const
{
    return this->id;
}
void Client::setNom(QString nom)
{
    this->nom = nom;
}
void Client::setPrenom(QString prenom)
{
    this->prenom = prenom;
}
void Client::setMail(QString email)
{
    this->email = email;
}

void Client::setId(const int id)
{
    this->id = id;
}
