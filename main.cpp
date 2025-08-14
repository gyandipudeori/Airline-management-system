#include <iostream>
#include <limits>
#include <ios>
#include <windows.h>
#include <string>
#include "ReservationSystem.h"
#include "FileManager.h"
#include <regex>  

void runBookingSimulation(ReservationSystem& system); 

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getPositiveInput(const std::string& prompt) {
    int val;
    while (true) {
        std::cout << prompt;
        if (std::cin >> val && val >= 0) return val;
        std::cout << "Invalid input. Please enter a non-negative number.\n";
        clearInputBuffer();
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    ReservationSystem system;

    std::cout << " Loading flight and ticket data...\n";
    system.loadFlights();
    system.loadTickets();
    std::cout << " System Ready.\n\n";

    int choice;
    do {
        std::cout << "\n============ Airline Reservation System ============\n";
        std::cout << "1. View Available Flights\n";
        std::cout << "2. Book a Ticket\n";
        std::cout << "3. Modify a Ticket\n";
        std::cout << "4. Cancel a Ticket\n";
        std::cout << "5. View Ticket by Booking ID\n";
        std::cout << "6. Run Multi-Threaded Booking Simulation\n";
        std::cout << "0. Exit\n";
        std::cout << "====================================================\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        clearInputBuffer();

        switch (choice) {
            case 1:
                system.displayFlights();
                break;

            case 2: {
                std::string origin, destination, date, time, passengerName;
                std::cout << "Enter Origin: ";
                std::getline(std::cin, origin);
                std::cout << "Enter Destination: ";
                std::getline(std::cin, destination);
                std::cout << "Enter Date (YYYY-MM-DD): ";
                std::getline(std::cin, date);
                std::cout << "Enter Time (HH:MM): ";
                std::getline(std::cin, time);

                std::vector<std::string> matchingFlightIDs = system.displayAvailableFlights(origin, destination, date, time);

                if (matchingFlightIDs.empty()) {
                    std::cout << " No flights available for booking.\n";
                    break;
                }

                std::string selectedFlightID;
                std::cout << "Enter Flight ID from above options: ";
                std::getline(std::cin, selectedFlightID);

                // Validate flight ID
                bool isValid = false;
                for (const auto& id : matchingFlightIDs) {
                    if (id == selectedFlightID) {
                        isValid = true;
                        break;
                    }
                }

                if (!isValid) {
                    std::cout << " Invalid Flight ID selected.\n";
                    break;
                }

                do {
                    std::cout << "Enter Passenger Name: ";
                    std::getline(std::cin, passengerName);

                    // Trim
                    passengerName.erase(0, passengerName.find_first_not_of(" \t\n\r\f\v"));
                    passengerName.erase(passengerName.find_last_not_of(" \t\n\r\f\v") + 1);

                    // Validate: only letters and spaces
                    std::regex validNameRegex("^[A-Za-z ]+$");

                    if (passengerName.empty()) {
                        std::cout << " Passenger name cannot be empty. Please try again.\n";
                    } else if (!std::regex_match(passengerName, validNameRegex)) {
                        std::cout << " Invalid name. Only letters and spaces are allowed.\n";
                        passengerName.clear(); // Force loop again
                    }
                } while (passengerName.empty());

                int daysToDeparture = getPositiveInput("Enter Days to Departure: ");

                std::string bookingID = system.bookTicketByFlightID(selectedFlightID, passengerName, daysToDeparture);
                if (!bookingID.empty()) {
                    std::cout << " Booking successful. Booking ID: " << bookingID << "\n";

                    
                    const auto& user = system.getUser(passengerName);
                    std::cout << " Frequent Flyer Updated:\n";
                    std::cout << "Code  : " << user.code << "\n";
                    std::cout << "Points: " << user.points << "\n";
                    std::cout << "Tier  : " << user.getTier() << "\n";

                    system.saveAll();
                } else {
                    std::cout << " Booking failed. Please try again.\n";
                }

                break;
            }


            case 3: {
                std::string bookingID, newFlightID;
                std::cout << "Enter Booking ID: ";
                std::getline(std::cin, bookingID);
                std::cout << "Enter New Flight ID: ";
                std::getline(std::cin, newFlightID);
                int days = getPositiveInput("Enter Days Before New Departure: ");

                clearInputBuffer();

                if (system.modifyTicket(bookingID, newFlightID, days))
                    system.saveAll();
                else
                    std::cout << " Modification Failed.\n";
                break;
            }

            case 4: {
                std::string bookingID;
                std::cout << "Enter Booking ID to Cancel: ";
                std::getline(std::cin, bookingID);

                if (system.cancelTicket(bookingID)) {
                    std::cout << " Ticket Cancelled.\n";
                    system.saveAll();
                } else {
                    std::cout << " Booking ID not found.\n";
                }
                break;
            }

            case 5: {
                std::string bookingID;
                std::cout << "Enter Booking ID: ";
                std::getline(std::cin, bookingID);
                system.printTicket(bookingID);
                break;
            }

            case 6:
            runBookingSimulation(system);
            break;


            case 0:
                std::cout << " Exiting... Thank you!\n";
                break;

            default:
                std::cout << " Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
