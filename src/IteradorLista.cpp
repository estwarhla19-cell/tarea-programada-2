#include "IteradorLista.hpp"

IteradorLista::IteradorLista(Nodo* inicio) : actual(inicio) {}

Vehiculo& IteradorLista::operator*() const {
    return actual->dato;
}

IteradorLista& IteradorLista::operator++() {
    if (actual != nullptr) {
        actual = actual->siguiente;
    }
    return *this;
}

bool IteradorLista::operator!=(const IteradorLista& otro) const {
    return actual != otro.actual;
}

bool IteradorLista::operator==(const IteradorLista& otro) const {
    return actual == otro.actual;
}