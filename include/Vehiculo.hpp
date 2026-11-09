#ifndef VEHICULO_HPP
#define VEHICULO_HPP

#include <string>
using namespace std;


class Vehiculo {
private:
    int numeroSolicitud;
    string placa;
    string propietario;
    string tipo;   // "Automovil" o "Motocicleta"

public:
    Vehiculo();
    Vehiculo(int numeroSolicitud, const string& placa,
             const string& propietario, const string& tipo);

    int getNumeroSolicitud() const;
    string getPlaca() const;
    string getPropietario() const;
    string getTipo() const;

    string toString() const;
};

#endif