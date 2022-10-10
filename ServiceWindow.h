#ifndef SERVICEWINDOW_H
#define SERVICEWINDOW_H
#include "Area.h"

class ServiceWindow{
private:
    Ticket * tiqueteActual;
    int ticketsQuantity;
    string code;

public:
    ServiceWindow(string code){
        this->code = code;
        this->ticketsQuantity = 0;
    }

    void atenderPrioridad(){} //esta est� ligada a la queue de prioridad

    void atenderNormal(){} // esta est� ligada a la queue normal
};

#endif // SERVICEWINDOW_H
