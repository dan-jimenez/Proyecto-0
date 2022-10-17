#ifndef AREA_H
#define AREA_H


#include "iostream"
#include "ServiceWindow.h"
#include "Service.h"
#include "Ticket.h"
#include <string.h>
#include "ArrayList.h"
#include "ArrayQueue.h"
#include "LinkedPriorityQueue.h"

using std::to_string;

class Area{
private:
    string description;
    char code;
    int windowsQuantity;
    ArrayList<ServiceWindow*> * serviceWindows;
    ArrayList<Service*> * services;
    ArrayList <Area*>  * areas;
    LinkedPriorityQueue<Ticket*> *queue;
    ArrayList<Ticket*> * attentedTickets;
    int ticketsGiven; // tienen que ir desde el 0 al 99
    int prefTicketsGiven; 

    void generateServiceWindows(){
        for (int i = 0; i < windowsQuantity; i++){
            string windowCode = code + to_string(i);
            ServiceWindow * current = new ServiceWindow(windowCode);
            serviceWindows->append(current);
        }
    }


public:
    Area(string description, char code, int windowsQuantity){
        this->description = description;
        this->code = code;
        this->windowsQuantity = windowsQuantity;
        ticketsGiven = 0;
        serviceWindows = new ArrayList<ServiceWindow*>();
        services = new ArrayList<Service*>();
        queue = new LinkedPriorityQueue<Ticket*>(2);
    }

    bool generateClient(bool pref, string serviceCode){ //este genera el code de la ficha apartir del servicio y el numero de clientes.
        string clientCode = code + to_string(ticketsGiven);
        Service * actual;
        for (int i = 0; i < services->getSize(); i++)
            if(serviceCode == services->getElement()->getCodigo())
                actual = services->getElement();
        if(actual == nullptr){
            return false;
        }
        Ticket * client = new Ticket(clientCode, pref, actual);
        actual->count();
        if(pref){
            queue->insert(client, 0);
            prefTicketsGiven++;
        }
        else
            queue->insert(client, 1);
        ticketsGiven++;
        return true;
        
    }
    void addService(Service *service){
        services->append(service);
    }
    void addArea (Area *area){
        areas->append(area);
    }

    bool areaExist(char code){
        areas->goToStart();
        while (!areas->atEnd()) {
            Area *a = areas->getElement();
            if (a->getCode() == code)
                return true;
        }
        return false;
    }
    
    bool attend(string serviceWindowCode){
        ServiceWindow * current;
        for(serviceWindows->goToStart(); !serviceWindows->atEnd(); serviceWindows->next())
            if(serviceWindows->getElement()->getCode() == serviceWindowCode)
                current = serviceWindows->getElement();
        if(current != nullptr){
            current->attend(queue->removeMin());
            attentedTickets->append(current->getLastTicket());
            return true;
        }
        return false;
    }

    Service * removeService(string code){
        return nullptr; //Falta implementacion
    }
    string getDescription(){
        return description;
    }
    char getCode(){
        return code;
    }
    int getWindowsQuantity(){
        return windowsQuantity;
    }
    int getClientAttended(){
        return ticketsGiven;
    }
   double getAverageWatingTime(){
        double totalAverage = 0;
        for (attentedTickets->goToStart(); !attentedTickets->atEnd(); attentedTickets->next()){
            totalAverage = attentedTickets->getElement()->getDuration();
        }
        return totalAverage/ticketsGiven;
        
    }
    int getTicketServiceWindow(string code){
        for (serviceWindows->goToStart(); !serviceWindows->atEnd(); serviceWindows->next()){
            if(serviceWindows->getElement()->getCode() == code){
                return serviceWindows->getElement()->getTicketsQuantity();
            }
        }
        return -1;
    }
    void printQueues(){
        queue->print();
    }
    int getTicketsGiven(){
        return ticketsGiven;
    }
    int getTicketsGiven(string serviceCode){
        for(services->goToStart(); !services->atEnd(); services->next())
            if(services->getElement()->getCodigo() == serviceCode)
                return services->getElement()->getTicketsGiven();
        return -1;
    }
    int getPrefTicketsGiven(){
        return prefTicketsGiven;
    }


};

#endif // AREA_H
