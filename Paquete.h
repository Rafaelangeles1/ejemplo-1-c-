#ifndef PAQUETE_H
#define PAQUETE_H

#include "string"
#include "iostream"
using namespace std;

class Paquete {
private:
    string codigoEnvio;
    string destino;
    float peso;
    int prioridad;

public:
    
    Paquete();

    
    Paquete(string codigoEnvio, string destino, float peso, int prioridad);

    
    string getCodigoEnvio() const;
    string getDestino() const;
    float getPeso() const;
    int getPrioridad() const;

  
    void setCodigoEnvio(string codigoEnvio);
    void setDestino(string destino);
    void setPeso(float peso);
    void setPrioridad(int prioridad);

    
    void mostrar() const;
};

#endif 