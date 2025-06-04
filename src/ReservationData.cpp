#include "ReservationData.h"

ReservationData::ReservationData() {
    idUser = -1;
}

// Setter de las reservas
void ReservationData::setReservations(map<int, Reservation> _reservations) {
    reservations = _reservations;
}

// Setter para el idUser
void ReservationData::setIdUser(int id) {
    idUser = id;
}

// Getter para las reservas
map<int, Reservation> ReservationData::getReservations() {
    load();
    return reservations;
}

// Método para cargar las reservas desde un archivo CSV
void ReservationData::load() {
    ifstream file("./BaseData/userReservation/" + to_string(idUser) + ".csv");
    if (!file) {
        cerr << "Error: No se pudo abrir el archivo" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int idFlight, rowSeat, colSeat;
        float price;
        string temp;

        // Leer datos de cada línea
        if (getline(ss, temp, ',') && 
            (idFlight = stoi(temp), true) &&           
            getline(ss, temp, ',') && 
            (rowSeat = stoi(temp), true) &&            
            getline(ss, temp, ',') && 
            (colSeat = stoi(temp), true) &&            
            getline(ss, temp)) {                       
            price = stof(temp);  // Convertir precio

            // Almacenar la reserva en el mapa
            reservations[idFlight] = Reservation(idFlight, rowSeat, colSeat, price);
        } else {
            cerr << "Error: Línea malformada: " << line << endl;
        }
    }

    file.close();
}

// Método para actualizar el archivo con las reservas actuales
void ReservationData::update() {
    ofstream file("./BaseData/userReservation/" + to_string(idUser) + ".csv");
    if (!file) {
        cerr << "Error: No se pudo abrir el archivo" << endl;
        return;
    }

    // Escribir los datos de las reservas en el archivo
    for (auto& entry : reservations) {
        int flightNumber = entry.first;
        Reservation reservation = entry.second;  

        float price = reservation.getPrice();
        int rowSeat = reservation.getRowSeat();
        int colSeat = reservation.getColSeat();
    
        file << flightNumber << ","
             << rowSeat << ","
             << colSeat << ","
             << price << "\n";
    }

    file.close();
}
