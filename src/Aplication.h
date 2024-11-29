#ifndef APLICATION_H
#define APLICATION_H

#include <string>
#include <map>

#include "ClientData.h"
#include "User.h"
#include "FlightData.h"

class Aplication{
private:
    FlightData flightsData;
    ClientData usersData;
    map<int, Flight> flights;
    User client;

public:

    Aplication(){
        flights = flightsData.loadFlightData();
        flightsData.setFlights(flights);
        client = accountLogin();
    }

    User getClient(){
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

        User us(username, password);
        return us.authenticateUser(users);
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

        usersData.createUser(newUs);
        
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
            this_thread::sleep_for(chrono::seconds(1));
            return accountLogin();
        }
    }

    void reserva(){

        int selectedFlight;
        cout<<"\nSelecciona el vuelo que quieras ver a detalle: ";
        cin>>selectedFlight;

        Flight& selected = flights[selectedFlight];

        clear();
        cout<<selected.toString()<<endl;
        selected.printAvailability();

        cout<<"¿Quieres reservar? (S/N): ";
        char reservar; cin>>reservar; cout<<endl;

        if(toupper(reservar) != 'S') return;

        int col; char letter;

        cout<<"Selecciona la columna (1-30): "; cin>>col;
        cout<<"Selecciona A/B/C/D/E/F/G: "; cin>>letter;

        if(selected.disponible(col - 1, letter - 'A')){
            usersData.reserva(selectedFlight, client.getIdUser(), col - 1, letter - 'A');
            flightsData.setFlights(flights);
            //flightsData.update();
            cout<<"Reservación completada"<<endl;
        }
    }

    void mostrarVuelos(){
        clear();
        
        cout << "------------------Vuelos disponibles------------------\n" << endl;

        for (map<int, Flight>::const_iterator it = flights.begin(); it != flights.end(); ++it) {
            cout << it->second.toString() << endl;
        }

        reserva();
    }

    void dateAndAirlineFilter(){
        clear();
        string airline;
        int day, month, year;

        cout << "Introduce la aerolínea: ";
        cin >> airline;

        cout << "Introduce el día (1-31): ";
        cin >> day;

        cout << "Introduce el mes (1-12): ";
        cin >> month;

        cout << "Introduce el año: ";
        cin >> year;

        vector<Flight> filteredFlights = flightsData.dateAndAirlineFilter(airline, day, month, year);

        // Mostrar los resultados filtrados
        if (filteredFlights.empty()) {
            cout << "No se encontraron vuelos para la aerolínea y la fecha proporcionadas." << endl;
        } else {
            cout << "Vuelos encontrados:" << endl;
            for (const Flight& flight : filteredFlights) {
                cout << flight.toString() << endl;
            }
        }

        reserva();
    }
};

#endif