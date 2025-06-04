#ifndef RESERVATIONDATA_H
#define RESERVATIONDATA_H

#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

#include "DataBase.h"
#include "Reservation.h"  

using namespace std;

class ReservationData : public DataBase {
private:
    map<int, Reservation> reservations;
    int idUser;

public:
    // Constructor
    ReservationData();

    void setReservations(map<int, Reservation> _reservations);
    void setIdUser(int id);
    map<int, Reservation> getReservations(); 

    // Métodos para cargar y actualizar las reservas
    void load() override;
    void update() override;
};

#endif // RESERVATIONDATA_H
