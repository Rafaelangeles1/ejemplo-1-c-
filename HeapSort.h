#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "Paquete.h"
#include <vector>
using namespace std;

class HeapSort {
private:
    // Convierte el subárbol con raíz en el índice 'i' en un max-heap
    // 'n' es el tamaño del heap
    void heapify(vector<Paquete>& paquetes, int n, int i);

public:
    // Ordena el vector de paquetes de mayor a menor prioridad
    void ordenar(vector<Paquete>& paquetes);

    // Muestra todos los paquetes del vector
    void mostrarPaquetes(const vector<Paquete>& paquetes) const;
};

#endif // HEAPSORT_H