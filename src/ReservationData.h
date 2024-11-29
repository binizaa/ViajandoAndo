#ifndef RESERVATIONDATA_H
#define RESERVATIONDATA_H

#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "Reservation.h"  

using namespace std;

class ReservationData {
private:
    map<int, Reservation> reservations;

public:
    ReservationData() {}

    // Constructor público para permitir la creación de objetos
    ReservationData(int idUser) {
        reservations = load(idUser);
    }

    void setReservations(map<int,Reservation> _reservations){
        reservations = _reservations;
    }

    map<int, Reservation> load(int idUser) {
        map<int, Reservation> reservations;

        // Ruta al archivo con las reservas del usuario
        ifstream file("./BaseData/userReservation/" + to_string(idUser) + ".csv");
        if (!file) {
            cerr << "Error: No se pudo abrir el archivo" << endl;
            return reservations;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            int idFlight, rowSeat, colSeat;
            float price;
            string temp;

            if (getline(ss, temp, ',') && 
                (idFlight = stoi(temp), true) &&           
                getline(ss, temp, ',') && 
                (rowSeat = stoi(temp), true) &&            
                getline(ss, temp, ',') && 
                (colSeat = stoi(temp), true) &&            
                getline(ss, temp)) {                       
                price = stof(temp);                        

                reservations[idFlight] = Reservation(idFlight, rowSeat, colSeat, price);
            } else {
                cerr << "Error: Línea malformada: " << line << endl;
            }
        }

        file.close();
        return reservations;
    }

    // Método para obtener las reservas (si es necesario)
    map<int, Reservation> getReservations() {
        return reservations;
    }

    void update(int idUser){
        ofstream file("./BaseData/userReservation/" + to_string(idUser) + ".csv");
        if (!file) {
            cerr << "Error: No se pudo abrir el archivo" << endl;
            return;
        }

        for (map<int, Reservation>::iterator it = reservations.begin(); it != reservations.end(); ++it) {
            int flightNumber = it->first;
            Reservation reservation = it->second;  

            float price = reservation.getPrice();
            int rowSeat = reservation.getRowSeat();
            int colSeat = reservation.getColSeat();
        
            file << flightNumber << ","
                 << rowSeat << ","
                 << colSeat << ","
                 << price << "\n";
        }
    }

};

#endif
