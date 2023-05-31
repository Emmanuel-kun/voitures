//
// Created by Administrateur on 31/05/2023.
//

#ifndef VOITURES_DB_H
#define VOITURES_DB_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QApplication>
#include <QDir>
#include <QDebug>


class DB {
public:
    static QSqlDatabase db_;

    static void dbInit(){
        QString dataFolderPath = QApplication::applicationDirPath() + "/data";
        QDir().mkpath(dataFolderPath);

        db_ = QSqlDatabase::addDatabase("QSQLITE");
        qDebug() << "dans db.h : " << db_;
        qDebug() << QSqlDatabase::drivers();
        db_.setDatabaseName(dataFolderPath + "/mydatabase.db");
    }
};


#endif //VOITURES_DB_H

