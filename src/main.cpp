#include <iostream>
#include <stdexcept>
#include "SistemaEstacionamiento.hpp"
using namespace std;

int main() {
    int filas, columnas;
    cout << "\n--- CONFIGURACION INICIAL ---" << endl;
    cout << "Ingrese cantidad de filas: "; cin >> filas;
    cout << "Ingrese cantidad de columnas: "; cin >> columnas;
    
    try {
        if (filas <= 0 || columnas <= 0) throw invalid_argument("Las dimensiones deben ser mayores a cero.");
        
        SistemaEstacionamiento sistema(filas, columnas);
        int opcion = -1;
        
        do {
            cout << "\n----------------------------------------" << endl;
            cout << "       SISTEMA DE ESTACIONAMIENTO       " << endl;
            cout << "----------------------------------------" << endl;
            cout << "1. Registrar encargado" << endl;
            cout << "2. Registrar solicitud de ingreso" << endl;
            cout << "3. Procesar siguiente solicitud" << endl;
            cout << "4. Registrar salida de vehiculo" << endl;
            cout << "5. Mostrar estado de la matriz" << endl;
            cout << "6. Generar reportes" << endl;
            cout << "0. Salir" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Seleccione una opcion: "; 
            cin >> opcion;
            
            try {
                if (opcion == 1) {
                    string id, nombre;
                    cout << "ID: "; cin >> id;
                    cout << "Nombre: "; cin >> nombre;
                    sistema.registrarEncargado(id, nombre);
                } else if (opcion == 2) {
                    string placa, prop, tipo;
                    cout << "Placa: "; cin >> placa;
                    cout << "Propietario: "; cin >> prop;
                    cout << "Tipo (Automovil/Motocicleta): "; cin >> tipo;
                    sistema.registrarSolicitud(placa, prop, tipo);
                } else if (opcion == 3) {
                    sistema.procesarSiguiente();
                } else if (opcion == 4) {
                    string placa; int horas;
                    cout << "Placa: "; cin >> placa;
                    cout << "Horas: "; cin >> horas;
                    sistema.registrarSalida(placa, horas);
                } else if (opcion == 5) {
                    sistema.mostrarMatriz();
                } else if (opcion == 6) {
                    sistema.mostrarReporte();
                } else if (opcion != 0) {
                    cout << "Opcion invalida." << endl;
                }
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
        } while (opcion != 0);
        
    } catch (const exception& e) {
        cout << "Error fatal: " << e.what() << endl;
    }
    return 0;
}
