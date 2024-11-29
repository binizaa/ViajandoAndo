#include <string>
#include <vector>
#include <iostream>
#include <cstdlib> 
#include <sstream>
#include <cctype>
#include <thread>
#include <map>
#include "./src/Flight.h"
#include "./src/Reservation.h"
#include "./src/Aplication.h"
#include "./src/User.h"

using namespace std;

/*
Puntos realizados
Añadir un nuevo usuario al sistema de reservación. +
Mostrar todos los vuelos. +
Buscar vuelos de aerolínea en una fecha específica. +
Mostrar todos los detalles del vuelo elegido. +
Cancelar una reservación. +
*/
int main() {

    Aplication aplication;
    
    User user = aplication.getClient();

    if(!user.getIsValid()) return 0;
    
    int option;
    char regresar = 'N';

    do {
        aplication.clear();
        
        cout<<"Bienvenido al ViajandoAndo "<<user.getName()<<endl;
        cout << "\n--- Menú de Vuelos ---\n";
        cout << "1. Mostrar todos los vuelos\n";
        cout << "2. Buscar vuelos por aerolínea y fecha específica\n";
        cout << "3. Ver tus reservaciones\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> option;
        cout<<endl;

        switch (option) {
            case 1:
                aplication.showFlights();
                break;
            case 2:
                aplication.dateAndAirlineFilter();
                break;
            case 3:
                aplication.showReservations();
                break;
            case 4:
                regresar = 'N';
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
                regresar = 'N';
        }
        
        if(option!=7){
            cout<<"¿Deseas regresar al ménu del usuario?(S/N): ";
            cin>>regresar;
            cout<<endl;
        }

    } while (option != 7 && toupper(regresar) == 'S');

    cout << "Saliendo del sistema...\n";

    return 0;
}
