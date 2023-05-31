//
// Created by Administrateur on 25/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainWindow.h"
#include "../dao/BaseDAO.h"
#include "../dao/db.h"
#include <QDir>


mainWindow::mainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::mainWindow) {
    ui->setupUi(this);
    this->resize(600,600);
    //db_ = new QSqlDatabase();
    DB::dbInit();
    //BaseDAO<Voiture>::dbInit();

    createContent();
}

mainWindow::~mainWindow() {
    delete ui;
}


void mainWindow::createContent() {
    tabWidget = new QTabWidget(this);
    pageClient = new vueClient(this);
    pageLocation = new vueLocation(this);
    pageVoiture = new vueVoitures(this);

    tabWidget->addTab(pageClient, "Clients");
    tabWidget->addTab(pageVoiture, "Voitures");
    tabWidget->addTab(pageLocation, "Locations");
    setCentralWidget(tabWidget);

}