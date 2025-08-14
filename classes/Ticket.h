#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <string>

class Ticket {
private:
    std::string bookingID;
    std::string passengerName;
    std::string flightID;
    int seatNumber;
    float price;

    //  Added for frequent flyer info
    std::string code;
    int points = 0;
    std::string tier;

public:
    Ticket() = default;

    //  Updated constructor
    Ticket(std::string bookingID, std::string passengerName, std::string flightID,
           int seatNumber, float price,
           std::string code = "", int points = 0, std::string tier = "");

    // Getters
    std::string getBookingID() const;
    std::string getPassengerName() const;
    std::string getFlightID() const;
    int getSeatNumber() const;
    float getPrice() const;

    //  New Getters for flyer info
    std::string getCode() const { return code; }
    int getPoints() const { return points; }
    std::string getTier() const { return tier; }

    // Setters
    void setPassengerName(const std::string& name);
    void setSeatNumber(int seat);
    void setPrice(float newPrice);
    void setFlightID(const std::string& id);

    //  New Setters for flyer info
    void setCode(const std::string& c) { code = c; }
    void setPoints(int p) { points = p; }
    void setTier(const std::string& t) { tier = t; }

    // Display ticket details
    void display() const;

    // Serialize to file
    std::string serialize() const;

    // Deserialize from string
    static Ticket deserialize(const std::string& dataLine);
};

#endif
