#ifndef SERVICEWINDOW_H
#define SERVICEWINDOW_H
#include "Ticket.h"
#include "iostream"

//La clase ServiceWindow se encarga de crear obejtos de tipo ventanilla, sus atributos son: código y cantidad de tiquetes. 
//Tiene los métodos accesores. 
////Autores: Danny Jimenez y Daniel Cruz.

using std::endl;
using std::cout;

class ServiceWindow{
    /**
     * @brief ServiceWindow
     * Se utiliza como una objeto donde se atienden clientes
     * 
     * @author Emily 
     */
private:
    Ticket * currentTicket;
    int ticketsQuantity;
    string code;

public:
    ServiceWindow(string code){
        this->code = code;
        this->ticketsQuantity = 0;
    }
    void attend(Ticket * current){
        currentTicket = current;
        ticketsQuantity++;
    }
    Ticket * getLastTicket(){
        return currentTicket;
    }
    int getTicketsQuantity(){
        return ticketsQuantity;
    }
    string getCode(){
        return code;
    }
    void print(){
        cout << "Codigo: " << code << endl; 
        
    }
};

#endif // SERVICEWINDOW_H
