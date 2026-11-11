#include <cassert>
#include <iostream>
#include "Lista.hpp"
#include "ListaEstacionamiento.hpp"
#include "ListaCircular.hpp"
#include "MatrizEspacios.hpp"

using namespace std;

void probarListaSimple() {
    Lista lista;
    lista.registrar("ABC123", "Carlos", "Automovil");
    assert(lista.getCantidad() == 1); // Prueba 1
    assert(lista.buscarPorPlaca("ABC123") != nullptr); // Prueba 2
    lista.cancelar("ABC123");
    assert(lista.estaVacia()); // Prueba 3
    cout << "Pruebas Lista Simple: OK" << endl;
}

void probarListaDoble() {
    ListaEstacionamiento lista;
    Vehiculo v(1, "XYZ789", "Pedro", "Automovil");
    VehiculoEstacionado ve(v, 0, 0, "E01");
    lista.agregar(ve);
    assert(lista.getCantidad() == 1); // Prueba 4
    assert(lista.buscar("XYZ789") != nullptr); // Prueba 5
    lista.eliminar("XYZ789");
    assert(lista.getCantidad() == 0); // Prueba 6
    cout << "Pruebas Lista Doble: OK" << endl;
}

void probarListaCircular() {
    ListaCircular lista;
    lista.registrar(Encargado("E01", "Ana"));
    lista.registrar(Encargado("E02", "Luis"));
    assert(lista.getCantidad() == 2); // Prueba 7
    assert(lista.getActual().getNombre() == "Ana"); // Prueba 8
    lista.avanzarTurno();
    assert(lista.getActual().getNombre() == "Luis"); // Prueba 9
    cout << "Pruebas Lista Circular: OK" << endl;
}

void probarMatriz() {
    MatrizEspacios matriz(2, 2);
    assert(matriz.getLibres() == 4); // Prueba 10
    int f, c;
    assert(matriz.buscarDisponible(f, c)); // Prueba 11
    matriz.ocupar(0, 0);
    assert(matriz.getOcupados() == 1); // Prueba 12
    matriz.liberar(0, 0);
    assert(matriz.getOcupados() == 0); // Prueba 13
    cout << "Pruebas Matriz: OK" << endl;
}

int main() {
    cout << "\n--- EJECUTANDO PRUEBAS DEL SISTEMA ---" << endl;
    probarListaSimple();
    probarListaDoble();
    probarListaCircular();
    probarMatriz();
    cout << "Todas las 13 pruebas pasaron correctamente." << endl;
    return 0;
}
