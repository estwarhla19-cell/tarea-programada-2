#ifndef MATRIZESPACIOS_HPP
#define MATRIZESPACIOS_HPP
class MatrizEspacios {
private:
    int** espacios;
    int filas;
    int columnas;
public:
    MatrizEspacios(int f, int c);
    ~MatrizEspacios();
    bool buscarDisponible(int& fila, int& col) const;
    void ocupar(int fila, int col);
    void liberar(int fila, int col);
    void mostrar() const;
    int getOcupados() const;
    int getLibres() const;
    double porcentajeOcupacion() const;
};
#endif
