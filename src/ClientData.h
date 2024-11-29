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
        users = load();
    }

    map<string,User> getUsers(){
        return users;
    }

    int getNumberUsers(){
        return users.size();
    }

    map<string,User> load() {
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

    void add(User user) {
        users[user.getName()] = user;
        ofstream userFile;

        userFile.open("./BaseData/userData.csv", ios::app);

        if (!userFile) {
            cerr << "Error: No se pudo abrir el archivo userData.csv" << endl;
            return;
        }

        userFile << user.getIdUser() << "," << user.getName() << "," << user.getMail() << "," << user.getPassword() << endl;

        userFile.close();

        ofstream reservation;
        userFile.open("./BaseData/userReservation/" + to_string(user.getIdUser()) + ".csv", ios::app);

        if (!reservation) {
            cerr << "Error: No se pudo crear el archivo de reservas para " << user.getName() << endl;
            return;
        }

        reservation.close();
    }

    void addReservation(Flight flight, int idUser, int col, int row){
        ofstream userFile;


        userFile.open("./BaseData/userReservation/" + to_string(idUser) + ".csv", ios::app);

        if (!userFile) {
            cerr << "Error: No se pudo abrir el archivo" << endl;
            return;
        }

        userFile << flight.getFlightNumber() << "," << row << "," << col << ","<<flight.getPrice()<<endl;

        userFile.close();

    }
};
#endif