#include "Ticket.h"
#include <sstream>
#include <iomanip>

// constructor definition
Ticket::Ticket(std::string bookingID, std::string passengerName, std::string flightID,
               int seatNumber, float price,
               std::string code, int points, std::string tier)
    : bookingID(bookingID), passengerName(passengerName),
      flightID(flightID), seatNumber(seatNumber), price(price),
      code(code), points(points), tier(tier) {}

std::string Ticket::getBookingID() const { return bookingID; }
std::string Ticket::getPassengerName() const { return passengerName; }
std::string Ticket::getFlightID() const { return flightID; }
int Ticket::getSeatNumber() const { return seatNumber; }
float Ticket::getPrice() const { return price; }

void Ticket::setPassengerName(const std::string& name) {
    passengerName = name;
}

void Ticket::setSeatNumber(int seat) {
    seatNumber = seat;
}

void Ticket::setPrice(float newPrice) {
    price = newPrice;
}

void Ticket::setFlightID(const std::string& id) {
    flightID = id;
}

void Ticket::display() const {
    std::cout << "=========== TICKET ===========\n";
    std::cout << "Booking ID  : " << bookingID << "\n";
    std::cout << "Passenger   : " << passengerName << "\n";
    std::cout << "Flight ID   : " << flightID << "\n";
    std::cout << "Seat Number : " << seatNumber << "\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Price       : Rs " << price << "\n";

    // Display frequent flyer info if available
    if (!code.empty()) {
        std::cout << "Code        : " << code << "\n";
        std::cout << "Points      : " << points << "\n";
        std::cout << "Tier        : " << tier << "\n";
    }

    std::cout << "==============================\n";
}

// Save ticket to a line (with user info)
std::string Ticket::serialize() const {
    std::ostringstream oss;
    oss << bookingID << "," << passengerName << "," << flightID << ","
        << seatNumber << "," << price << "," << code << "," << points << "," << tier;
    return oss.str();
}

// Load ticket from a line (supports both old and new formats)
Ticket Ticket::deserialize(const std::string& dataLine) {
    std::istringstream iss(dataLine);
    std::string id, name, flight, code, tier;
    int seat = 0;
    float price = 0.0f;
    int points = 0;

    std::getline(iss, id, ',');
    std::getline(iss, name, ',');
    std::getline(iss, flight, ',');
    iss >> seat;
    iss.ignore(1);
    iss >> price;

    if (iss.peek() == ',') {
        iss.ignore(1);
        std::getline(iss, code, ',');
        iss >> points;
        iss.ignore(1);
        std::getline(iss, tier);
    }

    return Ticket(id, name, flight, seat, price, code, points, tier);
}
