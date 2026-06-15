#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "Paquete.h"
#include "vector"
using namespace std;

class HeapSort {
private:
    
    void heapify(vector<Paquete>& paquetes, int n, int i);

public:
    
    void ordenar(vector<Paquete>& paquetes);

    
    void mostrarPaquetes(const vector<Paquete>& paquetes) const;
};

#endif 