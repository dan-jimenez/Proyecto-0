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
    ArrayList<Servicio*> * services;
    int ticketsQuantity;
    LinkedPriorityQueue<Ticket*> * queue;
    int clientAttended; // tienen que ir desde el 0 al 99
    
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
        serviceWindows = new ArrayList<ServiceWindow*>();
        services = new ArrayList<Servicio*>();
        queue = new LinkedPriorityQueue<Ticket*>(1);
    }

    void generateClient(bool pref){ //este genera el code de la ficha apartir del servicio y el numero de clientes.
        string clientCode = code + to_string(clientAttended);
        Ticket * client = new Ticket(clientCode, pref);
        if(pref)
            queue->insert(client, 0);
        else
            queue->insert(client, 1);
        clientAttended++;
        ticketsQuantity++;
    }
    void addService(Servicio * service){
        services->append(service);
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
        return clientAttended;
    }
    int getTicketsQuantity(){
        return ticketsQuantity;
    }

    

};

#endif // AREA_H
