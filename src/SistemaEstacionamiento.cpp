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
    if (solicitudes.buscarPorPlaca(placa) != nullptr) {
        throw logic_error("La placa ya esta registrada en espera.");
    }
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

    Vehiculo v = solicitudes.procesarPrimera();
    Encargado& enc = encargados.getActual();
    VehiculoEstacionado ve(v, f, c, enc.getId());
    estacionados.agregar(ve);
    matriz->ocupar(f, c);
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
    
    matriz->liberar(f, c);
    estacionados.eliminar(placa);
    totalRecaudado += monto;
    
    cout << "Vehiculo " << placa << " retirado." << endl;
    cout << "Monto a pagar: " << monto << " colones" << endl;
    cout << "Espacio (" << f+1 << "," << c+1 << ") liberado." << endl;
}

void SistemaEstacionamiento::mostrarReporte() const {
    cout << "\n--- REPORTE GENERAL ---" << endl;
    cout << "Solicitudes pendientes: " << solicitudes.getCantidad() << endl;
    cout << "Vehiculos estacionados: " << estacionados.getCantidad() << endl;
    cout << "Automoviles estacionados: " << estacionados.contarPorTipo("Automovil") << endl;
    cout << "Motocicletas estacionadas: " << estacionados.contarPorTipo("Motocicleta") << endl;
    cout << "Espacios ocupados: " << matriz->getOcupados() << endl;
    cout << "Espacios libres: " << matriz->getLibres() << endl;
    cout << "Porcentaje de ocupacion: " << matriz->porcentajeOcupacion() << "%" << endl;
    cout << "Total recaudado: " << totalRecaudado << " colones" << endl;
    
    cout << "\nVehiculos atendidos por encargado:" << endl;
    for (IteradorCircular it = encargados.begin(); it != encargados.end(); ++it) {
        cout << (*it).toString() << endl;
    }
}

void SistemaEstacionamiento::mostrarMatriz() const {
    matriz->mostrar();
}
