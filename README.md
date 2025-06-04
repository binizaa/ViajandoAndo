# ViajandoAndo ✈️

ViajandoAndo es una aplicación de consola escrita en C++ que simula un sistema de gestión de reservas para un aeropuerto. Permite a los usuarios:

- Acceder a sus reservas de avión.
- Consultar y seleccionar asientos disponibles en distintos vuelos.
- Gestionar datos relacionados con vuelos y usuarios.

## 📁 Estructura del Proyecto

```
ViajandoAndo/
├── BaseData/
│   ├── flightData.csv             # Datos de vuelos
│   ├── userData.csv               # Datos de usuarios
│   └── userReservation/
│       └── <id>.csv               # Reservas individuales por usuario
├── include/
│   ├── Aplication.h
│   ├── ClientData.h
│   ├── DataBase.h
│   ├── Flight.h
│   ├── FlightData.h
│   ├── Reservation.h
│   ├── ReservationData.h
│   └── User.h
├── src/
│   ├── Aplication.cpp
│   ├── FlightData.cpp
│   ├── ReservationData.cpp
│   └── main.cpp                   # Punto de entrada
├── CMakeLists.txt
└── README.md
```

## 🛠️ Requisitos

- CMake >= 3.10
- Compilador C++ (se recomienda `g++` con soporte C++17)

## 🚀 Instrucciones para Compilar y Ejecutar

### 1. Crear carpeta de compilación

Desde la raíz del proyecto:

```bash
mkdir build
cd build
cmake ..
make
```

Esto genera el ejecutable `main`.

### 2. Ejecutar el programa

```bash
./main
```

> Nota: Asegúrate de ejecutar desde el directorio `build/`, o adaptar las rutas de los archivos `.csv` si el programa no encuentra los datos.

## 📌 Consideraciones

- Los archivos `.csv` dentro de `BaseData/` contienen los datos iniciales.
- Las reservas se guardan en `BaseData/userReservation/` con el nombre `<idUsuario>.csv`.

## 👨‍💻 Autor

Este proyecto fue desarrollado como ejercicio de programación orientada a objetos en C++.
