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

void SistemaEstacionamiento::procesarSiguiente() {
    if (solicitudes.estaVacia()) {
        throw underflow_error("No hay solicitudes pendientes.");
    }
    
    int f, c;
    if (!matriz->buscarDisponible(f, c)) {
        throw overflow_error("No hay espacios disponibles.");
    }
    
    if (encargados.estaVacia()) {
        throw logic_error("No hay encargados registrados.");
    }

    // Sacar de la lista simple
    Vehiculo v = solicitudes.procesarPrimera();
    
    // Obtener encargado actual
    Encargado& enc = encargados.getActual();
    
    // Registrar en lista doble
    VehiculoEstacionado ve(v, f, c, enc.getId());
    estacionados.agregar(ve);
    
    // Ocupar matriz
    matriz->ocupar(f, c);
    
    // Actualizar encargado y avanzar turno
    enc.incrementarAtendidos();
    encargados.avanzarTurno();
    
    cout << "Solicitud: " << v.getPlaca() << " ingreso al espacio (" << f+1 << "," << c+1 << ")" << endl;
    cout << "Encargado: " << enc.getNombre() << endl;
}

void SistemaEstacionamiento::registrarSalida(const string& placa, int horas) {
    if (horas <= 0) {
        throw invalid_argument("Las horas deben ser mayores que cero.");
    }
    
    VehiculoEstacionado* ve = estacionados.buscar(placa);
    if (ve == nullptr) {
        throw out_of_range("Vehiculo no encontrado.");
    }
    
    double monto = ve->calcularMonto(horas);
    int f = ve->getFila();
    int c = ve->getColumna();
    
    // Liberar espacio en matriz y eliminar de lista doble
    matriz->liberar(f, c);
    estacionados.eliminar(placa);
    
    totalRecaudado += monto;
    
    cout << "Vehiculo " << placa << " retirado." << endl;
    cout << "Monto a pagar: " << monto << " colones" << endl;
    cout << "Espacio (" << f+1 << "," << c+1 << ") liberado." << endl;
}
