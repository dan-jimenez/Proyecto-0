#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Area.h"
#include "Service.h"
#include <string.h>

using std::string;

class Controlador{
private:
    ArrayList<Area*> * areas;
    ArrayList<Service*> * services;
    

public: 
    Controlador(){
        areas = new ArrayList<Area*>();
        services = new ArrayList<Service*>();
    }
    bool generateTicket();
    bool addService();
    bool addArea();
    bool areaExist(char code);
    bool attend();
    void printQueues();
    double getAverageWatingTime(char codigoArea);
    int getTicketQuantity(char codigoArea);
    int getAttentedTicketsQuantity(string codigoVentanilla);
    int getQuantityTicketsGiven(int codigoServicio);
    int getQuantityPrefTickets(){
        return 1;
    }
};


#endif //CONTROLADOR_H