//
// Created by Administrateur on 25/05/2023.
//

#ifndef VOITURES_VOITURE_H
#define VOITURES_VOITURE_H

#include <QString>

class Voiture {
public:
    Voiture(void);
    Voiture(const QString marque, const QString modele, const int anneeFabrication, const float prix);
    Voiture(const int id, const QString marque, const QString modele, const int anneeFabrication, const float prix);

    int id() const;
    void setId(const int id);
    QString marque() const;
    QString modele() const;
    int anneeFabrication() const;
    float prix() const;

private:
    int id_;
    QString marque_;
    QString modele_;
    int anneeFabrication_;
    float prix_;
};



#endif //VOITURES_VOITURE_H
