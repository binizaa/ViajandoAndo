#include <string>
#include <vector>
#include <iostream>
#include <cstdlib> 
#include <sstream>
#include <thread>
#include "Vuelo.h"
#include "Reservation.h"
#include "User.h"
using namespace std;

User logIn(vector<User> users) {
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
    string newUsername, newPassword, newEmail;

    cout << "\n------------------Crear cuenta------------------" << endl;
    cout << "Ingrese un nuevo nombre de usuario: ";
    cin >> newUsername;
    cout << "Ingresa un nuevo correo: ";
    cin >> newEmail;
    cout << "Ingrese una nueva contrasena: ";
    cin >> newPassword;


    User newUs(newId, newUsername, newEmail, newPassword);

    newUs.createUser();
    
    cout << "Cuenta creada exitosamente.\n";
    
    return newUs;
}

User accountLogin(vector<User>& userData){
    #ifdef _WIN32
                system("cls"); 
    #else
                system("clear"); 
        #endif

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
        User newUser = createAccount(userData.size() + 1);
        userData.push_back(newUser);
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

vector<User> loadDataBase() {
    vector<User> users;

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
            users.push_back(User(id, name, email, password));
        } else {
            cerr << "Error: Línea malformada: " << line << endl;
        }
    }

    file.close();

    return users;
}

int main() {
    vector<User> userData = loadDataBase();
    User user = accountLogin(userData);

    if(!user.getIsValid()) return 0;

    int option;
    char regresar = 'N';
    do {
        #ifdef _WIN32
                system("cls"); 
        #else
                    system("clear"); 
            #endif
        
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
                cout << "Opción 1: Mostrar todos los vuelos seleccionada.\n";
                // Aquí llamas a la función correspondiente
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
        
        if(option!=7){
            cout<<"¿Deseas regresar al ménu del usuario?(S/N)"<<endl;
            cin>>regresar;
        }

    } while (option != 7 && regresar=='S');

    cout << "Saliendo del sistema...\n";

    return 0;
}
