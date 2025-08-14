#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "Flight.h"
#include "Ticket.h"
#include <vector>
#include <unordered_map>
#include <string>
#include "../classes/User.h" 

class FileManager {
public:
    // Flights
    static std::vector<Flight> loadFlights(const std::string& filename);
    static void saveFlights(const std::string& filename, const std::vector<Flight>& flights);

    // Tickets
    static std::unordered_map<std::string, Ticket> loadTickets(const std::string& filename);
    static void saveTickets(const std::string& filename, const std::unordered_map<std::string, Ticket>& tickets);

    static void saveUsers(const std::string& filename, const std::unordered_map<std::string, User>& users);
    static std::unordered_map<std::string, User> loadUsers(const std::string& filename);

};

#endif
