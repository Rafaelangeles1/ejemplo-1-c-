#include "pch.h"
#include "Paquete.h"
#include "HeapSort.h"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

// ============================================================
//  IMPLEMENTACIÓN DE Paquete
// ============================================================

Paquete::Paquete()
    : codigoEnvio(""), destino(""), peso(0.0f), prioridad(0) {
}

Paquete::Paquete(string codigoEnvio, string destino, float peso, int prioridad)
    : codigoEnvio(codigoEnvio), destino(destino), peso(peso), prioridad(prioridad) {
}

// Getters
string Paquete::getCodigoEnvio() const { return codigoEnvio; }
string Paquete::getDestino()     const { return destino; }
float  Paquete::getPeso()        const { return peso; }
int    Paquete::getPrioridad()   const { return prioridad; }

// Setters
void Paquete::setCodigoEnvio(string codigoEnvio) { this->codigoEnvio = codigoEnvio; }
void Paquete::setDestino(string destino) { this->destino = destino; }
void Paquete::setPeso(float peso) { this->peso = peso; }
void Paquete::setPrioridad(int prioridad) { this->prioridad = prioridad; }

void Paquete::mostrar() const {
    cout << left
        << "  Codigo: " << setw(10) << codigoEnvio
        << "| Destino: " << setw(15) << destino
        << "| Peso: " << setw(7) << fixed << setprecision(2) << peso << " kg"
        << "| Prioridad: " << prioridad
        << endl;
}

// ============================================================
//  IMPLEMENTACIÓN DE HeapSort
// ============================================================

/*
 * heapify: mantiene la propiedad de MAX-HEAP.
 *
 * Lógica:
 *   Dado un nodo raíz en el índice 'i', compara su prioridad
 *   con la de sus hijos izquierdo (2i+1) y derecho (2i+2).
 *   Si algún hijo tiene mayor prioridad, intercambia la raíz
 *   con ese hijo y aplica heapify recursivamente hacia abajo.
 *
 * Complejidad: O(log n)
 */
void HeapSort::heapify(vector<Paquete>& paquetes, int n, int i) {
    int mayor = i;          // Suponemos que la raíz es el mayor
    int izquierdo = 2 * i + 1; // Hijo izquierdo
    int derecho = 2 * i + 2; // Hijo derecho

    // ¿El hijo izquierdo existe y tiene mayor prioridad que la raíz?
    if (izquierdo < n &&
        paquetes[izquierdo].getPrioridad() > paquetes[mayor].getPrioridad()) {
        mayor = izquierdo;
    }

    // ¿El hijo derecho existe y tiene mayor prioridad que el actual mayor?
    if (derecho < n &&
        paquetes[derecho].getPrioridad() > paquetes[mayor].getPrioridad()) {
        mayor = derecho;
    }

    // Si el mayor no es la raíz, intercambiamos y seguimos heapificando
    if (mayor != i) {
        swap(paquetes[i], paquetes[mayor]);
        heapify(paquetes, n, mayor);
    }
}

/*
 * ordenar: aplica HeapSort sobre el vector de paquetes.
 *
 * Fases:
 *   1. BUILD MAX-HEAP: recorre el vector de atrás hacia adelante
 *      llamando a heapify en cada nodo no-hoja. Esto garantiza
 *      que el paquete de MAYOR prioridad queda en paquetes[0].
 *      Complejidad: O(n)
 *
 *   2. EXTRACCIÓN ORDENADA: repite n-1 veces:
 *      - Mueve la raíz del heap (mayor prioridad) al final.
 *      - Reduce el tamaño efectivo del heap en 1.
 *      - Restaura la propiedad de heap con heapify.
 *      Resultado: orden de MAYOR a MENOR prioridad.
 *      Complejidad: O(n log n)
 *
 * Complejidad total: O(n log n) | Espacio auxiliar: O(1)
 */
void HeapSort::ordenar(vector<Paquete>& paquetes) {
    int n = paquetes.size();

    // Fase 1: construir el max-heap
    // El último nodo no-hoja está en el índice (n/2 - 1)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(paquetes, n, i);
    }

    // Fase 2: extraer elemento a elemento del heap
    for (int i = n - 1; i > 0; i--) {
        // El máximo (raíz) va al final de la porción no ordenada
        swap(paquetes[0], paquetes[i]);

        // Restauramos el heap sobre los primeros i elementos
        heapify(paquetes, i, 0);
    }
    // Al terminar, el arreglo queda de MENOR a MAYOR prioridad
    // (HeapSort natural con max-heap), así que invertimos para
    // obtener MAYOR a MENOR:
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        swap(paquetes[i], paquetes[j]);
    }
}

void HeapSort::mostrarPaquetes(const vector<Paquete>& paquetes) const {
    for (int i = 0; i < (int)paquetes.size(); i++) {
        cout << "[" << i + 1 << "] ";
        paquetes[i].mostrar();
    }
}

// ============================================================
//  FUNCIÓN PRINCIPAL
// ============================================================
int main() {
    cout << "==========================================" << endl;
    cout << "  Sistema de Prioridad de Envios (Courier)" << endl;
    cout << "  Algoritmo: HeapSort" << endl;
    cout << "==========================================" << endl;

    // Creamos una lista de paquetes con distintas prioridades
    vector<Paquete> listaPaquetes = {
        Paquete("PKT-001", "Miraflores",     2.5f, 3),
        Paquete("PKT-002", "San Isidro",     0.8f, 5),
        Paquete("PKT-003", "Surco",          5.2f, 1),
        Paquete("PKT-004", "La Molina",      3.1f, 4),
        Paquete("PKT-005", "Barranco",       1.0f, 2),
        Paquete("PKT-006", "Pueblo Libre",   4.7f, 5),
        Paquete("PKT-007", "Magdalena",      0.5f, 3),
        Paquete("PKT-008", "San Borja",      6.3f, 1),
        Paquete("PKT-009", "Jesus Maria",    2.2f, 4),
        Paquete("PKT-010", "Lince",          1.8f, 2)
    };

    cout << "\n--- Lista ORIGINAL de paquetes ---" << endl;
    HeapSort hs;
    hs.mostrarPaquetes(listaPaquetes);

    // Aplicar HeapSort
    hs.ordenar(listaPaquetes);

    cout << "\n--- Lista ORDENADA por prioridad (mayor a menor) ---" << endl;
    hs.mostrarPaquetes(listaPaquetes);

    cout << "\n>>> Carga de vehiculos lista. Prioridad maxima primero." << endl;
    return 0;
}