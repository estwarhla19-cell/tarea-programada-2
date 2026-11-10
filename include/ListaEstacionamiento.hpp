#ifndef LISTAESTACIONAMIENTO_HPP
#define LISTAESTACIONAMIENTO_HPP
#include "NodoDoble.hpp"
#include "IteradorDoble.hpp"
class ListaEstacionamiento {
private:
    NodoDoble* cabeza; 
    NodoDoble* cola; 
    int cantidad;
public:
    ListaEstacionamiento(); 
    ~ListaEstacionamiento();
    void agregar(const VehiculoEstacionado& v); 
    bool eliminar(const string& placa);
    VehiculoEstacionado* buscar(const string& placa) const;
    int getCantidad() const; 
    int contarPorTipo(const string& tipo) const;
    IteradorDoble begin() const; 
    IteradorDoble end() const;
    IteradorDoble rbegin() const; 
    IteradorDoble rend() const;
};
#endif
