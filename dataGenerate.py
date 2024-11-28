import pandas as pd
import random
from datetime import datetime, timedelta

# Función para generar el estado de los asientos del avión
def generate_seat_map():
    seat_map = []
    for i in range(6):  # 6 filas de asientos (A, B, C, D, E, F)
        # Usamos random.choices() para dar más probabilidad a los puntos (.)
        row = ''.join(random.choices(['.', 'X'], weights=[80, 20], k=30))  # 80% de probabilidad para '.', 20% para 'X'
        seat_map.append(row)
    return seat_map

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
        duration = random.randint(1, 12)  # Duración entre 1 y 12 horas
        date = (datetime.now() + timedelta(days=random.randint(0, 365))).strftime("%Y-%m-%d")
        origin = random.choice(origins)
        destination = random.choice(destinations)
        while destination == origin:  # Evitar que el destino sea el mismo que el origen
            destination = random.choice(destinations)

        # Generar el mapa de asientos
        seat_map = generate_seat_map()

        # Añadir los datos del vuelo con el mapa de asientos
        flights.append([flight_number, airline, price, duration, date, origin, destination] + seat_map)

    return flights

# Crear un DataFrame con los datos actualizados
flight_data_decimals = generate_flight_data_with_decimals(100)
columns = ["Flight Number", "Airline", "Price", "Duration (hrs)", "Date", "Origin", "Destination", "Seat Row 1", "Seat Row 2", "Seat Row 3", "Seat Row 4", "Seat Row 5", "Seat Row 6"]

df_decimals = pd.DataFrame(flight_data_decimals, columns=columns)

# Guardar el DataFrame en un archivo CSV
df_decimals.to_csv("flightData.csv", index=False)

print("CSV generado correctamente con los datos de los vuelos y los mapas de asientos.")
