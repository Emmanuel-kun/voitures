//
// Created by Administrateur on 25/05/2023.
//

#ifndef VOITURES_CLIENTDAO_H
#define VOITURES_CLIENTDAO_H

#include "BaseDAO.h"
#include "../entity/Client.h"

class ClientDAO : public BaseDAO<Client>{

public:
    //ClientDAO(QSqlDatabase &db):BaseDAO<Client>(db) {};
    ClientDAO();
    void init() const override;
    bool add(Client& contact) override;
    bool remove(const int id) override;
    QList<Client> getAll() override;
    Client get(const int id) override;
};


#endif //VOITURES_CLIENTDAO_H
