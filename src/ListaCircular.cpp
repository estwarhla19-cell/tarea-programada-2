#include "ListaCircular.hpp"
ListaCircular::ListaCircular() : actual(nullptr), cantidad(0) {}
bool ListaCircular::estaVacia() const { return cantidad == 0; }
int ListaCircular::getCantidad() const { return cantidad; }
void ListaCircular::registrar(const Encargado& e) {
    NodoCircular* nuevo = new NodoCircular(e);
    if (actual == nullptr) { actual = nuevo; actual->siguiente = actual; }
    else {
        NodoCircular* temp = actual;
        while (temp->siguiente != actual) temp = temp->siguiente;
        temp->siguiente = nuevo; nuevo->siguiente = actual;
    }
    cantidad++;
}
