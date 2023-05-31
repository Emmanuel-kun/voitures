//
// Created by Administrateur on 26/05/2023.
//

#ifndef VOITURES_LISTECLIENT_H
#define VOITURES_LISTECLIENT_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include "../entity/Client.h"
//#include "../pages/mainwindow.h"

class mainWindow;
QT_BEGIN_NAMESPACE
namespace Ui { class listeClient; }
QT_END_NAMESPACE

class listeClient : public QWidget {
Q_OBJECT

public:
    explicit listeClient(QWidget *parent = nullptr);

    ~listeClient() override;
    void createContent();
    class DeleteButton:public QPushButton{
    private :
        int id;

    public:
        DeleteButton(int client, QWidget *parent = nullptr);
        void hitButton(const QPoint & pos);

    };

private:
    Ui::listeClient *ui;
    QTableWidget * liste;
public:
    void refreshList();
};


#endif //VOITURES_LISTECLIENT_H
