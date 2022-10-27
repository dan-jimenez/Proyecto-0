#ifndef AREA_H
#define AREA_H


#include "iostream"
#include "ServiceWindow.h"
#include "Service.h"
#include "Ticket.h"
#include <string.h>
#include "ArrayList.h"
#include "LinkedPriorityQueue.h"
#include <stdexcept>

//La clase Area se encarga de crear areas con distintos atributos como: descripción, código, ventanillas, lista de servicios, lista de ventanillas y 2 colas una -
// preferencial y otra normal. Desde está clase se pueden crear métodos para añadir areas, generar ventanillas, verificar si hay servicios y ventanillas disponibles -
// crear areas nuevas, generar clientes, añadir, eliminar o reordenar servicios, atender y ver estado de las colas.
//Autores: Danny Jimenez, Daniel Cruz y Emily Sánchez.

using std::runtime_error;
using std::to_string;

class Area{
    /**
     * @brief Area
     * Usada para manejar una seccion completa donde se contienen las ventanillas de servicio y las colas del programa.
     *
     * @author Danny Jimenez Sevilla
     * @version 29/10/22
     */
private:
    string description;
    string code;
    int windowsQuantity;
    ArrayList<ServiceWindow*> * serviceWindows;
    LinkedPriorityQueue<Ticket*> *queue;
    ArrayList<Ticket*> * attentedTickets;
    int ticketsGiven; // tienen que ir desde el 0 al 99
    int prefTicketsGiven;
    void operator=(const Area &other) {}

    void generateServiceWindows(){
        /**
         * @brief Generate Service Window
         * Inicializa todas las ventanas de servicio
         * @author Danny Jimenez Sevilla
         */
        for (int i = 0; i < windowsQuantity; i++){

            string windowCode = code + to_string(i);
            ServiceWindow * current = new ServiceWindow(windowCode);
            serviceWindows->append(current);
        }
    }

    void windowServicesVerification(){
        if(serviceWindows->getSize() == 0){
            throw runtime_error("No hay ventanas de servicio registradas...");
        }
    }

public:
    Area(string description, string code, int windowsQuantity){
        this->description = description;
        this->code = code;
        this->windowsQuantity = windowsQuantity;
        ticketsGiven = 0;
        serviceWindows = new ArrayList<ServiceWindow*>();
        generateServiceWindows();
        attentedTickets = new ArrayList<Ticket*>();
        queue = new LinkedPriorityQueue<Ticket*>(2);
    }

    bool generateClient(bool pref, Service * service){ //este genera el code de la ficha apartir del servicio y el numero de clientes.
        string clientCode = code + to_string(ticketsGiven);
        Ticket * client = new Ticket(clientCode, pref, service);
        service->count();
        if(pref){
            queue->insert(client, 0);
            prefTicketsGiven++;
        }
        else
            queue->insert(client, 1);
        ticketsGiven++;
        return true;

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

    string getDescription(){
        return description;
    }
    string getCode(){
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
    int getTicketsGiven(){
        return ticketsGiven;
    }

    int getPrefTicketsGiven(){
        return prefTicketsGiven;
    }
    void print(){
        cout << "Area: " << description << ". Codigo: " << code << endl;
    }
    void printWindows(){
        cout << "Area: " << description << ". Codigo: " << code << endl;
        int counterWin = 0;
        cout << "--------------------------------" << endl;
        cout << "Ventanillas: " << endl;
        for (serviceWindows->goToStart(); !serviceWindows->atEnd(); serviceWindows->next()){
            cout << counterWin << ". " ;
            serviceWindows->getElement()->print();
            counterWin++;
        }
        cout << "--------------------------------" << endl;

    }

    void printQueues(){
        cout << "Area: " << description << ". Codigo: " << code << endl;
        int counterWin = 0;
        cout << "--------------------------------" << endl;
        cout << "Colas: " << endl;
        queue->print();
        cout << "--------------------------------" << endl;
    }

};

#endif // AREA_H
