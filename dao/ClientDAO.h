//
// Created by Administrateur on 25/05/2023.
//

#ifndef VOITURES_CLIENTDAO_H
#define VOITURES_CLIENTDAO_H

#include "BaseDAO.h"
#include "../entity/Client.h"

class ClientDAO : public BaseDAO<Client>{

public:
    ClientDAO(QSqlDatabase &db):BaseDAO<Client>(db) {};
    void init() const;
    bool add(Client& contact);
    bool remove(const int id);
    QList<Client> getAll();
    Client get(const int id);
};


#endif //VOITURES_CLIENTDAO_H
