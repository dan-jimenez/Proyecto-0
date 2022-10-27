#ifndef SERVICE_H
#define SERVICE_H
#include <string.h>

#include <iostream>

//La clase Service se encarga de crear los objetos de tipo servicio, que tiene como atributos: nombre, código y los tiquetes atendidos, solo tiene los métodos accesores
// metodo print.
//Autores: Daniel Cruz y Emily Sánchez.

using std::string;
using std::endl;
using std::cout;

class Service{
    /**
     * @brief Service
     * En esta clase se manejan los datos de un servicio que se puede ofrecer a un cliente.
     *
     * @author Daniel
     */
private:
    string area;
    string nombre;
    int ticketsGiven;


public:
    Service(string nombre){
        this->nombre = nombre;
        this->ticketsGiven = 0;
        this->area = area;
    }
    void setArea(string area){
        this->area = area;
    }
    string getArea(){
        return area;
    }
    string getNombre(){
        return this->nombre;
    }
    int getNumCliente(){
        return this->ticketsGiven;
    }
    void count(){
        ticketsGiven++;
    }
    int getTicketsGiven(){
        return ticketsGiven;
    }
    void print(){
        cout << nombre << ". Codigo Area: " + area << endl;
    }

};

#endif // SERVICE_H
