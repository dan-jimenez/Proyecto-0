#ifndef SERVICE_H
#define SERVICE_H
#include <string.h>
#include <iostream>

using std::string;

class Service{
private:
    string nombre;
    string code;
    int ticketsGiven;

public:
    Service(string nombre, string code){
        this->nombre = nombre;
        this->code = code;
        this->ticketsGiven = 0;
    }

    string getNombre(){
        return this->nombre;
    }
    string getCodigo(){
        return this->code;
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
    string print(){
        string result = nombre + "   --------------------------- Codigo: "+ code + ". \n";
        return result;
    }

};

#endif // SERVICE_H
