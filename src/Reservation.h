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
    int idFlight;
    float price;
    int rowSeat;
    int colSeat;

public:
    Reservation() {}

    Reservation(int _idFlight, int _rowSeat, int _colSeat, float _price){
         idFlight = _idFlight;
         price = _price;
         rowSeat = _rowSeat;
         colSeat = _colSeat;
    }
    /**
     * Obtiene el ID de la reserva.
     * 
     * @return ID de la reserva.
     */
    int getIdReserva() { 
        return id_reserva; 
    }
    
    // Obtener el valor de la fila del asiento
    int getRowSeat() const {
        return rowSeat;
    }

    // Obtener el valor de la columna del asiento
    int getColSeat() const {
        return colSeat;
    }
    
    /**
     * Obtiene el vuelo reservado.
     * 
     * @return Objeto Vuelo reservado.
     */
    int getVuelo() { 
        return idFlight; 
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
    void setVuelo(int v) { 
        idFlight = v; 
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
    string toString()const{
        std::stringstream ss;
        ss << "Vuelo ID: " << idFlight << " | "
           << "Asiento: (" << static_cast<char>(rowSeat + 'A') << ", " << colSeat << ") |"
           << "Precio: $" << price;
        return ss.str();
    }
};

#endif