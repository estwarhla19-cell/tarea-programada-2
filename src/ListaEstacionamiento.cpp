#include "ListaEstacionamiento.hpp"
ListaEstacionamiento::ListaEstacionamiento() : cabeza(nullptr), cola(nullptr), cantidad(0) {}
ListaEstacionamiento::~ListaEstacionamiento() {
    NodoDoble* actual = cabeza;
    while (actual != nullptr) { NodoDoble* aBorrar = actual; actual = actual->siguiente; delete aBorrar; }
}
void ListaEstacionamiento::agregar(const VehiculoEstacionado& v) {
    NodoDoble* nuevo = new NodoDoble(v);
    if (cabeza == nullptr) { cabeza = nuevo; cola = nuevo; }
    else { cola->siguiente = nuevo; nuevo->anterior = cola; cola = nuevo; }
    cantidad++;
}
bool ListaEstacionamiento::eliminar(const string& placa) {
    NodoDoble* actual = cabeza;
    while (actual != nullptr && actual->dato.getPlaca() != placa) actual = actual->siguiente;
    if (actual == nullptr) return false;
    if (actual == cabeza && actual == cola) { cabeza = nullptr; cola = nullptr; }
    else if (actual == cabeza) { cabeza = actual->siguiente; cabeza->anterior = nullptr; }
    else if (actual == cola) { cola = actual->anterior; cola->siguiente = nullptr; }
    else { actual->anterior->siguiente = actual->siguiente; actual->siguiente->anterior = actual->anterior; }
    delete actual; cantidad--; return true;
}
VehiculoEstacionado* ListaEstacionamiento::buscar(const string& placa) const {
    for (IteradorDoble it = begin(); it != end(); ++it) if ((*it).getPlaca() == placa) return &(*it);
    return nullptr;
}
int ListaEstacionamiento::getCantidad() const { return cantidad; }
int ListaEstacionamiento::contarPorTipo(const string& tipo) const {
    int c = 0; for (IteradorDoble it = begin(); it != end(); ++it) if ((*it).getTipo() == tipo) c++;
    return c;
}
IteradorDoble ListaEstacionamiento::begin() const { return IteradorDoble(cabeza); }
IteradorDoble ListaEstacionamiento::end() const { return IteradorDoble(nullptr); }
IteradorDoble ListaEstacionamiento::rbegin() const { return IteradorDoble(cola); }
IteradorDoble ListaEstacionamiento::rend() const { return IteradorDoble(nullptr); }
