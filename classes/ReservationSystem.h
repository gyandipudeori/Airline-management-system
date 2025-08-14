#ifndef RESERVATION_SYSTEM_H
#define RESERVATION_SYSTEM_H

#include <string>
#include <vector>
#include <queue>
#include <mutex>
#include <unordered_map>
#include "Flight.h"
#include "Ticket.h"
#include "PricingEngine.h"
#include "FileManager.h"
#include "User.h"


// Priority booking structure for waitlist
struct PriorityBooking {
    std::string passengerName;
    std::string flightID;
    int priority; // Lower number = higher priority (e.g., 1 = VIP)

    bool operator<(const PriorityBooking& other) const {
        return priority > other.priority; // For min-heap behavior
    }
};

class ReservationSystem {
private:
    std::vector<Flight> flights;
    std::unordered_map<std::string, Ticket> tickets;
    std::mutex mtx;
    std::priority_queue<PriorityBooking> waitlist;
    std::unordered_map<std::string, User> users; 

public:
    // Load/Save
    void loadFlights();
    void loadTickets();
    void saveAll();

    // Display
    void displayFlights() const;

    // Now returns matching flight IDs
    std::vector<std::string> displayAvailableFlights(const std::string& origin,
                                                     const std::string& destination,
                                                     const std::string& date,
                                                     const std::string& time) const;

    void printTicket(const std::string& bookingID) const;

    // Booking methods
    std::string bookTicket(const std::string& origin,
                           const std::string& destination,
                           const std::string& date,
                           const std::string& time,
                           const std::string& passengerName,
                           int daysToDeparture);

    std::string bookTicketByFlightID(const std::string& flightID,
                                     const std::string& passengerName,
                                     int daysToDeparture,
                                     int priority = 5);

    // Modify/Cancel
    bool modifyTicket(const std::string& bookingID,
                      const std::string& newFlightID,
                      int daysToDeparture);

    bool cancelTicket(const std::string& bookingID);

    // Helper
    std::string generateBookingID(const std::string& passengerName) const;
    void addSampleFlights();

    const User& getUser(const std::string& name) const;

};

#endif
