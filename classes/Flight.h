#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>

#include <set> 

class Flight {
private:
    std::string flightID;
    std::string origin;
    std::string destination;
    std::string date;  
    std::string time;
    int totalSeats;
    int availableSeats;
    float baseFare;
    float surgeMultiplier;
    std::set<int> bookedSeats;


public:
    // Constructor
    Flight(std::string id, std::string org, std::string dest, std::string d, std::string t,
           int total, int available, float fare, float surge = 1.0f);

    // Getters
    std::string getFlightID() const;
    std::string getOrigin() const;
    std::string getDestination() const;
    std::string getDate() const;
    std::string getTime() const;
    int getTotalSeats() const;
    int getAvailableSeats() const;
    float getBaseFare() const;
    float getSurgeMultiplier() const;


    int assignSeat();                  
    void releaseSeat(int seatNumber);

    // Setters / Updaters
    void setSurgeMultiplier(float surge);
    void updateSurgeMultiplier(float delta);
    void bookSeat();
    void cancelSeat();

    // Display flight info
    void display() const;

    // occupancy percentage
    float getOccupancyRate() const;

    // calculate current price
    float calculateDynamicPrice(int daysToDeparture) const;

};

#endif