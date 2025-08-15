# Airline Reservation System with Dynamic Pricing

##  Project Overview
This is a **console-based Airline Reservation System** implemented in **C++**, featuring **dynamic ticket pricing** and **thread-safe booking simulation**.  
The system allows users to book, modify, and cancel flight tickets while prices adjust based on real-time seat availability and the time remaining before departure.

---

##  Key Features
1. **Ticket Booking**
   - Input: Origin, destination, date, and time.
   - Real-time seat availability check.
   - Dynamic price calculation based on demand and booking date.
   - Generates a **unique booking ID**.

2. **Ticket Modification**
   - Change flight, time, or passenger details.
   - Recalculate updated ticket price.
   - Adjust seat counts accordingly.

3. **Ticket Cancellation**
   - Cancel using the booking ID.
   - Refund logic (basic or time-based).
   - Seats returned to availability.

4. **Dynamic Pricing Algorithm**
   - Price increases as seats become scarce.
   - Price increases as departure date approaches.
   - Formula:
     ```
     Final Price = Base Fare + Demand Component + Timing Component
     ```
     where:
     - **Demand Component** = Surge based on `(1 - availableSeats / totalSeats)`
     - **Timing Component** = Surge based on `daysToDeparture`

5. **Thread-Safe Multi-User Simulation**
   - Uses **mutex locks** to ensure safe concurrent booking.
   - Prevents race conditions in seat allocation and pricing.

---

## 🛠 Tools & Technologies
- **Language**: C++
- **Threading**: `std::thread`, `std::mutex`
- **File Handling**: For saving and loading flight/ticket data
- **OOP Principles**: Classes for `Flight`, `Ticket`, `ReservationSystem`, `PricingEngine`, etc.



