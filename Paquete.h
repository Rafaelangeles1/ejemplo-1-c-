#ifndef PAQUETE_H
#define PAQUETE_H

#include <string>
#include <iostream>
using namespace std;

class Paquete {
private:
    string codigoEnvio;
    string destino;
    float peso;
    int prioridad;

public:
    // Constructor por defecto
    Paquete();

    // Constructor parametrizado
    Paquete(string codigoEnvio, string destino, float peso, int prioridad);

    // Getters
    string getCodigoEnvio() const;
    string getDestino() const;
    float getPeso() const;
    int getPrioridad() const;

    // Setters
    void setCodigoEnvio(string codigoEnvio);
    void setDestino(string destino);
    void setPeso(float peso);
    void setPrioridad(int prioridad);

    // Mostrar información del paquete
    void mostrar() const;
};

#endif // PAQUETE_H