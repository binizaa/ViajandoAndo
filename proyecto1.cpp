#include <string>
#include <vector>
#include <iostream>
#include "Vuelo.h"
#include "Reservation.h"
#include "User.h"

using namespace std;

int main() {
    // Crear un ejemplo de Vuelo
    Vuelo vuelo;
    vuelo.setFlightNumber(101);
    vuelo.setAirline("Air Mexico");
    vuelo.setPrice(199.99);
    vuelo.setDuration(2.5);

    // Inicializar la fecha manualmente
    vector<int> date;
    date.push_back(2024);
    date.push_back(12);
    date.push_back(25);
    vuelo.setDate(date);

    // Crear una Reservación
    Reservation reserva;
    reserva.setIdReserva(1);
    reserva.setVuelo(vuelo);
    reserva.setPrice(vuelo.getPrice());

    // Crear un Usuario
    User usuario;
    usuario.setIdUser(1);
    usuario.setName("Juan Pérez");
    usuario.setMail("juan@example.com");

    // Inicializar reservaciones manualmente
    vector<Reservation> reservations;
    reservations.push_back(reserva);
    usuario.setReservations(reservations);

    // Imprimir usando toString()
    cout << vuelo.toString() << endl;
    cout << reserva.toString() << endl;
    cout << usuario.toString() << endl;

    return 0;
}
