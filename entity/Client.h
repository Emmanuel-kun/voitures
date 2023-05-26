//
// Created by Administrateur on 25/05/2023.
//

#ifndef VOITURES_CLIENT_H
#define VOITURES_CLIENT_H
#include <QString>

class Client {

private:
    int id;
    QString nom;
    QString prenom;
    QString email;
public:
    Client(void)=default;
    Client(const QString _nom, const QString _prenom, const QString _email): nom(_nom), prenom(_prenom), email(_email){};
    Client(const int _id, const QString _nom, const QString _prenom, const QString _email): id(_id), nom(_nom), prenom(_prenom), email(_email){};

    QString getNom() const;
    QString getPrenom() const;
    QString getMail() const;
    int getId() const;
    void setNom(QString nom);
    void setPrenom(QString prenom);
    void setMail(QString email);
    void setId(const int id);

};


#endif //VOITURES_CLIENT_H
