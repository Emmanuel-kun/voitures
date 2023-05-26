//
// Created by ihab on 17/05/2023.
//

#ifndef ANNUAIREDAO_BASEDAO_H
#define ANNUAIREDAO_BASEDAO_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

template <typename T>
class BaseDAO {

public:
    BaseDAO(QSqlDatabase &db) : db_(db) {};
    virtual ~BaseDAO() = default;

    virtual void init() const = 0;
    virtual bool add(T& contact) = 0;
    virtual bool remove(const int id) = 0;
    virtual QList<T> getAll() = 0;
    virtual T get(const int id) = 0;


protected:
    QSqlDatabase& db_;
};


#endif //ANNUAIREDAO_BASEDAO_H
