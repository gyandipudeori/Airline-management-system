#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

// ------------------ FLIGHTS ------------------

std::vector<Flight> FileManager::loadFlights(const std::string& filename) {
    std::vector<Flight> flights;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string id, org, dest, date, time;
        int total, avail;
        float fare, surge;

        std::getline(iss, id, ',');
        std::getline(iss, org, ',');
        std::getline(iss, dest, ',');
        std::getline(iss, date, ',');
        std::getline(iss, time, ',');
        iss >> total;
        iss.ignore(1);
        iss >> avail;
        iss.ignore(1);
        iss >> fare;
        iss.ignore(1);
        iss >> surge;

        flights.emplace_back(id, org, dest, date, time, total, avail, fare, surge);
    }

    return flights;
}

void FileManager::saveFlights(const std::string& filename, const std::vector<Flight>& flights) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << " Failed to open " << filename << " for writing.\n";
        return;
    }

    for (const auto& f : flights) {
        file << f.getFlightID() << "," << f.getOrigin() << "," << f.getDestination() << ","
             << f.getDate() << "," << f.getTime() << "," << f.getTotalSeats() << ","
             << f.getAvailableSeats() << "," << f.getBaseFare() << "," << f.getSurgeMultiplier() << "\n";
    }

    file.flush();
    file.close();
}

// ------------------ TICKETS ------------------

std::unordered_map<std::string, Ticket> FileManager::loadTickets(const std::string& filename) {
    std::unordered_map<std::string, Ticket> tickets;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        Ticket t = Ticket::deserialize(line);
        tickets[t.getBookingID()] = t;
    }

    return tickets;
}

void FileManager::saveTickets(const std::string& filename, const std::unordered_map<std::string, Ticket>& tickets) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << " Failed to open " << filename << " for writing.\n";
        return;
    }

    for (const auto& pair : tickets) {
        const Ticket& t = pair.second;
        if (t.getBookingID().empty() || t.getPassengerName().empty() || t.getFlightID().empty()) {
            continue;
        }
        file << t.serialize() << "\n";
    }

    file.flush();
    file.close();
}

// ------------------ USERS ------------------

void FileManager::saveUsers(const std::string& filename, const std::unordered_map<std::string, User>& users) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << " Failed to open " << filename << " for writing.\n";
        return;
    }

    for (const auto& [name, user] : users) {
        file << user.name << "," << user.code << "," << user.points << ",";
        for (size_t i = 0; i < user.bookings.size(); ++i) {
            file << user.bookings[i];
            if (i != user.bookings.size() - 1) file << ";";
        }
        file << "\n";
    }

    file.flush();
    file.close();
}

std::unordered_map<std::string, User> FileManager::loadUsers(const std::string& filename) {
    std::unordered_map<std::string, User> users;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        User user;
        std::string bookingsStr;

        std::getline(iss, user.name, ',');
        std::getline(iss, user.code, ',');
        std::string pointsStr;
        std::getline(iss, pointsStr, ',');
        user.points = std::stoi(pointsStr);
        std::getline(iss, bookingsStr);

        std::stringstream ss(bookingsStr);
        std::string bookingID;
        while (std::getline(ss, bookingID, ';')) {
            user.bookings.push_back(bookingID);
        }

        users[user.name] = user;
    }

    return users;
}
