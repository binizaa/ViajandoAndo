#ifndef APLICATION_H
#define APLICATION_H

#include <string>
#include <map>

#include "ClientData.h"
#include "User.h"
#include "FlightData.h"
#include "ReservationData.h"

class Aplication{
private:
    FlightData flightsData;
    ClientData usersData;
    ReservationData reservationsData;
    map<int, Flight> flights;
    map<int,Reservation> reservations;
    User client;

    User accountLogin();
    User logIn();
    User createAccount();

public:

    Aplication();

    void clear();

    User getClient();

    void reserva();

    void showFlights();

    void dateAndAirlineFilter();

    void showReservations();

};

#endif // APLICATION_H