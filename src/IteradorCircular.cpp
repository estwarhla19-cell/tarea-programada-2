#include "IteradorCircular.hpp"
IteradorCircular::IteradorCircular(NodoCircular* inicio, int cantidad) : actual(inicio), inicio(inicio), restantes(cantidad) {}
Encargado& IteradorCircular::operator*() const { return actual->dato; }
IteradorCircular& IteradorCircular::operator++() {
    if (actual != nullptr && restantes > 0) { actual = actual->siguiente; restantes--; }
    return *this;
}
bool IteradorCircular::operator!=(const IteradorCircular& otro) const { return restantes != otro.restantes || actual != otro.actual; }
bool IteradorCircular::operator==(const IteradorCircular& otro) const { return restantes == otro.restantes && actual == otro.actual; }
