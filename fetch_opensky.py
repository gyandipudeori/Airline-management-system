import requests
from datetime import datetime, timezone
import os

# API URL for OpenSky data
url = "https://opensky-network.org/api/states/all"

print("🔍 Fetching flight data...")
response = requests.get(url)
data = response.json()

states = data.get("states", [])
print(f"✅ Retrieved {len(states)} aircraft from OpenSky")

# Select top 100 flights with valid data
filtered = []
for s in states:
    if s[2] and s[3] and s[5] and s[6] and s[1]:  # Check for origin country, time, lat/lon, callsign
        date = datetime.now(timezone.utc).strftime("%Y-%m-%d")
        time_str = datetime.fromtimestamp(s[3] or s[4] or datetime.now(timezone.utc).timestamp(), timezone.utc).strftime("%H:%M")

        flight = {
            "flight_id": s[1].strip(),
            "origin": s[2],
            "destination": "TBD",  # Unknown
            "date": date,
            "time": time_str,
            "capacity": 180,
            "seats_available": 180,
            "base_fare": 5000,
            "surge": 1.0
        }
        filtered.append(flight)
    if len(filtered) >= 100:
        break

# ✅ Write to data/flights.txt
os.makedirs("data", exist_ok=True)
with open("data/flights.txt", "w", encoding="utf-8") as f:
    for fli in filtered:
        line = f"{fli['flight_id']},{fli['origin']},{fli['destination']},{fli['date']},{fli['time']},{fli['capacity']},{fli['seats_available']},{fli['base_fare']},{fli['surge']}\n"
        f.write(line)

print("✅ Saved 100 entries to data/flights.txt")
