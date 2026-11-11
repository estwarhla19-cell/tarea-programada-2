#include "SistemaEstacionamiento.hpp"
#include <iostream>
#include <stdexcept>

SistemaEstacionamiento::SistemaEstacionamiento(int filas, int columnas) {
    matriz = new MatrizEspacios(filas, columnas);
    totalRecaudado = 0.0;
}

SistemaEstacionamiento::~SistemaEstacionamiento() {
    delete matriz;
}

void SistemaEstacionamiento::registrarEncargado(const string& id, const string& nombre) {
    Encargado e(id, nombre);
    encargados.registrar(e);
    cout << "Encargado registrado: " << nombre << endl;
}
