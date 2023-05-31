//
// Created by ihab on 17/05/2023.
//

#ifndef ANNUAIREDAO_BASEDAO_H
#define ANNUAIREDAO_BASEDAO_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QApplication>
#include <QDir>
#include "./db.h"

template <typename T>
class BaseDAO {
public:
    //BaseDAO(QSqlDatabase &db) : db_(db) {};
    //static QSqlDatabase& db_;
    //BaseDAO();
    virtual ~BaseDAO() = default;

    virtual void init() const = 0;
    virtual bool add(T& contact) = 0;
    virtual bool remove(const int id) = 0;
    virtual QList<T> getAll() = 0;
    virtual T get(const int id) = 0;
    /*static void dbInit(){
            QString dataFolderPath = QApplication::applicationDirPath() + "/data";
            QDir().mkpath(dataFolderPath);
            db_ = QSqlDatabase::addDatabase("QSQLITE");
            db_.setDatabaseName(dataFolderPath + "/mydatabase.db");

        }*/

};



#endif //ANNUAIREDAO_BASEDAO_H
