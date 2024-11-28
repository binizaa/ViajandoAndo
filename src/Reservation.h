#ifndef RESERVATION_H
#define RESERVATION_H

#include "Flight.h"

/**
 * Clase Reservation
 * 
 * Representa una reservación de vuelo, con métodos para obtener y establecer detalles de la reserva, 
 * como el ID de la reserva, el vuelo reservado y el precio de la reserva.
 */
class Reservation {
private:
    int id_reserva;
    Flight vuelo;
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
    Flight getVuelo() { 
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
    void setVuelo(Flight v) { 
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

    /**
     * Convierte la información de la reservación a una representación de cadena.
     * 
     * Este método devuelve una descripción detallada de la reservación en forma de cadena,
     * incluyendo el ID de la reservación, los detalles del vuelo asociado y el precio total
     * de la reservación.
     * 
     * @return Una cadena que contiene la descripción completa de la reservación.
     */
    string toString() {
        string str = "ID Reservación: " + to_string(id_reserva);
        str += " | Vuelo: [" + vuelo.toString() + "]";
        str += " | Precio: $" + to_string(price);
        return str;
    }
};

#endif