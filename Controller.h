#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Area.h"
#include "Service.h"
#include <string.h>
#include <stdexcept>
//La clase Controller se encarga de llamar a todas las funciones de todas las otras clases y ordenar más el proyecto, desde está clase se pueden llamar a todas las -
//funciones necesarias, tiene métodos como: añadir servicios, añadir áreas, eliminar areas y servicios, atender, ver el tiempo de espera de un área, ver el estado de -
// las colas, ver los tiquetes atendidos, imprimir áreas.
//Autores: Danny Jimenez, Daniel Cruz y Emily Sánchez.

using std::runtime_error;
using std::string;
using std::to_string;

class Controller
{
private:
    ArrayList<Area *> *areas;
    ArrayList<Service *> *services;

    void noAreas()
    {
        if (areas->getSize() == 0)
        {
            throw runtime_error("No hay areas disponibles... ");
        }
    }
    void servicesVerification()
    {
        if (services->getSize() == 0)
        {
            throw runtime_error("No hay servicios disponible...");
        }
    }

    Service * getService(int index){
        services->goToPos(index);
        return services->getElement();
    }

public:
    Controller()
    {
        areas = new ArrayList<Area *>();
    }
    bool generateTicket( bool pref, int index)
    {
        noAreas();
        servicesVerification();
        string areaCode;
        if(getService(index) != nullptr){
            areaCode = getService(index)->getArea();
        }
        for (areas->goToStart(); !areas->atEnd(); areas->next())
        {
            if (areas->getElement()->getCode() == areaCode)
            {
                areas->getElement()->generateClient(pref, getService(index));
            }
        }
        throw runtime_error("Servicio no existe...");
    }
    bool addService(string areaCode, string nombre)
    {
        servicesVerification();
        string area;
        for (areas->goToStart(); !areas->atEnd(); areas->next())
        {
            if (areas->getElement()->getCode() == areaCode)
            {
                area = areas->getElement()->getCode();
            }
        }
        Service * nuevo = new Service(nombre);
        nuevo->setArea(area);
        services->append(nuevo);
        return true;
    }
    bool deleteService(int index)
    {
        servicesVerification();
        getService(index);
        services->remove();
        return true;
    }

    bool addArea(string description, string code, int windowsQuantity)
    {
        Area *current = new Area(description, code, windowsQuantity);
        for (areas->goToStart(); !areas->atEnd(); areas->next())
        {
            if (areas->getElement()->getCode() == code)
            {
                throw runtime_error("El area ya existe... ");
            }
        }
        areas->append(current);
        return true;
    }

    bool areaExist(string code)
    {
        noAreas();
        areas->goToStart();
        while (!areas->atEnd())
        {
            Area *a = areas->getElement();
            if (a->getCode() == code)
                return true;
        }
        return false;
    }

    bool deleteArea(string code)
    {
        noAreas();
        for (areas->goToStart(); !areas->atEnd(); areas->next())
        {
            if (areas->getElement()->getCode() == code)
            {
                areas->remove();
                return true;
            }
        }
        throw runtime_error("No existe el area que se desea borrar... ");
    }
    bool attend(string areaCode, string serviceWindowCode)
    {
        noAreas();
        for (areas->goToStart(); !areas->atEnd(); areas->next())
        {
            if (areas->getElement()->getCode() == areaCode)
            {
                areas->getElement()->attend(serviceWindowCode);
                return true;
            }
        }
        throw runtime_error("No se encontro el area deseada...");
    }

    int getAverageWatingTime(string codigoArea)
    {
        noAreas();
        for (areas->goToStart(); !areas->atEnd(); areas->next())
            if (areas->getElement()->getCode() == codigoArea)
                return areas->getElement()->getAverageWatingTime();
        throw runtime_error("No se han atendido tiquetes... por lo cual no hay tiempo de espera promedio...");
    }
    int getTicketQuantity(string codigoArea)
    {
        noAreas();
        for (areas->goToStart(); !areas->atEnd(); areas->next())
            if (areas->getElement()->getCode() == codigoArea)
                return areas->getElement()->getTicketsGiven();
        throw runtime_error("El area no ha dado ningun tiquete... ");
    }
    int getAttentedTicketsQuantity(string codeArea, string codigoVentanilla)
    {
        noAreas();
        for (areas->goToStart(); !areas->atEnd(); areas->next())
            if (areas->getElement()->getCode() == codeArea)
                return areas->getElement()->getTicketServiceWindow(codigoVentanilla);
        throw runtime_error("Esa ventanilla no ha atendido a ningun tiquete...");
    }
    int getQuantityTicketsGiven(int indexService)
    {
        servicesVerification();
        return getService(indexService)->getTicketsGiven();
    }
    int getQuantityPrefTickets()
    {
        noAreas();
        int ticketsPrefGiven = 0;
        for (areas->goToStart(); !areas->atEnd(); areas->next())
            ticketsPrefGiven += areas->getElement()->getPrefTicketsGiven();
        throw runtime_error("No hay tiquetes preferenciales dados... ");
    }
    void printAreas(){
        noAreas();
        int counter = 0;
        cout << "-------------------------------------------------------------" << endl;
        cout << "Areas disponibles" << endl;
        cout << "-------------------------------------------------------------" << endl;
        for (areas->goToStart(); !areas->atEnd(); areas->next())
        {
            cout << to_string(counter) + ". ";
            areas->getElement()->print();
            counter++;
        }
        cout << "-------------------------------------------------------------" << endl;
    }
    void printServices(){
        servicesVerification();
        int counter = 0;
        cout << "-------------------------------------------------------------" << endl;
        cout << "Servicios disponibles" << endl;
        cout << "-------------------------------------------------------------" << endl;
        for (services->goToStart(); !services->atEnd(); services->next())
        {
            cout << to_string(counter) << ". ";
            services->getElement()->print();
            counter++;
        }
        cout << "-------------------------------------------------------------" << endl;
    }
    void printQueues(){
        noAreas();
        int counter = 0;
        cout << "-------------------------------------------------------------" << endl;
        cout << "Areas disponibles con sus respectivas colas" << endl;
        cout << "-------------------------------------------------------------" << endl;
        for (areas->goToStart(); !areas->atEnd(); areas->next())
        {
            cout << to_string(counter) + ". ";
            areas->getElement()->printQueues();
            counter++;
        }
        cout << "-------------------------------------------------------------" << endl;
    }
    void printArea(string areaCode)
    {
        noAreas();
        for (areas->goToStart(); !areas->atEnd(); areas->next())
            if (areas->getElement()->getCode() == areaCode)
                areas->getElement()->printWindows();
        throw runtime_error("No se encontro el area...");
    }
    bool reorder(int inicialPos, int nextPos)
    {
        servicesVerification();
        services->goToPos(inicialPos);
        Service *current = services->remove();
        services->goToPos(nextPos);
        services->insert(current);
        return true;
    }
    int getServicesQuantity(){
        return services->getSize();
    }


};

#endif // CONTROLADOR_H
