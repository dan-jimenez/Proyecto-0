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
    int ticketsQuantity;
    LinkedPriorityQueue<Ticket*> * queue;
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
        ticketsQuantity = 0;
        ticketsGiven = 0; 
        serviceWindows = new ArrayList<ServiceWindow*>();
        services = new ArrayList<Service*>();
        queue = new LinkedPriorityQueue<Ticket*>(2);
    }

    void generateClient(bool pref, Service * service){ //este genera el code de la ficha apartir del servicio y el numero de clientes.
        string clientCode = code + to_string(ticketsGiven);
        Ticket * client = new Ticket(clientCode, pref, service);
        if(pref)
            queue->insert(client, 0);
        else
            queue->insert(client, 1);
        ticketsGiven++;
        ticketsQuantity++;
    }
    void addService(Service * service){
        services->append(service);
    }
    bool attend(ServiceWindow * serviceWindow){ // Modificar
        serviceWindow->attend(queue->removeMin());
        return serviceWindow->getLastTicket();
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
    int getTicketsQuantity(){
        return ticketsQuantity;
    }
    double getAverageWatingTime(char codigoArea);

    

};

#endif // AREA_H
