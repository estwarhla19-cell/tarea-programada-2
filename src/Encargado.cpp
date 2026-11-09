#include "Encargado.hpp"

Encargado::Encargado() : identificador(""), nombre(""), cantidadVehiculos(0) {}
Encargado::Encargado(const string& id, const string& nombre) : identificador(id), nombre(nombre), cantidadVehiculos(0) {}

string Encargado::getId() const { return identificador; }
string Encargado::getNombre() const { return nombre; }
int Encargado::getCantidadVehiculos() const { return cantidadVehiculos; }
void Encargado::incrementarAtendidos() { cantidadVehiculos++; }

string Encargado::toString() const {
    return identificador + " " + nombre + ": " + to_string(cantidadVehiculos);
}
