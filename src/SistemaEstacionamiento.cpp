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

void SistemaEstacionamiento::registrarSolicitud(const string& placa, const string& propietario, const string& tipo) {
    // Validar que la placa no esté en espera
    if (solicitudes.buscarPorPlaca(placa) != nullptr) {
        throw logic_error("La placa ya esta registrada en espera.");
    }
    // Validar que no esté estacionada
    if (estacionados.buscar(placa) != nullptr) {
        throw logic_error("La placa ya esta registrada en el estacionamiento.");
    }
    solicitudes.registrar(placa, propietario, tipo);
    cout << "Solicitud registrada correctamente." << endl;
}
