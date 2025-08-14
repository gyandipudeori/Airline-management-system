#include "../classes/ReservationSystem.h"
#include "../utils/FileManager.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

void ReservationSystem::addSampleFlights() {
    // Delhi → Mumbai, 2025-08-10, 08:30
    flights.push_back(Flight("F101", "Delhi", "Mumbai", "2025-08-10", "08:30", 100, 100, 5000.0f));
    flights.push_back(Flight("F102", "Delhi", "Mumbai", "2025-08-10", "08:30", 120, 120, 5200.0f));
    flights.push_back(Flight("F103", "Delhi", "Mumbai", "2025-08-10", "08:30", 90, 90, 4800.0f));

    // Guwahati → Kolkata, 2025-08-12, 19:00
    flights.push_back(Flight("F104", "Guwahati", "Kolkata", "2025-08-12", "19:00", 95, 95, 4200.0f));
    flights.push_back(Flight("F105", "Guwahati", "Kolkata", "2025-08-12", "19:00", 85, 85, 4100.0f));
    flights.push_back(Flight("F106", "Guwahati", "Kolkata", "2025-08-12", "19:00", 100, 100, 4500.0f));

    // Bangalore → Hyderabad, 2025-08-13, 06:45
    flights.push_back(Flight("F107", "Bangalore", "Hyderabad", "2025-08-13", "06:45", 110, 110, 3900.0f));
    flights.push_back(Flight("F108", "Bangalore", "Hyderabad", "2025-08-13", "06:45", 90, 90, 4000.0f));
    flights.push_back(Flight("F109", "Bangalore", "Hyderabad", "2025-08-13", "06:45", 100, 100, 4100.0f));

    // Chennai → Kolkata, 2025-08-14, 15:15
    flights.push_back(Flight("F110", "Chennai", "Kolkata", "2025-08-14", "15:15", 95, 95, 4600.0f));
    flights.push_back(Flight("F111", "Chennai", "Kolkata", "2025-08-14", "15:15", 100, 100, 4700.0f));
    flights.push_back(Flight("F112", "Chennai", "Kolkata", "2025-08-14", "15:15", 80, 80, 4500.0f));

    // Delhi → Lucknow, 2025-08-15, 09:00
    flights.push_back(Flight("F113", "Delhi", "Lucknow", "2025-08-15", "09:00", 90, 90, 3600.0f));
    flights.push_back(Flight("F114", "Delhi", "Lucknow", "2025-08-15", "09:00", 85, 85, 3700.0f));
    flights.push_back(Flight("F115", "Delhi", "Lucknow", "2025-08-15", "09:00", 80, 80, 3400.0f));

    // Mumbai → Pune, 2025-08-16, 11:30
    flights.push_back(Flight("F116", "Mumbai", "Pune", "2025-08-16", "11:30", 60, 60, 2500.0f));
    flights.push_back(Flight("F117", "Mumbai", "Pune", "2025-08-16", "11:30", 70, 70, 2400.0f));
    flights.push_back(Flight("F118", "Mumbai", "Pune", "2025-08-16", "11:30", 65, 65, 2300.0f));

    // Kolkata → Patna, 2025-08-17, 13:30
    flights.push_back(Flight("F119", "Kolkata", "Patna", "2025-08-17", "13:30", 75, 75, 3100.0f));
    flights.push_back(Flight("F120", "Kolkata", "Patna", "2025-08-17", "13:30", 70, 70, 3000.0f));
    flights.push_back(Flight("F121", "Kolkata", "Patna", "2025-08-17", "13:30", 85, 85, 3200.0f));

    // Chennai → Delhi, 2025-08-18, 10:00
    flights.push_back(Flight("F122", "Chennai", "Delhi", "2025-08-18", "10:00", 100, 100, 4900.0f));
    flights.push_back(Flight("F123", "Chennai", "Delhi", "2025-08-18", "10:00", 95, 95, 5000.0f));
    flights.push_back(Flight("F124", "Chennai", "Delhi", "2025-08-18", "10:00", 85, 85, 4800.0f));

    // Mumbai → Delhi, 2025-08-19, 17:20
    flights.push_back(Flight("F125", "Mumbai", "Delhi", "2025-08-19", "17:20", 100, 100, 5100.0f));
    flights.push_back(Flight("F126", "Mumbai", "Delhi", "2025-08-19", "17:20", 120, 120, 5300.0f));
    flights.push_back(Flight("F127", "Mumbai", "Delhi", "2025-08-19", "17:20", 90, 90, 4900.0f));

    // Pune → Hyderabad, 2025-08-20, 06:45
    flights.push_back(Flight("F128", "Pune", "Hyderabad", "2025-08-20", "06:45", 75, 75, 3200.0f));
    flights.push_back(Flight("F129", "Pune", "Hyderabad", "2025-08-20", "06:45", 80, 80, 3300.0f));
    flights.push_back(Flight("F130", "Pune", "Hyderabad", "2025-08-20", "06:45", 85, 85, 3400.0f));

    // Delhi → Chennai, 2025-08-21, 14:40
    flights.push_back(Flight("F131", "Delhi", "Chennai", "2025-08-21", "14:40", 100, 100, 4700.0f));
    flights.push_back(Flight("F132", "Delhi", "Chennai", "2025-08-21", "14:40", 90, 90, 4600.0f));
    flights.push_back(Flight("F133", "Delhi", "Chennai", "2025-08-21", "14:40", 95, 95, 4500.0f));

    // Guwahati → Delhi, 2025-08-22, 08:00
    flights.push_back(Flight("F134", "Guwahati", "Delhi", "2025-08-22", "08:00", 90, 90, 4800.0f));
    flights.push_back(Flight("F135", "Guwahati", "Delhi", "2025-08-22", "08:00", 100, 100, 4900.0f));
    flights.push_back(Flight("F136", "Guwahati", "Delhi", "2025-08-22", "08:00", 85, 85, 4700.0f));

    // Hyderabad → Kolkata, 2025-08-23, 16:10
    flights.push_back(Flight("F137", "Hyderabad", "Kolkata", "2025-08-23", "16:10", 90, 90, 4500.0f));
    flights.push_back(Flight("F138", "Hyderabad", "Kolkata", "2025-08-23", "16:10", 85, 85, 4600.0f));
    flights.push_back(Flight("F139", "Hyderabad", "Kolkata", "2025-08-23", "16:10", 95, 95, 4700.0f));

    // Bangalore → Mumbai, 2025-08-24, 12:00
    flights.push_back(Flight("F140", "Bangalore", "Mumbai", "2025-08-24", "12:00", 100, 100, 4800.0f));
    flights.push_back(Flight("F141", "Bangalore", "Mumbai", "2025-08-24", "12:00", 110, 110, 4700.0f));
    flights.push_back(Flight("F142", "Bangalore", "Mumbai", "2025-08-24", "12:00", 105, 105, 4900.0f));

    // Ahmedabad → Delhi, 2025-08-25, 18:30
    flights.push_back(Flight("F143", "Ahmedabad", "Delhi", "2025-08-25", "18:30", 85, 85, 4000.0f));
    flights.push_back(Flight("F144", "Ahmedabad", "Delhi", "2025-08-25", "18:30", 90, 90, 4200.0f));
    flights.push_back(Flight("F145", "Ahmedabad", "Delhi", "2025-08-25", "18:30", 100, 100, 4300.0f));

    // Patna → Delhi, 2025-08-26, 07:45
    flights.push_back(Flight("F146", "Patna", "Delhi", "2025-08-26", "07:45", 75, 75, 3600.0f));
    flights.push_back(Flight("F147", "Patna", "Delhi", "2025-08-26", "07:45", 85, 85, 3700.0f));
    flights.push_back(Flight("F148", "Patna", "Delhi", "2025-08-26", "07:45", 90, 90, 3800.0f));

    // Goa → Mumbai, 2025-08-27, 17:00
    flights.push_back(Flight("F149", "Goa", "Mumbai", "2025-08-27", "17:00", 80, 80, 3200.0f));
    flights.push_back(Flight("F150", "Goa", "Mumbai", "2025-08-27", "17:00", 70, 70, 3100.0f));
    flights.push_back(Flight("F151", "Goa", "Mumbai", "2025-08-27", "17:00", 85, 85, 3300.0f));

}

