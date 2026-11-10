#ifndef LISTA_HPP
#define LISTA_HPP

#include "Nodo.hpp"
#include "IteradorLista.hpp"

// Lista enlazada simple que administra las solicitudes de ingreso.
class Lista {
private:
    Nodo* cabeza;
    Nodo* cola;
    int cantidad;
    int contadorSolicitudes;   // genera el número de solicitud automáticamente

public:
    Lista();
    ~Lista();

    void registrar(const string& placa, const string& propietario,
                   const string& tipo);
    bool cancelar(const string& placa);
    
    // Esta es la declaración que faltaba
    Vehiculo procesarPrimera();

    int getCantidad() const;
    bool estaVacia() const;

    // Iteración
    IteradorLista begin() const;   // primer elemento
    IteradorLista end() const;     // posición "después del último"

    // Operaciones implementadas con el iterador (sin tocar nodos)
    Vehiculo* buscarPorPlaca(const string& placa) const;   // nullptr si no existe
    int contarPorTipo(const string& tipo) const;
};

#endif