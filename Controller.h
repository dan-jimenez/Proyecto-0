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
                areas->getElement()->getTicketsQuantity();
    }
    int getAttentedTicketsQuantity(char codeArea, string codigoVentanilla){
        for(areas->goToStart(); !areas->atEnd(); areas->next())
            if(areas->getElement()->getCode() == codeArea)
                areas->getElement()->getTicketServiceWindow(codigoVentanilla);
    }


    int getQuantityTicketsGiven(int codigoServicio);
    int getQuantityPrefTickets(){
        return 1;
    }
};


#endif //CONTROLADOR_H
