#include "VehiculoEstacionado.hpp"
VehiculoEstacionado::VehiculoEstacionado() : Vehiculo(), fila(0), columna(0), idEncargado("") {}
VehiculoEstacionado::VehiculoEstacionado(const Vehiculo& v, int f, int c, const string& encargado) : Vehiculo(v.getNumeroSolicitud(), v.getPlaca(), v.getPropietario(), v.getTipo()), fila(f), columna(c), idEncargado(encargado) {}
int VehiculoEstacionado::getFila() const { return fila; }
int VehiculoEstacionado::getColumna() const { return columna; }
string VehiculoEstacionado::getIdEncargado() const { return idEncargado; }
double VehiculoEstacionado::calcularMonto(int horas) const { return horas * ((getTipo() == "Automovil") ? 900.0 : 500.0); }
string VehiculoEstacionado::toString() const { return getPlaca() + " (" + to_string(fila) + "," + to_string(columna) + ") " + idEncargado; }
