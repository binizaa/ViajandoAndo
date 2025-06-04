#ifndef FLIGHTDATA_H
#define FLIGHTDATA_H

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "DataBase.h"
#include "Flight.h"

using namespace std;

class FlightData : public DataBase {
private:
    std::map<int, Flight> flights;

    std::vector<int> dateFormat(const std::string& dateStr);
    std::vector<std::string> separateAvailability(const std::string& line);

public:
    FlightData() {}

    void setFlights(const std::map<int, Flight>& _flights);

    map<int, Flight> getFlights();

    void load() override;

    void update() override;

    std::vector<Flight> dateAndAirlineFilter(const std::string& airline, int day, int month, int year);
};

#endif
