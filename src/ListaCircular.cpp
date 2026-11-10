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
Encargado& ListaCircular::getActual() const { return actual->dato; }
void ListaCircular::avanzarTurno() { if (actual != nullptr) actual = actual->siguiente; }
bool ListaCircular::eliminar(const string& id) {
    if (actual == nullptr) return false;
    NodoCircular* anterior = nullptr; NodoCircular* temp = actual;
    do {
        if (temp->dato.getId() == id) {
            if (temp == actual && temp->siguiente == actual) { delete temp; actual = nullptr; cantidad--; return true; }
            if (temp == actual) {
                NodoCircular* ultimo = actual;
                while (ultimo->siguiente != actual) ultimo = ultimo->siguiente;
                actual = actual->siguiente; ultimo->siguiente = actual; delete temp; cantidad--; return true;
            }
            if (anterior != nullptr) { anterior->siguiente = temp->siguiente; delete temp; cantidad--; return true; }
        }
        anterior = temp; temp = temp->siguiente;
    } while (temp != actual);
    return false;
}
