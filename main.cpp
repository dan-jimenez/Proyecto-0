#include <iostream>
#include "Area.h"
#include "Controller.h"
#include "Service.h"
#include "ArrayList.h"
#include <string>
#include <typeinfo>

//La clase main se encarga del programa principal, se despliega un menú para que el usuario pueda elegir todas las funcionalidades realizadas, se utilizo
//un switch para el menú principal recibiendo un char para mayor robustez.
//Autores: Danny Jimenez, Daniel Cruz y Emily Sánchez.

using std::cin;
using std::cout;
using std::endl;
using std::getline;

Controller *controller = new Controller();

bool ReadInt(int &valor)
{
    std::cin >> valor;

    bool ok = std::cin.good();

    if (!ok)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return ok;
}
void solicitarTiquete()
{
    string respuesta;
    do
    {
        cout << "Escoja una de las opciones: " << endl;
        cout << "1. Si es cliente preferencial" << endl;
        cout << "2. Si es un cliente no-preferencial" << endl;
        cout << "3. Ir al menu principal" << endl;
        cout << "Digite su respuesta aqui: " << endl;
        getline(cin, respuesta);
        int serviceIndex;
        if (respuesta == "1")
        {
            controller->printServices();
            cout << "Digita el numero del servicio que se adecue a tu necesidad: " << endl;
            if (!ReadInt(serviceIndex))
                cout << "Se requiere un numero. " << endl;
            if (serviceIndex < controller->getServicesQuantity())
            {
                try
                {
                    controller->generateTicket(true, serviceIndex);
                    cout << "*** Se genero correctamente el tiquete ***" << endl;
                    break;
                }
                catch (const std::exception &e)
                {
                    cout << e.what() << endl;
                }
            }
            else
                cout << "El numero debe estar en el rango correspondiente. " << endl;
        }
        if (respuesta == "2")
        {
            controller->printServices();
            cout << "Digita el numero del servicio que se adecue a tu necesidad: " << endl;
            if (!ReadInt(serviceIndex))
                cout << "Se requiere un numero. " << endl;
            if (serviceIndex < controller->getServicesQuantity())
            {
                try
                {
                    controller->generateTicket(false, serviceIndex);
                    cout << "*** Se genero correctamente el tiquete ***" << endl;
                }
                catch (const std::exception &e)
                {
                    cout << e.what() << endl;
                }
            }
            else
                cout << "El numero debe estar en el rango correspondiente. " << endl;
        }
        if (respuesta == "3")
        {
            break;
        }
        else
        {
            cout << "*** Opcion incorrecta ***" << endl;
        }
    } while (true);
}

void atender()
{
    string codigoArea;
    string serviceWCode;
    do
    {
        controller->printAreas();
        cout << "Digite el codigo del area en la que se encuentra el cliente: " << endl;
        getline(cin, codigoArea);
        controller->printArea(codigoArea);
        cout << "Digite el codigo de la ventanilla: " << endl;
        getline(cin, serviceWCode);
        try
        {
            controller->attend(codigoArea, serviceWCode);
            break;
        }
        catch (const std::exception &e)
        {
            cout << e.what() << endl;
        }
    } while (true);
}

void areaAdministracion()
{
    string opcion;
    string description;
    string areaCode;
    string serviceDescription;
    int windowsQuantity;
    int serviceIndex;
    do
    {
        cout << "\nMenu Area de administracion" << endl;
        cout << "1. Agregar Area " << endl;
        cout << "2. Eliminar Area " << endl;
        cout << "3. Agregar servicio " << endl;
        cout << "4. Eliminar servicio" << endl;
        cout << "5. Reordenar servicios " << endl;
        cout << "6. Volver al menu principal " << endl;
        cout << "\nIngrese una opcion: " << endl;
        getline(cin, opcion);
        if (opcion == "1")
        {
            cout << "Por favor ingrese la descripcion del area" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin, description);
            cout << "Por favor ingrese el codigo del area: " << endl;
            getline(cin, areaCode);

            cout << "Por favor ingrese el numero de ventanillas: ";
            if (ReadInt(windowsQuantity))
            {
                try
                {
                    controller->addArea(description, areaCode, windowsQuantity);
                    cout << "Se ha agregado el area correctamente... " << endl;
                }
                catch (const std::exception &e)
                {
                    cout << e.what() << endl;
                }
            }
            else
                cout << "Debe ingresar un numero. " << endl;
        }
        if (opcion == "2")
        {
            cout << "Por favor digite el codigo del area que desea eliminar: " << endl;
            getline(cin, areaCode);
            try
            {
                controller->deleteArea(areaCode);
            }
            catch (const std::exception &e)
            {
                cout << e.what() << endl;
            }
        }

        if (opcion == "3")
        {
            cout << " Por favor ingrese la descripcion del servicio: " << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin, serviceDescription);
            cout << "Por favor ingrese el codigo del area: " << endl;
            getline(cin, areaCode);
            try
            {
                controller->addService(areaCode, serviceDescription);
                cout << "Servicio agregado correctamente!" << endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        if (opcion == "4")
        {
            controller->printServices();
            cout << "Por favor digite el indice del servicio que desea eliminar: " << endl;
            if (ReadInt(serviceIndex))
            {
                try
                {
                    controller->deleteService(serviceIndex);
                    cout << "Servicio eliminado correctamente!" << endl;
                }
                catch (const std::exception &e)
                {
                    cout << e.what() << endl;
                }
            }
        }
        if (opcion == "5")
        {
            int initialPos, nextPos;
            controller->printServices();
            cout << "Ingresar el numero del servicio que desea cambiar de lugar: ";
            if (ReadInt(initialPos))
            {
                cout << "Ingresar el numero de la posicion donde quiere poner el servicio: ";
                if (ReadInt(nextPos))
                {
                    try
                    {
                        controller->reorder(initialPos, nextPos);
                        cout << "Se reordeno correctamente. " << endl;
                        controller->printServices();
                    }
                    catch (const std::exception &e)
                    {
                        cout << e.what() << endl;
                    }
                }
                else
                {
                    cout << "Tiene que ingresar un numero. " << endl;
                }
            }
            else
            {
                cout << "Tiene que ingresar un numero. " << endl;
            }
        }
        if (opcion == "6")
            break;
    } while (true);
}

