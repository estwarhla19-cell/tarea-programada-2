#ifndef ENCARGADO_HPP
#define ENCARGADO_HPP
#include <string>
using namespace std;

class Encargado {
private:
    string identificador;
    string nombre;
    int cantidadVehiculos;
public:
    Encargado();
    Encargado(const string& id, const string& nombre);
    string getId() const;
    string getNombre() const;
    int getCantidadVehiculos() const;
    void incrementarAtendidos();
    string toString() const;
};
#endif
