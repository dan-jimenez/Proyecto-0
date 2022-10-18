#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Area.h"
#include "Service.h"
#include <string.h>
#include <stdexcept>

using std::string;
using std::runtime_error;

class Controller{
private:
    ArrayList<Area*> * areas;
    
    void noAreas(){
        if(areas->getSize() == 0){
            throw runtime_error("No hay areas disponibles... ");
        }
    }

public:
    Controller(){
        areas = new ArrayList<Area*>();
    }
    bool generateTicket(char areaCode, bool pref, string serviceCode){
        noAreas();
        for(areas->goToStart(); !areas->atEnd(); areas->next()){
            if(areas->getElement()->getCode() == areaCode){
                return areas->getElement()->generateClient(pref, serviceCode);
            }
        }
        throw runtime_error("Area no existe...");
    }
    bool addService(char areaCode, string serviceCode, string nombre){
        noAreas();
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
        noAreas();
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
        noAreas();
        for(areas->goToStart(); !areas->atEnd(); areas->next()){
            if(areas->getElement()->getCode() == code){
                areas->remove();
                return true;
            }
        }
        return false;
    }
    bool areaExist(char code){
        noAreas();
        for(areas->goToStart(); !areas->atEnd(); areas->next()){
            if(areas->getElement()->getCode() == code){
                return true; 
            }
        }
        return false;
    }
    bool attend(char areaCode, string serviceWindowCode){
       noAreas();
        for(areas->goToStart(); !areas->atEnd(); areas->next()){
            if(areas->getElement()->getCode() == areaCode){
                areas->getElement()->attend(serviceWindowCode);
                return true;
            }
        }
        return false;
    }

    void printQueues(){
        noAreas();
        for(areas->goToStart(); !areas->atEnd(); areas->next()){
            cout << "Area "<< areas->getElement()->getCode() << ": " << endl;
            areas->getElement()->printQueues();
        }
    }
    double getAverageWatingTime(char codigoArea){
        noAreas();
        for(areas->goToStart(); !areas->atEnd(); areas->next())
            if(areas->getElement()->getCode() == codigoArea)
                return areas->getElement()->getAverageWatingTime();
        throw runtime_error("No se han atendido tiquetes... por lo cual no hay tiempo de espera promedio...");
    }
    int getTicketQuantity(char codigoArea){
        noAreas();
        for(areas->goToStart(); !areas->atEnd(); areas->next())
            if(areas->getElement()->getCode() == codigoArea)
                return areas->getElement()->getTicketsGiven();
        throw runtime_error("El area no ha dado ningun tiquete... ");
    }
    int getAttentedTicketsQuantity(char codeArea, string codigoVentanilla){
        noAreas();
        for(areas->goToStart(); !areas->atEnd(); areas->next())
            if(areas->getElement()->getCode() == codeArea)
                return areas->getElement()->getTicketServiceWindow(codigoVentanilla);
        throw runtime_error("Esa ventanilla no ha atendido a ningun tiquete...");
    }
    int getQuantityTicketsGiven(char areaCode, string serviceCode){
        noAreas();
        for (areas->goToStart(); !areas->atEnd(); areas->next())
            if(areas->getElement()->getCode() == areaCode)
                return areas->getElement()->getTicketsGiven(serviceCode);
        throw runtime_error("No hay tiquetes dados...");
    }
    int getQuantityPrefTickets(){
        noAreas();
        int ticketsPrefGiven = 0;
        for(areas->goToStart(); !areas->atEnd(); areas->next())
            ticketsPrefGiven += areas->getElement()->getPrefTicketsGiven();
        throw runtime_error("No hay tiquetes preferenciales dados... ");
    }
};


#endif //CONTROLADOR_H
