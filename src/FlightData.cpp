#include "FlightData.h"

vector<int> FlightData::dateFormat(const string& dateStr) {
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

vector<string> FlightData::separateAvailability(const string& line) {
    vector<string> seatLines;
    stringstream ss(line);
    string seatLine;

    for (int i = 0; i < 6; ++i) {
        if (getline(ss, seatLine, ',')) {
            seatLines.push_back(seatLine);
        } else {
            cerr << "Error: Se esperaba más datos para las líneas de disponibilidad." << endl;
            break;
        }
    }

    return seatLines;
}

void FlightData::setFlights(const map<int, Flight>& _flights) {
    flights = _flights;
}

map<int, Flight> FlightData::getFlights() {
    load();
    return flights;
}

void FlightData::load() {
    ifstream file("./BaseData/flightData.csv");
    if (!file) {
        cerr << "Error: No se pudo abrir el archivo flightData.csv" << endl;
        return;
    }

    string line;
    getline(file, line); // Leer encabezado y descartarlo

    while (getline(file, line)) {
        stringstream ss(line);
        string flightNumberStr, airline, priceStr, durationStr, dateStr, origin, destination, availabilityLine;

        if (getline(ss, flightNumberStr, ',') &&
            getline(ss, airline, ',') &&
            getline(ss, priceStr, ',') &&
            getline(ss, durationStr, ',') &&
            getline(ss, dateStr, ',') &&
            getline(ss, origin, ',') &&
            getline(ss, destination, ',') &&
            getline(ss, availabilityLine)) {

            int flightNumber = stoi(flightNumberStr);
            float price = stof(priceStr);
            float duration = stof(durationStr);

            vector<int> date = dateFormat(dateStr);

            vector<string> availability = separateAvailability(availabilityLine);

            flights[flightNumber] = Flight(flightNumber, airline, price, duration, date, origin, destination, availability);
        } else {
            cerr << "Error: Línea malformada: " << line << endl;
        }
    }

    file.close();
}

void FlightData::update() {
    ofstream file("./BaseData/flightData.csv");
    if (!file) {
        cerr << "Error: No se pudo abrir el archivo flightData.csv" << endl;
        return;
    }

    file << "Flight Number,Airline,Price,Duration (hrs),Date,Origin,Destination,Seat Row 1,Seat Row 2,Seat Row 3,Seat Row 4,Seat Row 5,Seat Row 6\n";

    for (auto it = flights.begin(); it != flights.end(); ++it) {
        int flightNumber = it->first;
        Flight flight = it->second;

        string airline = flight.getAirline();
        double price = flight.getPrice();
        int duration = flight.getDuration();
        vector<int> date = flight.getDate();
        string origin = flight.getOrigin();
        string destination = flight.getDestination();
        vector<string> availability = flight.getAvailability();

        string dateStr = to_string(date[2]) + "-" + to_string(date[1]) + "-" + to_string(date[0]);

        file << flightNumber << ","
             << airline << ","
             << price << ","
             << duration << ","
             << dateStr << ","
             << origin << ","
             << destination << ","
             << availability[0] << ","
             << availability[1] << ","
             << availability[2] << ","
             << availability[3] << ","
             << availability[4] << ","
             << availability[5] << "\n";
    }
}

vector<Flight> FlightData::dateAndAirlineFilter(const string& airline, int day, int month, int year) {
    vector<Flight> filteredFlights;

    for (const auto& pair : flights) {
        const Flight& flight = pair.second;
        vector<int> date = flight.getDate();

        if (flight.getAirline() == airline && date[0] == day && date[1] == month && date[2] == year) {
            filteredFlights.push_back(flight);
        }
    }

    return filteredFlights;
}