void estadisticas()
{
    int opcion;
    string areaCode;
    string serviceWinCode;
    int serviceIndex;
    do
    {
        cout << "\nMenu estadisticas del sistema" << endl;
        cout << "1. Tiempo promedio de espera por area" << endl;
        cout << "2. Total de tiquetes dispensados por area" << endl;
        cout << "3. Total de tiquetes atendidos por ventanilla" << endl;
        cout << "4. Total de tiquetes dispensados por servicio" << endl;
        cout << "5. Total de tiquetes preferenciales dispensados en todo el sistema" << endl;
        cout << "6. Volver al Menu principal " << endl;
        cout << "\nIngrese una opcion: ";
        if (ReadInt(opcion))
        {
            if (opcion == 1)
            {
                controller->printAreas();
                cout << "Por favor digite el codigo del area: " << endl;
                getline(cin, areaCode);
                cout << "El tiempo promedio de atencion dentro de las areas es de: ";
                try
                {
                    cout << controller->getAverageWatingTime(areaCode) << "s. " << endl;
                }
                catch (const std::exception &e)
                {
                    cout << e.what() << endl;
                }
            }

            if (opcion == 2)
            {
                controller->printAreas();
                cout << "Digite el codigo del area: ";
                getline(cin, areaCode);
                cout << "La cantidad de tiquetes por area son: ";
                try
                {
                    cout << controller->getTicketQuantity(areaCode) << endl;
                }
                catch (const std::exception &e)
                {
                    cout << e.what() << endl;
                }
            }

            if (opcion == 3)
            {
                controller->printAreas();
                cout << "Por favor digite el codigo del area: " << endl;
                getline(cin, areaCode);
                cout << "Digite el codigo de la ventanilla: " << endl;
                getline(cin, serviceWinCode);
                cout << "El total de tiquetes atendidos por ventanilla es de: ";
                try
                {
                    cout << controller->getAttentedTicketsQuantity(areaCode, serviceWinCode) << endl;
                }
                catch (const std::exception &e)
                {
                    cout << e.what() << endl;
                }
            }

            if (opcion == 4)
            {
                controller->printServices();
                cout << "Por favor digite el indice del servicio: ";
                if (ReadInt(serviceIndex))
                {
                    cout << "La cantidad de tiquetes dispensados por servicio son: ";
                    try
                    {
                        cout << controller->getQuantityTicketsGiven(serviceIndex) << endl;
                    }
                    catch (const std::exception &e)
                    {
                        cout << e.what() << endl;
                    }
                }
            }
            if (opcion == 5)
            {
                cout << "La cantidad de tiquetes preferenciales dados son: ";
                try
                {
                    cout << controller->getQuantityPrefTickets() << endl;
                }
                catch (const std::exception &e)
                {
                    cout << e.what() << endl;
                }
            }
            if (opcion == 6)
                break;
        }

    } while (true);
}

int main()
{
    // se declaran las variables
    string opcion;
    bool repetir = true;

    // se imprime la bienvenida del programa
    cout << " ____________________________________________________________ " << endl;
    cout << "|                        Bienvenido!                         |" << endl;
    cout << "|____________________________________________________________| " << endl;
    cout << "|  En nuestra institucion bancaria se le ofrecen distintos   |" << endl;
    cout << "|  servicios al cliente, a continuacion se le desplegara el  |" << endl;
    cout << "|  menu principal donde prodra elegir cual servicio desea    |" << endl;
    cout << "|  adquirir.                                                 |" << endl;
    cout << "|____________________________________________________________|" << endl;
    do
    {
        cout << "\nMenu Principal de Opciones\n"
             << endl;
        cout << "1. Solicitar tiquete " << endl;
        cout << "2. Atender" << endl;
        cout << "3. Area de administracion " << endl;
        cout << "4. Estadasticas del sistema" << endl;
        cout << "5. Ver el estado de la colas " << endl;
        cout << "6. SALIR" << endl;
        cout << "\nIngrese una opcion: ";
        getline(cin, opcion);
        // comienza a ejecutar las operaciones del programa
        if (opcion == "1")
            solicitarTiquete();
        if (opcion == "2")
            atender();
        if (opcion == "3")
            areaAdministracion();
        if (opcion == "4")
            estadisticas();
        if (opcion == "5")
            controller->printQueues();
        if (opcion == "6")
        {
            cout << "Muchas gracias por utilizar nuestros servicios, hasta pronto!" << endl;
            break;
        }
        else
            cout << "Opcion fuera de rango, por favor intente de nuevo" << endl;

    } while (true);
    return 0;
}
