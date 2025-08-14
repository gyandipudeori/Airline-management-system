#include "Flight.h"
#include <iomanip>
#include <stdexcept>
#include <cmath>

Flight::Flight(std::string id, std::string org, std::string dest, std::string d, std::string t,
               int total, int available, float fare, float surge)
    : flightID(id), origin(org), destination(dest), date(d), time(t),
      totalSeats(total), availableSeats(available), baseFare(fare), surgeMultiplier(surge) {}

std::string Flight::getFlightID() const { return flightID; }
std::string Flight::getOrigin() const { return origin; }
std::string Flight::getDestination() const { return destination; }
std::string Flight::getDate() const { return date; }
std::string Flight::getTime() const { return time; }
int Flight::getTotalSeats() const { return totalSeats; }
int Flight::getAvailableSeats() const { return availableSeats; }
float Flight::getBaseFare() const { return baseFare; }
float Flight::getSurgeMultiplier() const { return surgeMultiplier; }

void Flight::setSurgeMultiplier(float surge) {
    surgeMultiplier = std::max(1.0f, surge);  
}

void Flight::updateSurgeMultiplier(float delta) {
    surgeMultiplier += delta;
    if (surgeMultiplier < 1.0f) surgeMultiplier = 1.0f;
}

void Flight::bookSeat() {
    if (availableSeats <= 0) throw std::runtime_error("No available seats on this flight.");
    availableSeats--;
}

void Flight::cancelSeat() {
    if (availableSeats >= totalSeats) throw std::runtime_error("All seats already available.");
    availableSeats++;
}

void Flight::display() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Flight ID: " << flightID << "\n"
              << "Route: " << origin << " -> " << destination << "\n"
              << "Date: " << date << "  Time: " << time << "\n"
              << "Seats: " << availableSeats << "/" << totalSeats << "\n"
              << "Base Fare: Rs " << baseFare << "\n"
              << "Surge Multiplier: x" << surgeMultiplier << "\n"
              << "---------------------------------------------\n";
}

float Flight::getOccupancyRate() const {
    return 1.0f - (static_cast<float>(availableSeats) / totalSeats);
}

float Flight::calculateDynamicPrice(int daysToDeparture) const {
    float demandFactor = getOccupancyRate();  
    float timingFactor = (daysToDeparture <= 0) ? 1.0f : (1.0f / daysToDeparture); 

    float finalPrice = baseFare +
                       (baseFare * demandFactor * 0.5f) +
                       (baseFare * timingFactor * 0.5f);

    finalPrice *= surgeMultiplier;

    return finalPrice;
}