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
#include <stdexcept>


using std::runtime_error;
using std::to_string;

class Area{
private:
    string description;
    char code;
    int windowsQuantity;
    ArrayList<ServiceWindow*> * serviceWindows;
    ArrayList<Service*> * services;
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
    void servicesVerification(){
        if(services->getSize() == 0){
            throw runtime_error("No hay servicios disponible...");
        }
    }
    void windowServicesVerification(){
        if(serviceWindows->getSize() == 0){
            throw runtime_error("No hay ventanas de servicio registradas...");
        }
    }

public:
    Area(string description, char code, int windowsQuantity){
        this->description = description;
        this->code = code;
        this->windowsQuantity = windowsQuantity;
        ticketsGiven = 0;
        serviceWindows = new ArrayList<ServiceWindow*>();
        generateServiceWindows();
        services = new ArrayList<Service*>();
        attentedTickets = new ArrayList<Ticket*>();
        queue = new LinkedPriorityQueue<Ticket*>(2);
    }

    bool generateClient(bool pref, string serviceCode){ //este genera el code de la ficha apartir del servicio y el numero de clientes.
        string clientCode = code + to_string(ticketsGiven);
        Service * actual;
        servicesVerification();
        for (services->goToStart(); !services->atEnd(); services->next())
            if(serviceCode == services->getElement()->getCodigo())
                actual = services->getElement();
        if(actual == nullptr){
            throw runtime_error("El servicio no existe... ");
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
    
    bool attend(string serviceWindowCode){
        windowServicesVerification();
        for(serviceWindows->goToStart(); !serviceWindows->atEnd(); serviceWindows->next())
            if(serviceWindows->getElement()->getCode() == serviceWindowCode){
                serviceWindows->getElement()->attend(queue->removeMin());
                attentedTickets->append(serviceWindows->getElement()->getLastTicket());
                return true;
            }
        throw runtime_error("La  ventana de servicio no existe...");
    }

    bool removeService(string code){
        services->goToStart();
        while (!services->atEnd()) {
            if (services->getElement()->getCodigo() == code){
                services->remove();
                return true;
            }
                
        }
        return false;
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
            totalAverage += attentedTickets->getElement()->getDuration();
        }
        return totalAverage/ticketsGiven;
        
    }
    int getTicketServiceWindow(string code){
        windowServicesVerification();
        for (serviceWindows->goToStart(); !serviceWindows->atEnd(); serviceWindows->next()){
            if(serviceWindows->getElement()->getCode() == code){
                return serviceWindows->getElement()->getTicketsQuantity();
            }
        }
        throw runtime_error("La ventana de servicio que se desea consultar no existe...");
    }
    void printQueues(){
        queue->print();
    }
    int getTicketsGiven(){
        return ticketsGiven;
    }
    int getTicketsGiven(string serviceCode){
        servicesVerification();
        for(services->goToStart(); !services->atEnd(); services->next())
            if(services->getElement()->getCodigo() == serviceCode)
                return services->getElement()->getTicketsGiven();
        return -1;
    }
    int getPrefTicketsGiven(){
        return prefTicketsGiven;
    }

    bool deleteService(string serviceCode){
        servicesVerification();
        for(services->goToStart(); !services->atEnd(); services->next())
            if(services->getElement()->getCodigo() == serviceCode){
                services->remove();
                return true;
            }
        return false;
    }
    string print(){
        string result = "Area codigo ";
        result += code;
        result += "\nDescripcion: " + description +  "\n------------------------------------------------------------------";
        result += "\nServicios: \n";
        int counter = 0;
        int counterWin = 0;
        for (services->goToStart(); !services->atEnd(); services->next()){
            result += to_string(counter) + ". "+ services->getElement()->print();
            counter++;
        }
        result += "------------------------------------------------------------------\nVentanillas: \n";
        for (serviceWindows->goToStart(); !serviceWindows->atEnd(); serviceWindows->next()){
            result += to_string(counterWin) +". " + serviceWindows->getElement()->print();
            counterWin++;
        }
        result += "------------------------------------------------------------------\n";
        return result; 
        
    }

    void reorder(int inicialPos, int nextPos){
        servicesVerification();
        services->goToPos(inicialPos);
        Service * current = services->remove();
        services->goToPos(nextPos);
        services->insert(current);
    }

};

#endif // AREA_H
