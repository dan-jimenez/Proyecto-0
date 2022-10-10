#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Area.h"
#include "Service.h"
#include <string.h>

using std::string;

class Controlador{
private:
    ArrayList<Area> * areas;
    ArrayList<Servicio> * services;

public: 
    Controlador(){
        areas = new ArrayList<Area>();
        services = new ArrayList<Servicio>();
    }
    bool agregarServicio();
    bool agregarArea();
    bool existeArea(char code);
    bool atender();
    void verColas();
    double getTiempoPromedioEspera(char codigoArea);
    int getCantidadTiquetes(char codigoArea);
    int getCantidadTiquetesAtendidos(string codigoVentanilla);
    int getCantidadTiquetesDispensados(int codigoServicio);
    int getCantidadTiquetesPreferenciales();
};


#endif //CONTROLADOR_H