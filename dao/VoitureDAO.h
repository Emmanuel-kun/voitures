//
// Created by Administrateur on 25/05/2023.
//

#ifndef VOITURES_VOITUREDAO_H
#define VOITURES_VOITUREDAO_H

#include "BaseDAO.h"
#include "../entity/Voiture.h"
#include "../entity/Location.h"
#include <QSqlDatabase>


class VoitureDAO : public BaseDAO<Voiture>{
public:
    VoitureDAO(QSqlDatabase &db) : BaseDAO<Voiture>(db) {};
    void init() const;
    bool add(Voiture& voiture);
    bool remove(const int id);
    QList<Voiture> getAll();
    Voiture get(const int id);
};


#endif //VOITURES_VOITUREDAO_H
