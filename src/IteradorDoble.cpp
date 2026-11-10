#include "IteradorDoble.hpp"
IteradorDoble::IteradorDoble(NodoDoble* inicio) : actual(inicio) {}
VehiculoEstacionado& IteradorDoble::operator*() const { return actual->dato; }
IteradorDoble& IteradorDoble::operator++() { if (actual != nullptr) actual = actual->siguiente; return *this; }
IteradorDoble& IteradorDoble::operator--() { if (actual != nullptr) actual = actual->anterior; return *this; }
bool IteradorDoble::operator!=(const IteradorDoble& otro) const { return actual != otro.actual; }
bool IteradorDoble::operator==(const IteradorDoble& otro) const { return actual == otro.actual; }
