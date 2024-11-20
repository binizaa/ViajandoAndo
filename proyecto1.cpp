#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Vuelo {
private:
    int flight_number;
    string airline;
    float price;
    float duration;
    vector<int> date; // Formato de fecha [año, mes, día]
    string origin;
    string destination;
    vector<vector<bool>> availability;

public:
    int getFlightNumber() const { 
        return flight_number; 
    }
    
    string getAirline() const { 
        return airline; 
    }
    
    float getPrice() const { 
        return price; 
    }
    
    float getDuration() const { 
        return duration; 
    }
    
    vector<int> getDate() const { 
        return date; 
    }
    
    string getOrigin() const { 
        return origin; 
    }
    
    string getDestination() const { 
        return destination; 
    }
    
    vector<vector<bool>> getAvailability() const { 
        return availability; 
    }

    void setFlightNumber(int flightNum) { 
        flight_number = flightNum; 
    }
    
    void setAirline(string air) { 
        airline = air; 
    }
    
    void setPrice(float pr) { 
        price = pr; 
    }
    
    void setDuration(float dur) { 
        duration = dur; 
    }
    
    void setDate(const vector<int>& dt) { 
        date = dt; 
    }
    
    void setOrigin(string orig) { 
        origin = orig; 
    }
    
    void setDestination(string dest) { 
        destination = dest; 
    }
    
    void setAvailability(vector<vector<bool>> avail) { 
        availability = avail; 
    }
};

class Reservation {
private:
    int id_reserva;
    Vuelo vuelo;
    float price;

public:
    int getIdReserva(){ 
        return id_reserva; 
    }
    
    Vuelo getVuelo(){ 
        return vuelo; 
    }
    
    float getPrice(){ 
        return price; 
    }

    void setIdReserva(int id) { 
        id_reserva = id; 
    }
    
    void setVuelo(Vuelo v) { 
        vuelo = v; 
    }
    
    void setPrice(float pr) { 
        price = pr; 
    }
};

class User {
private:
    int id_user;
    string name;
    string mail;
    string password;
    vector<Reservation> reservations;

public:
    int getIdUser(){ 
        return id_user; 
    }
    
    string getName(){ 
        return name; 
    }
    
    string getMail(){ 
        return mail; 
    }
    
    string getPassword(){ 
        return password; 
    }
    
    vector<Reservation> getReservations(){ 
        return reservations; 
    }

    void setIdUser(int id) { 
        id_user = id; 
    }
    
    void setName(string n) { 
        name = n; 
    }
    
    void setMail(string m) { 
        mail = m; 
    }
    
    void setPassword(string pass) { 
        password = pass; 
    }
    
    void setReservations(vector<Reservation> res) { 
        reservations = res; 
    }
};

int main(){
    cout<<"Hola, soy Bini"<<endl;

    return 0;
}
