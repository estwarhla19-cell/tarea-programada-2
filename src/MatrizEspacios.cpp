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

bool MatrizEspacios::buscarDisponible(int& fila, int& col) const {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (espacios[i][j] == 0) {
                fila = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

void MatrizEspacios::ocupar(int fila, int col) {
    if (fila >= 0 && fila < filas && col >= 0 && col < columnas) {
        espacios[fila][col] = 1;
    }
}

void MatrizEspacios::liberar(int fila, int col) {
    if (fila >= 0 && fila < filas && col >= 0 && col < columnas) {
        espacios[fila][col] = 0;
    }
}