void ReservationSystem::loadFlights() {
    flights = FileManager::loadFlights("data/flights.txt");
    if (flights.empty()) {
        std::cout << " No flight data found. Adding sample flights...\n";
        addSampleFlights();
        FileManager::saveFlights("data/flights.txt", flights);
    }
}

void ReservationSystem::loadTickets() {
    tickets = FileManager::loadTickets("data/tickets.txt");

    // Load user data too
    users = FileManager::loadUsers("data/users.txt");
}


void ReservationSystem::saveAll() {
    FileManager::saveFlights("data/flights.txt", flights);
    FileManager::saveTickets("data/bookings.txt", tickets); 
    FileManager::saveUsers("data/users.txt", users);
 
}

void ReservationSystem::displayFlights() const {
    std::cout << "========= AVAILABLE FLIGHTS =========\n";
    for (const auto& f : flights) {
        f.display();
    }
}

std::vector<std::string> ReservationSystem::displayAvailableFlights(const std::string& origin,
                                                                     const std::string& destination,
                                                                     const std::string& date,
                                                                     const std::string& time) const {
    std::vector<std::string> validFlightIDs;
    std::cout << "========= Available Flights =========\n";
    bool found = false;

    for (const auto& f : flights) {
        if (f.getOrigin() == origin &&
            f.getDestination() == destination &&
            f.getDate() == date &&
            f.getTime() == time &&
            f.getAvailableSeats() > 0) {
            f.display();
            validFlightIDs.push_back(f.getFlightID());
            found = true;
        }
    }

    if (!found) {
        std::cout << " No available flights found for the given criteria.\n";
    }

    return validFlightIDs;
}



