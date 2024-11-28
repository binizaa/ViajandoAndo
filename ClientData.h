#ifndef CLIENTEDATA_H
#define CLIENTEDATA_H

#include<map>
#include <string>

#include "User.h"

class ClientData{
public:
    map<string,User> loadDataBase() {
        map<string,User> users;

        ifstream file("userData.csv");
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
};
#endif