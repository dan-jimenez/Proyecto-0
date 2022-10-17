#ifndef SERVICEWINDOW_H
#define SERVICEWINDOW_H
#include "Area.h"
#include "Ticket.h"

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
    string getCode(){
        return code;
    }
};

#endif // SERVICEWINDOW_H
