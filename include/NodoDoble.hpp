#ifndef NODODOBLE_HPP
#define NODODOBLE_HPP
#include "VehiculoEstacionado.hpp"
class ListaEstacionamiento; class IteradorDoble;
class NodoDoble {
private:
    VehiculoEstacionado dato; NodoDoble* siguiente; NodoDoble* anterior;
public:
    NodoDoble(const VehiculoEstacionado& dato);
    friend class ListaEstacionamiento; friend class IteradorDoble;
};
#endif
