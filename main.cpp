#include <iostream>
#include "Area.h"
#include "Controller.h"
#include "Service.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
// El cÃƒÂ¯Ã‚Â¿Ã‚Â½digo del menÃƒÂ¯Ã‚Â¿Ã‚Â½ se hace con una estructura switch que recibe nÃƒÂ¯Ã‚Â¿Ã‚Â½meros enteros
// como entrada para poder realizar las operaciones del programa

int main()
{
    Controller *controller = new Controller();
    controller->addArea("Cajas", 'C', 4);
    controller->addArea("Empresas", 'E', 2);
    controller->addArea("Servicio al cliente", 'S', 3);
    controller->addService('S', "C", "Cobros de cliente");
    controller->addService('S', "A", "Apertura cuentas");
    controller->addService('S', "R", "Retiro de tarjetas");
    controller->addService('C', "C", "Cobros de cliente");
    controller->addService('C', "P", "Pagos de servicio");
    controller->addService('E', "PT", "Prestamos");
    controller->addService('E', "AR", "Arreglos de pago");

    //    setlocale(LC_ALL, "spanish");
    // se declaran las variables
    int opcion;
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
    // system("cls");
    do
    {
        // opciones del menÃƒÂº

        cout << "\nMenu Principal de Opciones\n"
             << endl;
        cout << "1. Solicitar tiquete " << endl;
        cout << "2. Atender" << endl;
        cout << "3. Area de administracion " << endl;
        cout << "4. Estadasticas del sistema" << endl;
        cout << "5. Ver el estado de la colas " << endl;
        cout << "6. SALIR" << endl;
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        // variables para los metodos

        char areaCode = 'D';
        string serviceCode = "Default";
        string description = "Default";
        int windowsQuantity = 0;
        string flag = "D";
        string serviceDesciption = "Default";
        string serviceWinCode = "D";

        // comienza a ejecutar las operaciones del programa
        switch (opcion)
        {
        case 1:
        {
            // Caso para solicitar un tiquete

            cout << "Por favor escoja una de las opciones: " << endl;
            cout << "1. Si es un cliente no-preferencial: " << endl;
            cout << "2. Si usted es un cliente preferencial" << endl;
            cin >> opcion;
            if (opcion == 1)
            {
                cout << controller->print() << endl;
                cout << "Por favor digite  el código de area: ";
                cin >> areaCode;
                cout << "Por favor digite el código de servicio: ";
                cin >> serviceCode;
                try
                {
                    controller->generateTicket(areaCode, false, serviceCode);
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
            if (opcion == 2)
            {
                cout << controller->print() << endl;
                cout << "Por favor digite  el código de area: ";
                cin >> areaCode;
                cout << "Por favor digite el código de servicio: ";
                cin >> serviceCode;
                try
                {
                    controller->generateTicket(areaCode, true, serviceCode);
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
            break;
        }

        case 2:
        { // Caso para atender
            cout << "Atendiendo cliente";
            cout << controller->print() << endl;
            cout << "Por favor digite el area en la que se encuentra el cliente: ";
            cin >> areaCode;
            cout << "Por favor digite el codigo de la ventana de servicio donde atenderan al cliente: ";
            cin >> serviceWinCode;
            try
            {
                controller->attend(areaCode, serviceWinCode);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
            break;
        }
        case 3:
        {
            // submenÃƒÂ¯Ã‚Â¿Ã‚Â½s
            while (true)
            {
                cout << "\nMenu Area de administracion" << endl;
                cout << "1. Agregar Area " << endl;
                cout << "2. Eliminar Area " << endl;
                cout << "3. Agregar servicio " << endl;
                cout << "4. Eliminar servicio" << endl;
                cout << "5. Reordenar servicios " << endl;
                cout << "6. Volver al menu principal " << endl;
                cout << "\nIngrese una opcion: ";
                cin >> opcion;

                if (opcion == 1)
                {

                    cout << "Por favor ingrese el codigo del area: ";
                    cin >> areaCode;
                    cout << "Por favor ingrese el numero de ventanillas: ";
                    cin >> windowsQuantity;
                    cout << "Por favor ingrese la descripcion del area: \n";
                    cin >> description;
                    try
                    {
                        controller->addArea(description, areaCode, windowsQuantity);
                        cout << "Se ha agregado el area correctamente... " << endl;
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                }
                if (opcion == 2)
                {
                    cout << "Por favor digite el codigo del area que desea eliminar: ";
                    cin >> areaCode;
                    try
                    {
                        controller->deleteArea(areaCode);
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                }

                if (opcion == 3)
                {
                    cout << "Por favor ingrese el codigo del area: ";
                    cin >> areaCode;
                    cout << " Por favor ingrese la descripcion del servicio: ";
                    cin >> serviceDesciption;
                    cout << "Por favor ingrese el codigo del servicio: ";
                    cin >> serviceCode;
                    try
                    {
                        controller->addService(areaCode, serviceCode, serviceDesciption);
                        cout << "Servicio agregado correctamente!" << endl;
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                }

                if (opcion == 4)
                {
                    cout << "Por favor digite el codigo del Area donde se encuentra el servicio: ";
                    cin >> areaCode;
                    cout << "Por favor digite el codigo del servicio que desea eliminar: ";
                    cin >> serviceCode;
                    try
                    {
                        controller->deleteService(areaCode, serviceCode);
                        cout << "Servicio eliminado correctamente!" << endl;
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                }

                if (opcion == 5){
                    int initialPos, nextPos;
                    cout << "Por favor digite el codigo del Area donde se encuentra el servicio: ";
                    cin >> areaCode;
                    cout << controller->printArea(areaCode) << endl; 
                    cout << "Ingresar el numero del servicio que desea cambiar de lugar: ";
                    cin >> initialPos;
                    cout << "Ingresar el numero de la posicion donde quiere poner el servicio: ";
                    cin >> nextPos;
                    try
                    {
                        controller->reorder(areaCode, initialPos, nextPos);
                        cout << "Se reordeno correctamente. " << endl;
                        cout << controller->printArea(areaCode) << endl; 
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                }
                if (opcion == 6)
                    break;
            }
            break;
        }
        case 4:
        {
            // submenÃƒÂ¯Ã‚Â¿Ã‚Â½s
            while (true)
            {
                cout << "\nMenu estadisticas del sistema" << endl;
                cout << "1. Tiempo promedio de espera por area" << endl;
                cout << "2. Total de tiquetes dispensados por area" << endl;
                cout << "3. Total de tiquetes atendidos por ventanilla" << endl;
                cout << "4. Total de tiquetes dispensados por servicio" << endl;
                cout << "5. Total de tiquetes preferenciales dispensados en todo el sistema" << endl;
                cout << "6. Volver al Menu principal " << endl;
                cout << "\nIngrese una opcion: ";
                cin >> opcion;
                if (opcion == 1)
                {
                    cout << controller->print()<< endl;
                    cout << "Por favor digite el codigo del area: ";
                    cin >> areaCode;
                    cout << "El tiempo promedio de atencion dentro de las areas es de: ";
                    try
                    {
                        cout << controller->getAverageWatingTime(areaCode) << "s. " << endl;
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                }

                if (opcion == 2)
                {
                    cout << controller->print()<< endl;
                    cout << "Digite el codigo del area: ";
                    cin >> areaCode;
                    cout << "La cantidad de tiquetes por area son: ";
                    try
                    {
                        cout << controller->getTicketQuantity(areaCode) << endl;
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                }

                if (opcion == 3)
                {
                    cout << controller->print()<< endl;
                    cout << "Por favor digite el codigo del area: ";
                    cin >> areaCode;
                    cout << "Digite el codigo de la ventanilla: ";
                    cin >> serviceWinCode;
                    cout << "El total de tiquetes atendidos atendidos por ventanilla es de: ";
                    try
                    {
                        cout << controller->getAttentedTicketsQuantity(areaCode, serviceWinCode) << endl;
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                }

                if (opcion == 4)
                {
                    cout << controller->print()<< endl;
                    cout << "Por favor digite el codigo de area: ";
                    cin >> areaCode;
                    cout << "Por favor digite el codigo de servicio: ";
                    cin >> serviceCode;
                    cout << "La cantidad de tiquetes dispensados por servicio son: ";
                    try
                    {
                        cout << controller->getQuantityTicketsGiven(areaCode, serviceCode) << endl;
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << e.what() << '\n';
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
                        std::cerr << e.what() << '\n';
                    }
                }
                if (opcion == 6)
                    break;
                
            }
            break;
        }
        case 5:
            controller->printQueues();
            break;
        case 6:
            cout << "Muchas gracias por utilizar nuestros servicios, hasta pronto!" << endl;
            repetir = false;
            break;
        default:
            cout << "Opcion fuera de rango, por favor intente de nuevo" << endl;
        }
    } while (repetir);
    return 0;
}
// return 0;
