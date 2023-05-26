//
// Created by Administrateur on 25/05/2023.
//

#ifndef VOITURES_LOCATION_H
#define VOITURES_LOCATION_H
#include <QString>

class Location {
public:
    Location(void) = default;
    Location(const int client_id, const int voiture_id, const QString date_debut, const QString date_fin);
    Location(const int id_, const int client_id, const int voiture_id, const QString date_debut, const QString date_fin);
    void setId(int id);
    int client_id() const;
    int voiture_id() const;
    QString date_debut() const;
    QString date_fin() const;

private:
    int id_;
    int client_id_;
    int voiture_id_;
    QString date_debut_;
    QString date_fin_;
};


#endif //VOITURES_LOCATION_H
