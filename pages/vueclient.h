            //
// Created by Administrateur on 25/05/2023.
//

#ifndef VOITURES_VUECLIENT_H
#define VOITURES_VUECLIENT_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "../dao/ClientDAO.h"

#include "../widget/listeclient.h"



QT_BEGIN_NAMESPACE
namespace Ui { class vueClient; }
QT_END_NAMESPACE

class vueClient : public QWidget {
Q_OBJECT

public:
    explicit vueClient(QWidget *parent = nullptr);

    ~vueClient() override;
    void createContent();

private:
    Ui::vueClient *ui;
    listeClient * listeCli;
    QGridLayout * gridLayout;
    QLabel * labelNom;
    QLabel * labelPrenom;
    QLabel * labelEmail;
    QLineEdit * textNom;
    QLineEdit * textPrenom;
    QLineEdit * textEmail;

    QPushButton * addButton;
    QPushButton * deleteButton;
private slots:
    void handleClientAdded();

};


#endif //VOITURES_VUECLIENT_H