std::string ReservationSystem::generateBookingID(const std::string& passengerName) const {
    std::ostringstream oss;
    time_t now = time(0);
    oss << "BK" << now << "_" << passengerName.substr(0, 3);
    return oss.str();
}

std::string ReservationSystem::bookTicket(const std::string& origin,
                                          const std::string& destination,
                                          const std::string& date,
                                          const std::string& time,
                                          const std::string& passengerName,
                                          int daysToDeparture) {
    std::lock_guard<std::mutex> lock(mtx);

    for (auto& flight : flights) {
        if (flight.getOrigin() == origin &&
            flight.getDestination() == destination &&
            flight.getDate() == date &&
            flight.getTime() == time) {

            if (flight.getAvailableSeats() <= 0) {
                std::cout << " No seats available.\n";
                return "";
            }

            float price = PricingEngine::calculatePrice(flight, daysToDeparture);
            flight.bookSeat();
            PricingEngine::adjustSurge(flight);

            std::string bookingID = generateBookingID(passengerName);
            int seatNumber = flight.getTotalSeats() - flight.getAvailableSeats();

            std::string flightID = flight.getFlightID();      // ✅ Added declaration
            float finalPrice = price;                         // ✅ Added declaration

            Ticket t(bookingID, passengerName, flightID, seatNumber, finalPrice);
            tickets[bookingID] = t;

            std::cout << " Ticket Booked Successfully!\n";
            t.display();

            saveAll();
            return bookingID;
        }
    }

    std::cout << " No matching flight found.\n";
    return "";
}

std::string ReservationSystem::bookTicketByFlightID(const std::string& flightID,
                                                    const std::string& passengerName,
                                                    int daysToDeparture,
                                                    int priority) {
    std::lock_guard<std::mutex> lock(mtx);

    auto& user = users[passengerName];
    user.name = passengerName;

    // Only assign a new code if it's a new user
    if (user.code.empty()) {
        user.code = "U" + std::to_string(users.size() + 1001);
    }

    user.points += 100;  // Points per booking (can be dynamic too)

    std::cout << "🎖️ Frequent Flyer Updated:\n";
    std::cout << "Code  : " << user.code << "\n";
    std::cout << "Points: " << user.points << "\n";
    std::cout << "Tier  : " << user.getTier() << "\n";

    for (auto& flight : flights) {
        if (flight.getFlightID() == flightID) {
            if (flight.getAvailableSeats() <= 0) {
                std::cout << " Flight full. Adding " << passengerName
                          << " to waitlist with priority " << priority << ".\n";
                waitlist.push({passengerName, flightID, priority});
                return "";
            }

            // Apply discount based on user's tier
            float finalPrice = PricingEngine::calculatePrice(flight, daysToDeparture);

            int discountPercent = user.getDiscountPercentage();
            if (discountPercent > 0) {
                float discountAmount = finalPrice * (discountPercent / 100.0f);
                finalPrice -= discountAmount;
                std::cout << "🎁 " << discountPercent << "% discount applied! You saved Rs " << discountAmount << "\n";
            }


            flight.bookSeat();
            PricingEngine::adjustSurge(flight);
            
            std::string bookingID = generateBookingID(passengerName);
            int seatNumber = flight.getTotalSeats() - flight.getAvailableSeats();

            // std::string flightID = flight.getFlightID();

            Ticket t(bookingID, passengerName, flightID, seatNumber, finalPrice);
            tickets[bookingID] = t;


            user.bookings.push_back(bookingID);
            users[passengerName] = user;

            std::cout << " Ticket Booked Successfully in thread!\n";
            t.display();

            std::cout << "👤 Passenger: " << passengerName << "\n";
            std::cout << "🏷️  Unique Code: " << user.code << "\n";
            std::cout << "💰 Points: " << user.points << "\n";
            std::cout << "🎖️  Tier: " << user.getTier() << "\n";


            saveAll();
            return bookingID;
        }
    }

    std::cout << " Flight ID not found.\n";
    return "";
}


