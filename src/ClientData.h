#ifndef CLIENTEDATA_H
#define CLIENTEDATA_H

#include<map>
#include <string>

#include "User.h"

class ClientData{
private:
    map<string,User> users;
    int numberUsers;

public:
    ClientData(){
        users = loadDataBase();
    }

    map<string,User> getUsers(){
        return users;
    }

    int getNumberUsers(){
        return users.size();
    }

    map<string,User> loadDataBase() {
        map<string,User> users;

        ifstream file("./BaseData/userData.csv");
        if (!file) {
            cerr << "Error: No se pudo abrir el archivo userData.csv" << endl;
            return users; 
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string id_str, name, email, password;

            if (getline(ss, id_str, ',') && getline(ss, name, ',') && 
                getline(ss, email, ',') && getline(ss, password, ',')) {
                int id = stoi(id_str); 
                users[name] = User(id, name, email, password);
            } else {
                cerr << "Error: Línea malformada: " << line << endl;
            }
        }

        file.close();

        return users;
    }

    bool exist(User user){
        return users.find(user.getName()) != users.end();
    }

    void createUser(User user) {
        users[user.getName()] = user;
        ofstream userFile;

        userFile.open("./BaseData/userData.csv", ios::app);

        if (!userFile) {
            cerr << "Error: No se pudo abrir el archivo userData.csv" << endl;
            return;
        }

        userFile << user.getIdUser() << "," << user.getName() << "," << user.getMail() << "," << user.getPassword() << endl;

        userFile.close();

        //Crear el simulador de revervaciones

        ofstream reservation("./userReservations/" + to_string(user.getIdUser()) + ".csv");

        if (!reservation) {
            cerr << "Error: No se pudo crear el archivo de reservas para " << user.getName() << endl;
            return;
        }

        reservation.close();
    }
};
#endif