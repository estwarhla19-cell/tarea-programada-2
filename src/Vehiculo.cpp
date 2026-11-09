#include "Vehiculo.hpp"

Vehiculo::Vehiculo()
    : numeroSolicitud(0), placa(""), propietario(""), tipo("") {}

Vehiculo::Vehiculo(int numeroSolicitud, const string& placa,
                   const string& propietario, const string& tipo)
    : numeroSolicitud(numeroSolicitud), placa(placa),
      propietario(propietario), tipo(tipo) {}

int Vehiculo::getNumeroSolicitud() const { return numeroSolicitud; }
string Vehiculo::getPlaca() const { return placa; }
string Vehiculo::getPropietario() const { return propietario; }
string Vehiculo::getTipo() const { return tipo; }

string Vehiculo::toString() const {
    string num = to_string(numeroSolicitud);
    while (num.size() < 3) num = "0" + num;
    return "S" + num + " " + placa + " " + propietario + " " + tipo;
}