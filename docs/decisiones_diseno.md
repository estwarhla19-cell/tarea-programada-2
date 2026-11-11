# Documento de Diseño y Arquitectura

## Organización de las Clases
El proyecto está dividido en dos grandes grupos: las estructuras de datos y la lógica del negocio.

### 1. Estructuras de Datos
Cada estructura fue implementada desde cero, separando su cabecera (.hpp) de su implementación (.cpp), y utilizando clases amigas (friend) para proteger los punteros de los nodos.
- **Lista Simple (Lista, Nodo, IteradorLista):** Utilizada para la cola de espera de vehículos.
- **Lista Doble (ListaEstacionamiento, NodoDoble, IteradorDoble):** Utilizada para registrar los vehículos activos. Tiene punteros al nodo anterior y siguiente para permitir recorridos inversos.
- **Lista Circular (ListaCircular, NodoCircular, IteradorCircular):** Administra los turnos de los encargados. El iterador incluye un contador para evitar ciclos infinitos.
- **MatrizEspacios:** Matriz dinámica de enteros (0 = libre, 1 = ocupado) implementada con punteros dobles (int**) y liberada correctamente en su destructor.

### 2. Modelos de Datos
- **Vehiculo:** Clase base con placa, propietario y tipo.
- **VehiculoEstacionado:** Hereda de Vehiculo y agrega la fila, columna y el ID del encargado. Incluye el cálculo de la tarifa.
- **Encargado:** Contiene el ID, nombre y la cantidad de vehículos atendidos.

## Manejo de Memoria Dinámica
Todas las estructuras utilizan `new` para crear nodos y `delete` para liberarlos. La clase `MatrizEspacios` utiliza `new int*[filas]` y `new int[columnas]` para cada fila, liberando la memoria con `delete[]` en el orden correcto para evitar fugas de memoria.

## Manejo de Excepciones
Se utiliza la biblioteca `<stdexcept>` para lanzar excepciones en situaciones inválidas:
- `underflow_error`: Al intentar procesar una lista de espera vacía.
- `overflow_error`: Cuando el estacionamiento está lleno.
- `invalid_argument`: Al ingresar horas negativas o dimensiones inválidas.
- `logic_error`: Al intentar registrar una placa duplicada o no haber encargados.

## Resultados de las Pruebas
