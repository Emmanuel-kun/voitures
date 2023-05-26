//
// Created by Administrateur on 25/05/2023.
//

#ifndef VOITURES_MAINWINDOW_H
#define VOITURES_MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include "vueclient.h"
#include "vuelocation.h"
#include "vuevoitures.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class mainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);

    ~mainWindow() override;

private:
    Ui::mainWindow *ui;
    QTabWidget *tabWidget;
    vueClient *pageClient;
    vueLocation *pageLocation;
    vueVoitures *pageVoiture;
    //ClientDAO * dao;
    void createContent();
};


#endif //VOITURES_MAINWINDOW_H
