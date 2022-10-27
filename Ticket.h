#ifndef TIQUETE_H
#define TIQUETE_H

#include <chrono>
#include <ctime>
#include <string>
//La clase Ticket se encarga de crear obejtos de tipo tiquete, tiene atributos como: código, si es preferencial, hora de llegada y hora de salida. 
//Tiene los métodos accesores y un método para cálcular el tiempo de espera del cliente en la cola. 
////Autores: Danny Jimenez.

#include "Service.h"

using std::ctime;
using std::chrono::system_clock;
using std::string;
using std::chrono::duration;

class Ticket {
private:
    string code;
    bool preferential;
    time_t comingTime;
    time_t endingTime;

    void operator=(const Ticket &other) {}
    Ticket(const Ticket &other) {}

public:
    Ticket(string code, bool preferential, Service * service){
        this->code = code;
        comingTime = system_clock::to_time_t(system_clock::now());
        this->preferential = preferential;
    }
    void setEndingTime(time_t endingTime){
        this->endingTime = endingTime;
    }
    string getCode(){
        return code;
    }
    double getDuration(){
        duration<double> duracion = system_clock::from_time_t(endingTime) - system_clock::from_time_t(comingTime);
        return duracion.count();
    }
    string print(){
        return code; 
    }
    
};

#endif //TIQUETE_H
