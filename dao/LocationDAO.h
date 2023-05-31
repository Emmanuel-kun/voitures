//
// Created by Administrateur on 25/05/2023.
//

#ifndef VOITURES_LOCATIONDAO_H
#define VOITURES_LOCATIONDAO_H
#include "BaseDAO.h"
#include "../entity/Location.h"
#include "../entity/Voiture.h"


class LocationDAO : public BaseDAO<Location> {

public:
    //LocationDAO(QSqlDatabase &db) : BaseDAO<Location>(db) {};
    LocationDAO();
    void init() const override;
    bool add(Location& location) override;
    bool remove(const int id) override;
    QList<Location> getAll() override;
    Location get(const int id) override;
    QList<Location> getVoitureFutureLocations(const Voiture& voiture);

};


#endif //VOITURES_LOCATIONDAO_H
