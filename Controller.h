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
    bool generateTicket(char areaCode, bool pref, string serviceCode){
        for(areas->goToStart(); !areas->atEnd(); areas->next()){
            if(areas->getElement()->getCode() == areaCode){
                return areas->getElement()->generateClient(pref, serviceCode);
            }
        }
        return false;
    }
    bool addService(char areaCode, string serviceCode, string nombre){
        for(areas->goToStart(); !areas->atEnd(); areas->next()){
            if(areas->getElement()->getCode() == areaCode){
                Service * current = new Service(nombre, serviceCode);
                areas->getElement()->addService(current);
                return true; 
            }
        }
        return false;
    }
    bool deleteService(char areaCode, string serviceCode){
        for(areas->goToStart(); !areas->atEnd(); areas->next()){
            if(areas->getElement()->getCode() == areaCode){
                return areas->getElement()->removeService(serviceCode); 
            }
        }
        return false;
    }
    bool addArea(int windowsQuantity, char code, string description){
        Area * current = new Area(description, code, windowsQuantity);
        for(areas->goToStart(); !areas->atEnd(); areas->next()){
            if(areas->getElement()->getCode() == code){
                return false; 
            }
        }
        areas->append(current);
        return true; 
    }
    bool deleteArea(char code){
        for(areas->goToStart(); !areas->atEnd(); areas->next()){
            if(areas->getElement()->getCode() == code){
                areas->remove();
                return true;
            }
        }
        return false;
    }
    bool areaExist(char code){
        for(areas->goToStart(); !areas->atEnd(); areas->next()){
            if(areas->getElement()->getCode() == code){
                return true; 
            }
        }
        return false;
    }
    bool attend(char areaCode, string serviceWindowCode){
        for(areas->goToStart(); !areas->atEnd(); areas->next()){
            if(areas->getElement()->getCode() == areaCode){
                areas->getElement()->attend(serviceWindowCode);
                return true;
            }
        }
        return false;
    }

    void printQueues(){
        for(areas->goToStart(); !areas->atEnd(); areas->next()){
            cout << "Area "<< areas->getElement()->getCode() << ": " << endl;
            areas->getElement()->printQueues();
        }
    }
    double getAverageWatingTime(char codigoArea){
        for(areas->goToStart(); !areas->atEnd(); areas->next())
            if(areas->getElement()->getCode() == codigoArea)
                return areas->getElement()->getAverageWatingTime();
        return -1;
    }
    int getTicketQuantity(char codigoArea){
        for(areas->goToStart(); !areas->atEnd(); areas->next())
            if(areas->getElement()->getCode() == codigoArea)
                return areas->getElement()->getTicketsGiven();
        return -1;
    }
    int getAttentedTicketsQuantity(char codeArea, string codigoVentanilla){
        for(areas->goToStart(); !areas->atEnd(); areas->next())
            if(areas->getElement()->getCode() == codeArea)
                return areas->getElement()->getTicketServiceWindow(codigoVentanilla);
        return -1;
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
