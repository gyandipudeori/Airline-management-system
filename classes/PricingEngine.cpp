#include "PricingEngine.h"
#include <cmath>


// all multiplied by current surgeMultiplier
float PricingEngine::calculatePrice(const Flight& flight, int daysToDeparture) {
    float baseFare = flight.getBaseFare();
    float demandFactor = flight.getOccupancyRate();  // 0.0 to 1.0
    float timingFactor = (daysToDeparture <= 0) ? 1.0f : (1.0f / daysToDeparture);

    float demandSurge = baseFare * demandFactor * 0.5f;
    float timingSurge = baseFare * timingFactor * 0.5f;

    float rawPrice = baseFare + demandSurge + timingSurge;
    float surgeMultiplier = flight.getSurgeMultiplier();

    return rawPrice * surgeMultiplier;
}

// Adjust surge multiplier based on current load

float PricingEngine::adjustSurge(Flight& flight) {
    float occupancy = flight.getOccupancyRate();  // 0.0 to 1.0
    float currentSurge = flight.getSurgeMultiplier();

    if (occupancy >= 0.80f) {
        currentSurge += 0.05f;
    } else if (occupancy <= 0.30f) {
        currentSurge -= 0.02f;
    }

    if (currentSurge < 1.0f) currentSurge = 1.0f;

    flight.setSurgeMultiplier(currentSurge);
    return currentSurge;
}
