#include <string>
#include <vector>
#include <iostream>
#include <cstdlib> 
#include "Vuelo.h"
#include "Reservation.h"
#include "User.h"
using namespace std;

User logIn() {
    string username, password;
    cout << "\n------------------Inicio de sección------------------" << endl;
    cout << "Ingrese su nombre de usuario: ";
    cin >> username;
    cout << "Ingrese su contrasena: ";
    cin >> password;

    User us(username, password);

    cout << "Inicio de sesión exitoso.\n";

    return us; 
}

User createAccount() {
    string newUsername, newPassword, newEmail;

    cout << "\n------------------Crear cuenta------------------" << endl;
    cout << "Ingrese un nuevo nombre de usuario: ";
    cin >> newUsername;
    cout << "Ingresa un nuevo correo: ";
    cin >> newEmail;
    cout << "Ingrese una nueva contrasena: ";
    cin >> newPassword;

    User newUs(1, newUsername, newEmail, newPassword);

    newUs.createUser();
    
    cout << "Cuenta creada exitosamente.\n";
    
    return newUs;
}

User accountLogin(){
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

    switch (opc){
        case 1:
            return logIn();
            break;
        case 2:
            return createAccount();
            break;
        case 3:
            cout<<"Salir"<<endl;
            return User("hola","contraseN");
        default:
            cout << "Opción no válida, intente de nuevo.\n";
            return accountLogin();
            break;
    }
}

int main() {
    
    User user = accountLogin();

    cout<<user.toString()<<endl;

    return 0;
}
