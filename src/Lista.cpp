#include "Lista.hpp"

Lista::Lista()
    : cabeza(nullptr), cola(nullptr), cantidad(0), contadorSolicitudes(0) {}

Lista::~Lista() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* aBorrar = actual;
        actual = actual->siguiente;
        delete aBorrar;
    }
}

void Lista::registrar(const string& placa, const string& propietario,
                      const string& tipo) {
    contadorSolicitudes++;
    Nodo* nuevo = new Nodo(Vehiculo(contadorSolicitudes, placa,
                                    propietario, tipo));
    if (cabeza == nullptr) {
        cabeza = nuevo;
        cola = nuevo;
    } else {
        cola->siguiente = nuevo;
        cola = nuevo;
    }
    cantidad++;
}

// Elimina la solicitud con esa placa, esté al inicio, en medio o al final.
// Retorna false si la placa no existe.
bool Lista::cancelar(const string& placa) {
    Nodo* anterior = nullptr;
    Nodo* actual = cabeza;

    while (actual != nullptr && actual->dato.getPlaca() != placa) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) return false;   // no se encontró

    if (anterior == nullptr) {
        cabeza = actual->siguiente;        // era el primero
    } else {
        anterior->siguiente = actual->siguiente;
    }

    if (actual == cola) {
        cola = anterior;                   // era el último
    }

    delete actual;
    cantidad--;
    return true;
}

int Lista::getCantidad() const { return cantidad; }

bool Lista::estaVacia() const { return cantidad == 0; }

IteradorLista Lista::begin() const { return IteradorLista(cabeza); }

IteradorLista Lista::end() const { return IteradorLista(nullptr); }


Vehiculo* Lista::buscarPorPlaca(const string& placa) const {
    for (IteradorLista it = begin(); it != end(); ++it) {
        if ((*it).getPlaca() == placa) {
            return &(*it);
        }
    }
    return nullptr;
}


int Lista::contarPorTipo(const string& tipo) const {
    int contador = 0;
    for (IteradorLista it = begin(); it != end(); ++it) {
        if ((*it).getTipo() == tipo) {
            contador++;
        }
    }
    return contador;
}