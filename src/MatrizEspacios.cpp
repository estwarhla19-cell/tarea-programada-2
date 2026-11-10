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

void MatrizEspacios::mostrar() const {
    cout << "  ";
    for (int j = 0; j < columnas; j++) cout << "C" << j + 1 << " ";
    cout << "\n";
    for (int i = 0; i < filas; i++) {
        cout << "F" << i + 1 << " ";
        for (int j = 0; j < columnas; j++) {
            cout << (espacios[i][j] == 0 ? "L " : "O ");
        }
        cout << "\n";
    }
}

int MatrizEspacios::getOcupados() const {
    int cont = 0;
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            if (espacios[i][j] == 1) cont++;
    return cont;
}

int MatrizEspacios::getLibres() const {
    return (filas * columnas) - getOcupados();
}

double MatrizEspacios::porcentajeOcupacion() const {
    int total = filas * columnas;
    if (total == 0) return 0.0;
    return (static_cast<double>(getOcupados()) / total) * 100.0;
}
