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
    map<string,User> users;

public:

    Aplication(){
        flights = flightsData.loadFlightData();
        users = usersData.loadDataBase();
    }

    void clear(){
        #ifdef _WIN32
                    system("cls"); 
            #else
                        system("clear"); 
                #endif
    }

    User logIn() {
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

    User createAccount(int newId) {
        clear();
        string newUsername, newPassword, newEmail;

        cout << "\n------------------Crear cuenta------------------" << endl;
        cout << "Ingrese un nuevo nombre de usuario: ";
        cin >> newUsername;
        cout << "Ingresa un nuevo correo: ";
        cin >> newEmail;
        cout << "Ingrese una nueva contrasena: ";
        cin >> newPassword;

        User newUs(newId, newUsername, newEmail, newPassword);

        if(newUs.exist(users)){
            cout<<"Este usuario ya fue creado, elige otro nombre de usuario"<<endl;
            return User();
        } 

        newUs.createUser();
        
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
            User newUser = createAccount(users.size() + 1);
            users[newUser.getName()] = newUser;
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

    void mostrarVuelos(){
        clear();
        
        cout << "------------------Vuelos disponibles------------------\n" << endl;

        for (map<int, Flight>::const_iterator it = flights.begin(); it != flights.end(); ++it) {
            cout << it->second.toString() << endl;
        }

        int selectedFlight;
        cout<<"\nSelecciona el vuelo que quieras ver a detalle: "<<endl;
        cin>>selectedFlight;

        Flight selected = flights[selectedFlight];
        
        clear();
        cout<<selected.toString()<<endl;
        selected.printAvailability();
        
    }
};

#endif