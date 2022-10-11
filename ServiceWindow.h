#ifndef SERVICEWINDOW_H
#define SERVICEWINDOW_H
#include "Area.h"

class ServiceWindow{
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
};

#endif // SERVICEWINDOW_H
