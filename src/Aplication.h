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

public:

    Aplication(){
        flights = flightsData.load();
        flightsData.setFlights(flights);
        client = accountLogin();
    }

    User getClient(){
        reservations = reservationsData.load(client.getIdUser());
        cout<<reservations.size();
        return client;
    }

    void clear(){
        #ifdef _WIN32
                    system("cls"); 
            #else
                        system("clear"); 
                #endif
    }

    User logIn() {
        map<string,User> users = usersData.getUsers();

        clear();
        string username, password;
        cout << "\n------------------Inicio de sección------------------" << endl;
        cout << "Ingrese su nombre de usuario: ";
        cin >> username;
        cout << "Ingrese su contrasena: ";
        cin >> password;

        return usersData.authenticateUser(username, password);
    }

    User createAccount() {
        clear();
        string newUsername, newPassword, newEmail;

        cout << "\n------------------Crear cuenta------------------" << endl;
        cout << "Ingrese un nuevo nombre de usuario: ";
        cin >> newUsername;
        cout << "Ingresa un nuevo correo: ";
        cin >> newEmail;
        cout << "Ingrese una nueva contrasena: ";
        cin >> newPassword;

        User newUs(usersData.getNumberUsers(), newUsername, newEmail, newPassword);

        if(usersData.exist(newUs)){
            cout<<"Este usuario ya fue creado, elige otro nombre de usuario"<<endl;
            return User();
        } 

        usersData.add(newUs);
        
        cout << "Cuenta creada exitosamente.\n";
        
        return newUs;
    }

    User accountLogin(){
        clear();

        int opc;

        cout << "Bienvenido, a ViajandoAndo!!!" << endl;
        cout << "------------------------------" << endl;
        cout << "1. Iniciar sesión" << endl;
        cout << "2. Crear cuenta" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opc;

        if(opc == 1){
            return logIn();

        }else if(opc == 2){
            User newUser = createAccount();
            return newUser;
        }else if(opc == 3){
            cout<<"Saliste del programa"<<endl;
            return User();
        }else{
            cout << "Opción no válida, intente de nuevo.\n";
            return User();
        }
    }

    void reserva() {
        int selectedFlight;
        cout << "\nSelecciona el vuelo que quieras ver a detalle: ";
        cin >> selectedFlight;

        Flight& selected = flights[selectedFlight];

        clear();
        cout << selected.toString() << endl;
        selected.printAvailability();

        cout << "¿Quieres reservar? (S/N): ";
        char reserve; 
        cin >> reserve; 
        cout << endl;

        if (toupper(reserve) != 'S') return;

        int col; 
        char letter;

        cout << "Selecciona la columna (1-30): "; 
        cin >> col;
        cout << "Selecciona A/B/C/D/E/F/G: "; 
        cin >> letter;

        if (selected.available(col - 1, letter - 'A')) {
            usersData.addReservation(selected, client.getIdUser(), col - 1, letter - 'A');
            flightsData.setFlights(flights);
            reservations[selectedFlight] = Reservation(selectedFlight, col - 1, letter - 'A', selected.getPrice());
            cout << "Reservación completada\n" << endl;
        }
    }

    void showFlights() {
        clear();
        
        cout << "------------------Vuelos disponibles------------------\n" << endl;

        for (map<int, Flight>::const_iterator it = flights.begin(); it != flights.end(); ++it)
            cout << it->second.toString() << endl;

        reserva();
    }



    void dateAndAirlineFilter(){
        clear();
        string airline;
        int day, month, year;

        cout<<"---------------Filtrar por aerolinea y fecha---------------------"<<endl;

        cout << "Introduce la aerolínea: "; cin >> airline;

        cout << "Introduce el día (1-31): "; cin >> day;
        cout << "Introduce el mes (1-12): "; cin >> month;
        cout << "Introduce el año: "; cin >> year;

        cout<<endl;

        vector<Flight> filteredFlights = flightsData.dateAndAirlineFilter(airline, day, month, year);

        if (filteredFlights.empty()) {
            cout << "No se encontraron vuelos para la aerolínea y la fecha proporcionadas." << endl;
            return;
        }
        
        cout << "Vuelos encontrados:" << endl;
        for (Flight flight : filteredFlights) cout << flight.toString() << endl;

    }

    void showReservations() {
        clear();
        cout << "-------Tus reservas---------------" << endl;

        // Mostrar las reservas existentes
        for (map<int, Reservation>::const_iterator it = reservations.begin(); it != reservations.end(); ++it)
            cout << it->second.toString() << endl;

        // Si no hay reservas, mostramos un mensaje y salimos
        if (reservations.size() == 0) {
            cout << "No hay reservaciones\n" << endl;
            return;
        }

        // Preguntar si el usuario desea cancelar una reserva
        char confirm;
        cout << "¿Deseas cancelar alguna reserva? (S/N): ";
        cin >> confirm;

        if (toupper(confirm) == 'S') {
            int canceledIdFlight;
            // Solicitar al usuario el ID del vuelo que desea cancelar
            cout << "¿Para qué vuelo (ID del vuelo) quieres cancelar la reserva? ";
            cin >> canceledIdFlight;

            // Verificar si la reserva existe y eliminarla
            if (reservations.erase(canceledIdFlight)) {
                reservationsData.setReservations(reservations);
                reservationsData.update(client.getIdUser());
                cout << "Reserva cancelada exitosamente." << endl;
            } else {
                cout << "Error: No se encontró la reserva para el vuelo " << canceledIdFlight << ".\n" << endl;
            }
        } else {
            cout << "No se ha cancelado ninguna reserva." << endl;
        }
    }


};

#endif