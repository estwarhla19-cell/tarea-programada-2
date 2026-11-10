#ifndef ITERADORCIRCULAR_HPP
#define ITERADORCIRCULAR_HPP
#include "NodoCircular.hpp"
class IteradorCircular {
private:
    NodoCircular* actual;
    NodoCircular* inicio;
    int restantes;
public:
    IteradorCircular(NodoCircular* inicio, int cantidad);
    Encargado& operator*() const;
    IteradorCircular& operator++();
    bool operator!=(const IteradorCircular& otro) const;
    bool operator==(const IteradorCircular& otro) const;
};
#endif
