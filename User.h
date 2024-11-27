#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Reservation.h"
using namespace std;

/**
 * Clase User
 * 
 * Representa un usuario en el sistema de reservaciones, incluyendo métodos para obtener y 
 * establecer detalles del usuario, como el ID, nombre, correo, contraseña y reservas realizadas.
 */
class User {
private:
    int id_user;
    string name;
    string mail;
    string password;
    vector<Reservation> reservations;
    bool isValid;

public:
    User(string _name, string _password){
        name = _name;
        password = _password;
        isValid = true;
    }

    User(int _id_user, string _name, string _mail, string _password){
        id_user = _id_user;
        name = _name;
        mail = _mail;
        password = _password;
        isValid = true;
    }

    // Constructor para un usuario no válido
    User() : name(""), password(""), isValid(false) {}
    
    /**
     * Obtiene el ID del usuario.
     * 
     * @return ID del usuario.
     */
    int getIdUser() { 
        return id_user; 
    }
    
    /**
     * Obtiene el nombre del usuario.
     * 
     * @return Nombre del usuario.
     */
    string getName() { 
        return name; 
    }
    
    /**
     * Obtiene el correo electrónico del usuario.
     * 
     * @return Correo electrónico del usuario.
     */
    string getMail() { 
        return mail; 
    }
    
    /**
     * Obtiene la contraseña del usuario.
     * 
     * @return Contraseña del usuario.
     */
    string getPassword() { 
        return password; 
    }
    
    /**
     * Obtiene la lista de reservaciones del usuario.
     * 
     * @return Lista de reservaciones.
     */
    vector<Reservation> getReservations() { 
        return reservations; 
    }

    bool getIsValid() const {
        return isValid;
    }

    /**
     * Establece el ID del usuario.
     * 
     * @param id ID del usuario.
     */
    void setIdUser(int id) { 
        id_user = id; 
    }
    
    /**
     * Establece el nombre del usuario.
     * 
     * @param n Nombre del usuario.
     */
    void setName(string n) { 
        name = n; 
    }
    
    /**
     * Establece el correo electrónico del usuario.
     * 
     * @param m Correo electrónico del usuario.
     */
    void setMail(string m) { 
        mail = m; 
    }
    
    /**
     * Establece la contraseña del usuario.
     * 
     * @param pass Contraseña del usuario.
     */
    void setPassword(string pass) { 
        password = pass; 
    }
    
    /**
     * Establece la lista de reservaciones del usuario.
     * 
     * @param res Lista de reservaciones.
     */
    void setReservations(vector<Reservation> res) { 
        reservations = res; 
    }

    // Setter para isValid
    void setIsValid(bool valid) {
        isValid = valid;
    }

    void createUser() {
        ofstream userFile;

        userFile.open("userData.csv", ios::app);

        if (!userFile) {
            cerr << "Error: No se pudo abrir el archivo userData.csv" << endl;
            return;
        }

        userFile << id_user << "," << name << "," << mail << "," << password << endl;

        userFile.close();

        //Crear el simulador de revervaciones

        ofstream reservation("./userReservations/" + to_string(id_user) + ".csv");

        if (!reservation) {
            cerr << "Error: No se pudo crear el archivo de reservas para " << name << endl;
            return;
        }

        reservation.close();
    }

    User authenticateUser(const vector<User>& users) {
        for(int i = 0; i<users.size(); i++){
            if (name == users[i].name) {
                if (password == users[i].password) {
                    cout << "Contraseña correcta" << endl;
                    return users[i];
                } else {
                    cout << "Contraseña incorrecta" << endl;
                    return User(); // Usuario no válido
                }
            }
        }
        cout << "Ese usuario no existe" << endl;
        return User();
    }


    /**
     * Convierte la información del usuario a una representación de cadena.
     * 
     * Este método devuelve una descripción detallada del usuario en forma de cadena,
     * incluyendo su ID, nombre, correo electrónico y la cantidad de reservaciones 
     * asociadas. Además, lista los detalles de cada reservación en líneas separadas.
     * 
     * @return Una cadena que contiene la descripción completa del usuario y sus reservaciones.
     */
    string toString(){
        string str = "Usuario #" + to_string(id_user);
        str += " | Nombre: " + name;
        str += " | Email: " + mail;
        str += " | Reservaciones: " + to_string(reservations.size()) + " reservaciones.";
        for (int i = 0; i < reservations.size(); ++i) {
            str += "\n  - " + reservations[i].toString();
        }
        return str;
    }
};