#ifndef ITERADORDOBLE_HPP
#define ITERADORDOBLE_HPP
#include "NodoDoble.hpp"
class IteradorDoble {
private:
    NodoDoble* actual;
public:
    explicit IteradorDoble(NodoDoble* inicio);
    VehiculoEstacionado& operator*() const;
    IteradorDoble& operator++(); 
    IteradorDoble& operator--();
    bool operator!=(const IteradorDoble& otro) const; 
    bool operator==(const IteradorDoble& otro) const;
};
#endif
