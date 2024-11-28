#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

/**
 * Clase Vuelo
 * 
 * Representa la información de un vuelo, incluyendo métodos para obtener y establecer detalles 
 * relacionados con el vuelo, como el número, la aerolínea, el precio, la duración, la fecha, el origen, 
 * el destino y la disponibilidad de asientos.
 */
class Flight {
private:
    int flight_number;
    string airline;
    float price;
    float duration;
    vector<int> date;
    string origin;
    string destination;
    vector<vector<bool> > availability;

public:

    Flight()
        : flight_number(0), price(0.0), duration(0.0), date(3, 0), origin(""), destination("") {}

    Flight(int _flight_number, string _airline, float _price, float _duration, vector<int> _date, string _origin, string _destination) {
        flight_number = _flight_number;
        airline = _airline;
        price = _price;
        duration = _duration;
        date = _date;
        origin = _origin;
        destination = _destination;
    }
    
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
    vector<vector<bool> > getAvailability() const { 
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
    void setAvailability(vector<vector<bool> > avail) { 
        availability = avail; 
    }

    /**
     * Convierte la información del vuelo a una representación de cadena.
     * 
     * Este método devuelve una descripción detallada del vuelo en forma de cadena, incluyendo
     * el número de vuelo, aerolínea, precio, duración, origen, destino y fecha del vuelo.
     * 
     * @return Una cadena que contiene la descripción completa del vuelo.
     */
    string toString() const {
        // Usar ostringstream para manejar el formato
        ostringstream output;

        // Establecer precisión para precio y duración
        output << fixed << setprecision(2);

        // Formatear la fecha
        string dateStr = to_string(date[0]) + "/" + to_string(date[1]) + "/" + to_string(date[2]);

        // Construir el string del vuelo
        output << "Vuelo: " << flight_number
               << "\nOrigen: " << origin
               << "\nDestino: " << destination
               << "\nAerolínea: " << airline
               << "\nPrecio: $" << price
               << "\nDuración: " << static_cast<int>(duration) << " hrs"
               << "\nFecha: " << dateStr << "\n";

        // Convertir ostringstream a string
        return output.str();
    }

    
};
#endif