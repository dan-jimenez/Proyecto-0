#ifndef SERVICE_H
#define SERVICE_H
#include <string.h>
#include <iostream>

using std::string;

class Servicio{
private:
    string nombre;
    string code;
    int clientAttended;

public:
    Servicio(string nombre, string code){
        this->nombre = nombre;
        this->code = code;
        this->clientAttended = 0;
    }

    string getNombre(){
        return this->nombre;
    }
    string getCodigo(){
        return this->code;
    }
    int getNumCliente(){
        return this->clientAttended;
    }
    void count(){
        clientAttended++;
    }
    

};

#endif // SERVICE_H