import requests
import random
from datetime import datetime, timedelta

API_KEY = 'f1b812f6847461ac441f3880256c6a9d' 

def fetch_flights():
    url = 'https://airlabs.co/api/v9/schedules'
    params = {
        'api_key': API_KEY,
        'dep_iata': 'DEL',
        'arr_iata': 'BOM',
        'limit': 10
    }

    print("🔍 Fetching flight data...")  # Debug line
    response = requests.get(url, params=params)

    if response.status_code != 200:
        print(f"❌ Error: {response.status_code} - {response.text}")
        return

    data = response.json()
    print(f"✅ Fetched {len(data.get('response', []))} flights")  # Debug line

    lines = []
    for idx, flight in enumerate(data.get('response', [])):
        flight_id = f"F10{idx+1}"
        dep_city = flight.get('dep_city', 'Delhi')
        arr_city = flight.get('arr_city', 'Mumbai')
        date = datetime.today() + timedelta(days=random.randint(1, 5))
        flight_date = date.strftime('%Y-%m-%d')
        flight_time = date.strftime('%H:%M')
        total_seats = random.choice([90, 100, 120])
        available_seats = random.randint(50, total_seats)
        base_fare = random.choice([4500, 4800, 5000])
        surge = round(random.uniform(1.0, 1.5), 2)

        line = f"{flight_id},{dep_city},{arr_city},{flight_date},{flight_time},{total_seats},{available_seats},{base_fare},{surge}"
        lines.append(line)

    if lines:
        with open('flights.txt', 'w', encoding='utf-8') as f:
            f.write('\n'.join(lines))
        print(f"✅ {len(lines)} flights saved to flights.txt")
    else:
        print("⚠️ No flight data available.")

fetch_flights()
