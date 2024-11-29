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
Añadir un nuevo usuario al sistema de reservación. +
Mostrar todos los vuelos. +
Buscar vuelos de aerolínea en una fecha específica. +
Elegir un vuelo con base en los detalles (precio, duración, tipo de asiento).
Mostrar todos los detalles del vuelo elegido. +
Contar los kilómetros acumulados de cada pasajero. Si tiene más de 50,000 km, entonces el sistema aplica descuento del 40% en el precio del vuelo.
Cancelar una reservación. 
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
        cout << "3. Elegir un vuelo basado en detalles (precio, duración, tipo de asiento)\n";
        cout << "4. Mostrar todos los detalles del vuelo elegido\n";
        cout << "5. Contar kilómetros acumulados de cada pasajero\n";
        cout << "6. Cancelar una reservación\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> option;
        cout<<endl;

        switch (option) {
            case 1:
                aplication.mostrarVuelos();
                break;
            case 2:
                cout << "Buscar vuelos por aerolínea y fecha específica seleccionada.\n";
                aplication.dateAndAirlineFilter();
                break;
            case 3:
                cout << "Opción 3: Elegir un vuelo basado en detalles seleccionada.\n";
                // Aquí llamas a la función correspondiente
                break;
            case 4:
                cout << "Opción 4: Mostrar todos los detalles del vuelo elegido seleccionada.\n";
                // Aquí llamas a la función correspondiente
                break;
            case 5:
                cout << "Opción 5: Contar kilómetros acumulados de cada pasajero seleccionada.\n";
                // Aquí llamas a la función correspondiente
                break;
            case 6:
                cout << "Opción 6: Cancelar una reservación seleccionada.\n";
                // Aquí llamas a la función correspondiente
                break;
            case 7:
                regresar = 'N';
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }
        
        if(option!=7){
            cout<<"¿Deseas regresar al ménu del usuario?(S/N)";
            cin>>regresar;
        }

    } while (option != 7 && toupper(regresar) == 'S');

    cout << "Saliendo del sistema...\n";

    return 0;
}
