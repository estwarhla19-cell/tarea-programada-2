#include "MatrizEspacios.hpp"
#include <iostream>
using namespace std;

MatrizEspacios::MatrizEspacios(int f, int c) : filas(f), columnas(c) {
    espacios = new int*[filas];
    for (int i = 0; i < filas; i++) {
        espacios[i] = new int[columnas];
        for (int j = 0; j < columnas; j++) {
            espacios[i][j] = 0; // 0 = libre
        }
    }
}

MatrizEspacios::~MatrizEspacios() {
    for (int i = 0; i < filas; i++) {
        delete[] espacios[i];
    }
    delete[] espacios;
}
