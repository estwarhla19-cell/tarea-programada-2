#ifndef NODO_HPP
#define NODO_HPP

#include "Vehiculo.hpp"

class Lista;
class IteradorLista;

// Nodo de la lista enlazada simple de solicitudes.
class Nodo {
private:
    Vehiculo dato;
    Nodo* siguiente;

public:
    Nodo(const Vehiculo& dato);

    // Solo la lista y su iterador manipulan los enlaces.
    friend class Lista;
    friend class IteradorLista;
};

#endif