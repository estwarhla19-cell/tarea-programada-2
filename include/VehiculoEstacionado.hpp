#ifndef VEHICULOESTACIONADO_HPP
#define VEHICULOESTACIONADO_HPP
#include <string>
#include "Vehiculo.hpp"
using namespace std;
class VehiculoEstacionado : public Vehiculo {
private:
    int fila; int columna; string idEncargado;
public:
    VehiculoEstacionado();
    VehiculoEstacionado(const Vehiculo& v, int f, int c, const string& encargado);
    int getFila() const; int getColumna() const; string getIdEncargado() const;
    double calcularMonto(int horas) const; string toString() const;
};
#endif
