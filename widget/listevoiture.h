//
// Created by Administrateur on 26/05/2023.
//

#ifndef VOITURES_LISTEVOITURE_H
#define VOITURES_LISTEVOITURE_H

#include <QWidget>
#include <QTableWidget>
#include "../entity/Voiture.h"
#include "../dao/VoitureDAO.h"

QT_BEGIN_NAMESPACE
namespace Ui { class listeVoiture; }
QT_END_NAMESPACE

class listeVoiture : public QWidget {
Q_OBJECT

public:
    explicit listeVoiture(QWidget *parent = nullptr);
    ~listeVoiture() override;



private:
    Ui::listeVoiture *ui;
    QTableWidget *liste;
    void createContent();

public slots:
    void handleVoitureAdded(Voiture &voiture);
    //void handleVoitureDeleted();
};


#endif //VOITURES_LISTEVOITURE_H
