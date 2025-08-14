#include "ReservationSystem.h"
#include <thread>
#include <vector>
#include <iostream>
#include <mutex>

std::mutex coutMutex;  // Global mutex for thread-safe output

// Booking thread function
void simulateBooking(ReservationSystem& system, const std::string& flightID,
                     const std::string& passengerName, int daysToDeparture) {
    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "🧵 Thread started for " << passengerName << "\n";
    }

    system.bookTicketByFlightID(flightID, passengerName, daysToDeparture);
}

void runBookingSimulation(ReservationSystem& system) {
    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "\n🚦 Starting multi-threaded booking simulation...\n";
    }

    std::vector<std::thread> threads;

    // Simulate 5 concurrent bookings on flight F101
    threads.emplace_back(simulateBooking, std::ref(system), "F101", "Alice", 2);
    threads.emplace_back(simulateBooking, std::ref(system), "F101", "Bob", 2);
    threads.emplace_back(simulateBooking, std::ref(system), "F101", "Charlie", 2);
    threads.emplace_back(simulateBooking, std::ref(system), "F101", "David", 2);
    threads.emplace_back(simulateBooking, std::ref(system), "F101", "Eve", 2);

    // Wait for all threads to finish
    for (auto& t : threads) {
        t.join();
    }

    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "✅ Multi-threaded simulation completed.\n";
    }
}
