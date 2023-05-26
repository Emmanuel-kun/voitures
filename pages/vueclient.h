            //
// Created by Administrateur on 25/05/2023.
//

#ifndef VOITURES_VUECLIENT_H
#define VOITURES_VUECLIENT_H

#include <QWidget>


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
};


#endif //VOITURES_VUECLIENT_H
