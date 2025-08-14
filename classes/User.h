#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <sstream>

class User {
public:
    std::string name;
    std::string code;
    int points = 0;
    std::vector<std::string> bookings;

    User() = default;

    std::string getTier() const {
        if (points >= 500) return "Gold";
        if (points >= 200) return "Silver";
        return "Bronze";
    }

    int getDiscountPercentage() const {
        if (points >= 1000) return 10;
        if (points >= 500) return 5;
        return 0;
    }


    std::string serialize() const {
        std::ostringstream oss;
        oss << code << "," << name << "," << points << "," << getTier() << ",";
        for (size_t i = 0; i < bookings.size(); ++i) {
            oss << bookings[i];
            if (i < bookings.size() - 1) oss << ";";
        }
        return oss.str();
    }

    void deserialize(const std::string& line) {
        std::istringstream ss(line);
        std::string bookingsStr;

        std::getline(ss, code, ',');
        std::getline(ss, name, ',');
        std::string pointsStr;
        std::getline(ss, pointsStr, ',');
        points = std::stoi(pointsStr);

        std::string tier; // Skip reading tier (we calculate it dynamically)
        std::getline(ss, tier, ',');

        std::getline(ss, bookingsStr);
        std::istringstream bs(bookingsStr);
        std::string id;
        while (std::getline(bs, id, ';')) {
            bookings.push_back(id);
        }
    }
};

#endif 