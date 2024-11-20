#include <string>
#include <vector>
#include <iostream>
using namespace std;

/**
 * Clase Vuelo
 * 
 * Representa la información de un vuelo, incluyendo métodos para obtener y establecer detalles 
 * relacionados con el vuelo, como el número, la aerolínea, el precio, la duración, la fecha, el origen, 
 * el destino y la disponibilidad de asientos.
 */
class Vuelo {
private:
    int flight_number;
    string airline;
    float price;
    float duration;
    vector<int> date;
    string origin;
    string destination;
    vector<vector<bool>> availability;

public:
    /**
     * Obtiene el número de vuelo.
     * 
     * @return Número de vuelo.
     */
    int getFlightNumber() const { 
        return flight_number; 
    }
    
    /**
     * Obtiene el nombre de la aerolínea.
     * 
     * @return Nombre de la aerolínea.
     */
    string getAirline() const { 
        return airline; 
    }
    
    /**
     * Obtiene el precio del vuelo.
     * 
     * @return Precio del vuelo.
     */
    float getPrice() const { 
        return price; 
    }
    
    /**
     * Obtiene la duración del vuelo.
     * 
     * @return Duración del vuelo.
     */
    float getDuration() const { 
        return duration; 
    }
    
    /**
     * Obtiene la fecha del vuelo.
     * 
     * @return Fecha del vuelo en formato [año, mes, día].
     */
    vector<int> getDate() const { 
        return date; 
    }
    
    /**
     * Obtiene la ciudad de origen del vuelo.
     * 
     * @return Ciudad de origen.
     */
    string getOrigin() const { 
        return origin; 
    }
    
    /**
     * Obtiene la ciudad de destino del vuelo.
     * 
     * @return Ciudad de destino.
     */
    string getDestination() const { 
        return destination; 
    }
    
    /**
     * Obtiene la disponibilidad de asientos del vuelo.
     * 
     * @return Disponibilidad de asientos.
     */
    vector<vector<bool>> getAvailability() const { 
        return availability; 
    }

    /**
     * Establece el número de vuelo.
     * 
     * @param flightNum Número de vuelo.
     */
    void setFlightNumber(int flightNum) { 
        flight_number = flightNum; 
    }
    
    /**
     * Establece el nombre de la aerolínea.
     * 
     * @param air Nombre de la aerolínea.
     */
    void setAirline(string air) { 
        airline = air; 
    }
    
    /**
     * Establece el precio del vuelo.
     * 
     * @param pr Precio del vuelo.
     */
    void setPrice(float pr) { 
        price = pr; 
    }
    
    /**
     * Establece la duración del vuelo.
     * 
     * @param dur Duración del vuelo.
     */
    void setDuration(float dur) { 
        duration = dur; 
    }
    
    /**
     * Establece la fecha del vuelo.
     * 
     * @param dt Fecha del vuelo en formato [año, mes, día].
     */
    void setDate(const vector<int>& dt) { 
        date = dt; 
    }
    
    /**
     * Establece la ciudad de origen del vuelo.
     * 
     * @param orig Ciudad de origen.
     */
    void setOrigin(string orig) { 
        origin = orig; 
    }
    
    /**
     * Establece la ciudad de destino del vuelo.
     * 
     * @param dest Ciudad de destino.
     */
    void setDestination(string dest) { 
        destination = dest; 
    }
    
    /**
     * Establece la disponibilidad de asientos del vuelo.
     * 
     * @param avail Disponibilidad de asientos.
     */
    void setAvailability(vector<vector<bool>> avail) { 
        availability = avail; 
    }
};

/**
 * Clase Reservation
 * 
 * Representa una reservación de vuelo, con métodos para obtener y establecer detalles de la reserva, 
 * como el ID de la reserva, el vuelo reservado y el precio de la reserva.
 */
class Reservation {
private:
    int id_reserva;
    Vuelo vuelo;
    float price;

public:
    /**
     * Obtiene el ID de la reserva.
     * 
     * @return ID de la reserva.
     */
    int getIdReserva() { 
        return id_reserva; 
    }
    
    /**
     * Obtiene el vuelo reservado.
     * 
     * @return Objeto Vuelo reservado.
     */
    Vuelo getVuelo() { 
        return vuelo; 
    }
    
    /**
     * Obtiene el precio de la reserva.
     * 
     * @return Precio de la reserva.
     */
    float getPrice() { 
        return price; 
    }

    /**
     * Establece el ID de la reserva.
     * 
     * @param id ID de la reserva.
     */
    void setIdReserva(int id) { 
        id_reserva = id; 
    }
    
    /**
     * Establece el vuelo reservado.
     * 
     * @param v Objeto Vuelo reservado.
     */
    void setVuelo(Vuelo v) { 
        vuelo = v; 
    }
    
    /**
     * Establece el precio de la reserva.
     * 
     * @param pr Precio de la reserva.
     */
    void setPrice(float pr) { 
        price = pr; 
    }
};

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

public:
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
};

int main() {
    cout << "Hola, soy Bini" << endl;
    return 0;
}