bool ReservationSystem::modifyTicket(const std::string& bookingID,
                                     const std::string& newFlightID,
                                     int daysToDeparture) {
    std::lock_guard<std::mutex> lock(mtx);

    if (tickets.find(bookingID) == tickets.end()) return false;

    Ticket& oldTicket = tickets[bookingID];

    std::string choice;
    std::cout << "Do you want to update the passenger name? (y/n): ";
    std::getline(std::cin, choice);
    if (choice == "y" || choice == "Y") {
        std::string newName;
        std::cout << "Enter new passenger name: ";
        std::getline(std::cin, newName);
        oldTicket.setPassengerName(newName);
    }

    Flight* oldFlightPtr = nullptr;
    Flight* newFlightPtr = nullptr;

    for (auto& flight : flights) {
        if (flight.getFlightID() == oldTicket.getFlightID()) {
            oldFlightPtr = &flight;
        }
        if (flight.getFlightID() == newFlightID) {
            newFlightPtr = &flight;
        }
    }

    if (oldFlightPtr && newFlightPtr && newFlightPtr->getAvailableSeats() > 0) {
        oldFlightPtr->cancelSeat();          
        newFlightPtr->bookSeat();           
        PricingEngine::adjustSurge(*newFlightPtr);

        oldTicket.setFlightID(newFlightID);
        oldTicket.setSeatNumber(newFlightPtr->getTotalSeats() - newFlightPtr->getAvailableSeats());
        oldTicket.setPrice(PricingEngine::calculatePrice(*newFlightPtr, daysToDeparture));

        saveAll();

        std::cout << " Ticket Modified Successfully!\n";
        oldTicket.display();
        return true;
    }

    std::cout << " New flight not available.\n";
    return false;
}


bool ReservationSystem::cancelTicket(const std::string& bookingID) {
    std::lock_guard<std::mutex> lock(mtx);

    if (tickets.find(bookingID) == tickets.end()) return false;

    std::string flightID = tickets[bookingID].getFlightID();

    for (auto& flight : flights) {
        if (flight.getFlightID() == flightID) {
            flight.cancelSeat();
            tickets.erase(bookingID);
            saveAll();
            std::cout << " Ticket Cancelled.\n";

            
            while (!waitlist.empty()) {
                PriorityBooking pb = waitlist.top();
                if (pb.flightID == flightID) {
                    waitlist.pop();
                    std::cout << "💺 Seat reassigned to waitlisted passenger: " << pb.passengerName << "\n";
                    bookTicketByFlightID(pb.flightID, pb.passengerName, 1, pb.priority);
                    break;
                } else {
                    waitlist.pop(); 
                }
            }

            return true;
        }
    }

    return false;
}


void ReservationSystem::printTicket(const std::string& bookingID) const {
    auto it = tickets.find(bookingID);
    if (it != tickets.end()) {
        it->second.display();
    } else {
        std::cout << " Ticket not found.\n";
    }
}

const User& ReservationSystem::getUser(const std::string& name) const {
    auto it = users.find(name);
    if (it != users.end()) return it->second;
    static User dummy;
    return dummy;
}