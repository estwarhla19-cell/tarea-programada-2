# Sistema de Administración de Estacionamiento Inteligente

**Curso:** Programación II
**Lenguaje:** C++


## Descripción del Proyecto
Sistema desarrollado para gestionar el ingreso, salida y control de espacios en un estacionamiento. El proyecto integra múltiples estructuras de datos dinámicas implementadas desde cero, junto con el uso de iteradores propios, memoria dinámica y manejo de excepciones.

## Estructuras Implementadas
1. **Lista Enlazada Simple:** Gestión de solicitudes de ingreso (espera).
2. **Lista Doblemente Enlazada:** Control de vehículos actualmente estacionados (con recorrido bidireccional).
3. **Lista Enlazada Circular:** Rotación equitativa de los encargados del estacionamiento.
4. **Matriz Dinámica:** Representación física de los espacios del estacionamiento (ocupado/libre).

## Instrucciones de Compilación y Ejecución
Para compilar el proyecto, abra la terminal en la raíz del repositorio y ejecute:
g++ -std=c++17 src/*.cpp -I include -o app
./app

## Autor
-Jordan Loria
-C5G645

## Para compilar y ejecutar las pruebas automatizadas 
g++ -std=c++17 tests/test_estructuras.cpp src/*.cpp -I include -o test_app
./test_app