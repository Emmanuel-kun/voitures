//
// Created by Administrateur on 25/05/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainWindow.h"


mainWindow::mainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::mainWindow) {
    ui->setupUi(this);
    createContent();
}

mainWindow::~mainWindow() {
    delete ui;
}


void mainWindow::createContent() {
    tabWidget = new QTabWidget(this);
    pageClient = new vueClient();
    pageLocation = new vueLocation();
    pageVoiture = new vueVoitures();

    tabWidget->addTab(pageVoiture, "Voitures");
    tabWidget->addTab(pageClient, "Clients");
    tabWidget->addTab(pageLocation, "Locations");
    setCentralWidget(tabWidget);

}