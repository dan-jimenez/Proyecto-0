#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Area.h"
#include "Service.h"
#include <string.h>

using std::string;

class Controller{
private:
    ArrayList<Area*> * areas;

public:
    Controller(){
        areas = new ArrayList<Area*>();
    }
    bool generateTicket();
    bool addService();
    bool addArea();
    bool areaExist(char code);
    bool attend();
    
    void printQueues(){
        for(areas->goToStart(); !areas->atEnd(); areas->next()){
            cout << "Area "<< areas->getElement()->getCode() << ": " << endl;
            areas->getElement()->printQueues();
        }
    }
    double getAverageWatingTime(char codigoArea){
        for(areas->goToStart(); !areas->atEnd(); areas->next())
            if(areas->getElement()->getCode() == codigoArea)
                areas->getElement()->getAverageWatingTime();
    }
    int getTicketQuantity(char codigoArea){
        for(areas->goToStart(); !areas->atEnd(); areas->next())
            if(areas->getElement()->getCode() == codigoArea)
                areas->getElement()->getTicketsGiven();
    }
    int getAttentedTicketsQuantity(char codeArea, string codigoVentanilla){
        for(areas->goToStart(); !areas->atEnd(); areas->next())
            if(areas->getElement()->getCode() == codeArea)
                areas->getElement()->getTicketServiceWindow(codigoVentanilla);
    }
    int getQuantityTicketsGiven(char areaCode, string serviceCode){
        for (areas->goToStart(); !areas->atEnd(); areas->next())
            if(areas->getElement()->getCode() == areaCode)
                return areas->getElement()->getTicketsGiven(serviceCode);
        return -1;
    }
    int getQuantityPrefTickets(){
        int ticketsPrefGiven = 0;
        for(areas->goToStart(); !areas->atEnd(); areas->next())
            ticketsPrefGiven += areas->getElement()->getPrefTicketsGiven();
        return ticketsPrefGiven;
    }
};


#endif //CONTROLADOR_H
