#ifndef NODOCIRCULAR_HPP
#define NODOCIRCULAR_HPP
#include "Encargado.hpp"

class ListaCircular;
class IteradorCircular;

class NodoCircular {
private:
    Encargado dato;
    NodoCircular* siguiente;
public:
    NodoCircular(const Encargado& dato);
    friend class ListaCircular;
    friend class IteradorCircular;
};
#endif
