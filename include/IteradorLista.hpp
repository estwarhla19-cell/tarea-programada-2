#ifndef ITERADORLISTA_HPP
#define ITERADORLISTA_HPP

#include "Nodo.hpp"

class IteradorLista {
private:
    Nodo* actual;

public:
    explicit IteradorLista(Nodo* inicio);

    Vehiculo& operator*() const;                     // dato del nodo actual
    IteradorLista& operator++();                     // avanza al siguiente nodo
    bool operator!=(const IteradorLista& otro) const;
    bool operator==(const IteradorLista& otro) const;
};

#endif