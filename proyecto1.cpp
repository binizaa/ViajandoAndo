#include <string>
#include <vector>
#include <iostream>
#include <cstdlib> 
#include <sstream>
#include <cctype>
#include <thread>
#include <map>
#include "Flight.h"
#include "Reservation.h"
#include "User.h"

using namespace std;

void clear(){
    #ifdef _WIN32
                system("cls"); 
        #else
                    system("clear"); 
            #endif
}

User logIn(map<string,User> users) {
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

User createAccount(int newId, map<string,User> users) {
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

User accountLogin(map<string, User>& userData){
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
        return logIn(userData);

    }else if(opc == 2){
        User newUser = createAccount(userData.size() + 1, userData);
        userData[newUser.getName()] = newUser;
        return newUser;
    }else if(opc == 3){
        cout<<"Saliste del programa"<<endl;
        return User();
    }else{
        cout << "Opción no válida, intente de nuevo.\n";
        this_thread::sleep_for(chrono::seconds(1));
        return accountLogin(userData);
    }
}

void mostrarVuelos(map<int,Flight> flights){
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

map<string,User> loadDataBase() {
    map<string,User> users;

    ifstream file("userData.csv");
    if (!file) {
        cerr << "Error: No se pudo abrir el archivo userData.csv" << endl;
        return users; // Devuelve un vector vacío si el archivo no se abre.
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id_str, name, email, password;

        if (getline(ss, id_str, ',') && getline(ss, name, ',') && 
            getline(ss, email, ',') && getline(ss, password, ',')) {
            int id = stoi(id_str); 
            users[name] = User(id, name, email, password);
        } else {
            cerr << "Error: Línea malformada: " << line << endl;
        }
    }

    file.close();

    return users;
}

vector<int> dateFormat(string dateStr) {
    vector<int> date(3);
    stringstream dateStream(dateStr);
    string year, month, day;

    if (getline(dateStream, year, '-') &&
        getline(dateStream, month, '-') &&
        getline(dateStream, day)) {
        date[0] = stoi(day);   // Día
        date[1] = stoi(month); // Mes
        date[2] = stoi(year);  // Año
    }

    return date;
}

vector<string> separateAvailability(string line) {
    vector<string> seatLines;
    stringstream ss(line);  
    string seatLine;
    
    for (int i = 0; i < 6; ++i) {
        if (getline(ss, seatLine, ',')) {  
            seatLines.push_back(seatLine);  // Agregar al vector
        } else {
            cerr << "Error: Se esperaba más datos para las líneas de disponibilidad." << endl;
            break;  
        }
    }
    
    return seatLines;
}

vector<vector<bool> > availabilityFormat(const vector<string>& seatLines) {
    vector<vector<bool> > seatAvailability(6, vector<bool>(30, false));  

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 30; ++j) {
            seatAvailability[i][j] = (seatLines[i][j] == '.');
        }
    }

    return seatAvailability;
}


map<int, Flight> loadFlightData() {
    map<int, Flight> flights;

    ifstream file("flightData.csv");
    if (!file) {
        cerr << "Error: No se pudo abrir el archivo flightData.csv" << endl;
        return flights;
    }

    string line;
    getline(file, line); 

    while (getline(file, line)) {
        stringstream ss(line);
        string flightNumberStr, airline, priceStr, durationStr, dateStr, origin, destination, avality;

        if (getline(ss, flightNumberStr, ',') &&
            getline(ss, airline, ',') &&
            getline(ss, priceStr, ',') &&
            getline(ss, durationStr, ',') &&
            getline(ss, dateStr, ',') &&
            getline(ss, origin, ',') &&
            getline(ss, destination, ',') &&
            getline(ss, line)) {

            int flightNumber = stoi(flightNumberStr);
            float price = stof(priceStr);
            float duration = stof(durationStr);

            // Dividir la fecha en partes: YYYY-MM-DD
            vector<int> date = dateFormat(dateStr);
            //cout<<date[0]<<" "<<date[1]<<" "<<date[2]<<endl;

            vector<string> availity = separateAvailability(line);

            flights[flightNumber] = Flight(flightNumber, airline, price, duration, date, origin, destination, availity);
        } else {
            cerr << "Error: Línea malformada: " << line << endl;
        }
    }

    file.close();

    return flights;
}

int main() {
    map<int, Flight> flightData = loadFlightData();
    map<string,User> userData = loadDataBase();
    
    User user = accountLogin(userData);

    if(!user.getIsValid()) return 0;
    
    int option;
    char regresar = 'N';
    do {
        clear();
        
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
                mostrarVuelos(flightData);
                break;
            case 2:
                cout << "Opción 2: Buscar vuelos por aerolínea y fecha específica seleccionada.\n";
                // Aquí llamas a la función correspondiente
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
        
        if(toupper(option)!=7){
            cout<<"¿Deseas regresar al ménu del usuario?(S/N)"<<endl;
            cin>>regresar;
        }

    } while (option != 7 && regresar=='S');

    cout << "Saliendo del sistema...\n";

    return 0;
}
