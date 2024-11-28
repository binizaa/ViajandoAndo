#ifndef FLIGHTDATA_H
#define FLIGHTDATA_H

#include <map>
#include <string>

#include "User.h"

class FlightData{
private:
    map<string,User> flights;

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

public:
    map<int, Flight> loadFlightData() {
        map<int, Flight> flights;

        ifstream file("./BaseData/flightData.csv");
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
};

#endif