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
    //VoitureDAO(QSqlDatabase &db) : BaseDAO<Voiture>(db) {};
    VoitureDAO();
    void init() const override;
    bool add(Voiture& voiture) override;
    bool remove(const int id) override;
    QList<Voiture> getAll() override;
    Voiture get(const int id) override;
};


#endif //VOITURES_VOITUREDAO_H
