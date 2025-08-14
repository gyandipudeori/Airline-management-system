#ifndef PRICING_ENGINE_H
#define PRICING_ENGINE_H

#include "Flight.h"

class PricingEngine {
public:
    // Calculate dynamic price for a given flight and days before departure
    static float calculatePrice(const Flight& flight, int daysToDeparture);

    // Adjust surge multiplier based on flight occupancy
    static float adjustSurge(Flight& flight);
};

#endif
