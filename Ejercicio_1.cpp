#include "pch.h"
#include "Paquete.h"
#include "HeapSort.h"
#include "vector"
#include "iostream"
#include "iomanip"
using namespace std;



Paquete::Paquete()
    : codigoEnvio(""), destino(""), peso(0.0f), prioridad(0) {
}

Paquete::Paquete(string codigoEnvio, string destino, float peso, int prioridad)
    : codigoEnvio(codigoEnvio), destino(destino), peso(peso), prioridad(prioridad) {
}


string Paquete::getCodigoEnvio() const { return codigoEnvio; }
string Paquete::getDestino()     const { return destino; }
float  Paquete::getPeso()        const { return peso; }
int    Paquete::getPrioridad()   const { return prioridad; }


void Paquete::setCodigoEnvio(string codigoEnvio) { this->codigoEnvio = codigoEnvio; }
void Paquete::setDestino(string destino) { this->destino = destino; }
void Paquete::setPeso(float peso) { this->peso = peso; }
void Paquete::setPrioridad(int prioridad) { this->prioridad = prioridad; }

void Paquete::mostrar() const {
    cout << left
        << "  Codigo: " << setw(10) << codigoEnvio
        << " Destino: " << setw(15) << destino
        << " Peso: " << setw(7) << fixed << setprecision(2) << peso << " kg"
        << " Prioridad: " << prioridad
        << endl;
}


void HeapSort::heapify(vector<Paquete>& paquetes, int n, int i) {
    int mayor = i;          
    int izquierdo = 2 * i + 1; 
    int derecho = 2 * i + 2; 

    
    if (izquierdo < n &&
        paquetes[izquierdo].getPrioridad() > paquetes[mayor].getPrioridad()) {
        mayor = izquierdo;
    }

    
    if (derecho < n &&
        paquetes[derecho].getPrioridad() > paquetes[mayor].getPrioridad()) {
        mayor = derecho;
    }

    
    if (mayor != i) {
        swap(paquetes[i], paquetes[mayor]);
        heapify(paquetes, n, mayor);
    }
}



void HeapSort::ordenar(vector<Paquete>& paquetes) {
    int n = paquetes.size();

    
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(paquetes, n, i);
    }

    
    for (int i = n - 1; i > 0; i--) {
        
        swap(paquetes[0], paquetes[i]);

        
        heapify(paquetes, i, 0);
    }
    
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


int main() {
    cout << "==========================================" << endl;
    cout << "  Sistema de Prioridad de Envios  " << endl;
    cout << "==========================================" << endl;

    
    vector<Paquete> listaPaquetes = {
        Paquete("PQT-01", "Miraflores",     2.5f, 3),
        Paquete("PQT-02", "San Isidro",     0.8f, 5),
        Paquete("PQT-03", "Surco",          5.2f, 1),
        Paquete("PQT-04", "La Molina",      3.1f, 4),
        Paquete("PQT-05", "Barranco",       1.0f, 2),
        Paquete("PQT-06", "Pueblo Libre",   4.7f, 5),
        Paquete("PQT-07", "Magdalena",      0.5f, 3),
        Paquete("PQT-08", "San Borja",      6.3f, 1),
        Paquete("PQT-09", "Jesus Maria",    2.2f, 4),
        Paquete("PQT-10", "Lince",          1.8f, 2)
    };

    cout << "\n Lista original de paquetes " << endl;
    HeapSort hs;
    hs.mostrarPaquetes(listaPaquetes);

    
    hs.ordenar(listaPaquetes);

    cout << "\n Lista ordenada por prioridad " << endl;
    hs.mostrarPaquetes(listaPaquetes);

    cout << "\n>>> Prioridad maxima enviadas primero." << endl;
    return 0;
}