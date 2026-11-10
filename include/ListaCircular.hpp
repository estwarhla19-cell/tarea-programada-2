#ifndef LISTACIRCULAR_HPP
#define LISTACIRCULAR_HPP
#include "NodoCircular.hpp"
#include "IteradorCircular.hpp"
class ListaCircular {
private:
    NodoCircular* actual;
    int cantidad;
public:
    ListaCircular();
    ~ListaCircular();
    void registrar(const Encargado& e);
    bool eliminar(const string& id);
    Encargado& getActual() const;
    void avanzarTurno();
    bool estaVacia() const;
    int getCantidad() const;
    IteradorCircular begin() const;
    IteradorCircular end() const;
};
#endif
