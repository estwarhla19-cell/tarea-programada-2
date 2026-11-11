#ifndef SISTEMAESTACIONAMIENTO_HPP
#define SISTEMAESTACIONAMIENTO_HPP
#include "Lista.hpp"
#include "ListaEstacionamiento.hpp"
#include "ListaCircular.hpp"
#include "MatrizEspacios.hpp"
#include <string>
using namespace std;

class SistemaEstacionamiento {
private:
    Lista solicitudes;
    ListaEstacionamiento estacionados;
    ListaCircular encargados;
    MatrizEspacios* matriz;
    double totalRecaudado;

public:
    SistemaEstacionamiento(int filas, int columnas);
    ~SistemaEstacionamiento();

    void registrarEncargado(const string& id, const string& nombre);
    void registrarSolicitud(const string& placa, const string& propietario, const string& tipo);
    void procesarSiguiente();
    void registrarSalida(const string& placa, int horas);
    void mostrarReporte() const;
    void mostrarMatriz() const;
};
#endif
