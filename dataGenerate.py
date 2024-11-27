import pandas as pd
import random
from datetime import datetime, timedelta

# Regenerar datos ficticios con precios que puedan tener decimales
def generate_flight_data_with_decimals(num_records=100):
    airlines = ["AirX", "SkyLine", "GlobalWings", "CloudJet", "AeroFly"]
    origins = ["New York", "Los Angeles", "Chicago", "Houston", "Phoenix"]
    destinations = ["Miami", "San Francisco", "Seattle", "Boston", "Denver"]

    flights = []
    flight_number = 0
    for i in range(num_records):
        flight_number = flight_number + 1
        airline = random.choice(airlines)
        price = round(random.uniform(100.00, 1500.99), 2)  # Precio con decimales entre 100.00 y 1500.99
        duration = random.randint(1, 12) 
        date = (datetime.now() + timedelta(days=random.randint(0, 365))).strftime("%Y-%m-%d")
        origin = random.choice(origins)
        destination = random.choice(destinations)
        while destination == origin:  # Evitar que el destino sea el mismo que el origen
            destination = random.choice(destinations)
        flights.append([flight_number, airline, price, duration, date, origin, destination])
    
    return flights

# Crear un DataFrame con los datos actualizados
flight_data_decimals = generate_flight_data_with_decimals(100)
columns = ["Flight Number", "Airline", "Price", "Duration (hrs)", "Date", "Origin", "Destination"]
df_decimals = pd.DataFrame(flight_data_decimals, columns=columns)

# Guardar el DataFrame en un archivo CSV
output_file_decimals = "flight_data.csv"
df_decimals.to_csv(output_file_decimals, index=False)

output_file_decimals
