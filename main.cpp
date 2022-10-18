#include <iostream>
#include "Area.h"
#include "Controller.h"
#include "Service.h"
using namespace std;
//El cÃ¯Â¿Â½digo del menÃ¯Â¿Â½ se hace con una estructura switch que recibe nÃ¯Â¿Â½meros enteros
//como entrada para poder realizar las operaciones del programa


int main (){
      Controller * controller = new Controller();
//    setlocale(LC_ALL, "spanish");
    // se declaran las variables
    int opcion;
    bool repetir = true;
    string desc;
    int wind;
    char codeA;
    string servic;
    string serviceCode;
    int fin = 1;
    cout << "Por favor agregue las áreas" << endl;
    while (fin > 0){
        cout << "Por favor ingrese la describción del area: ";
        cin >> desc;
        cout << "Por favor ingrese el número de ventanillas: ";
        cin >> wind;
        cout << "Por favor ingrese el código del area: ";
        cin >> codeA;
        controller->addArea(desc, codeA, wind);
        cout << "Se ha agregado el area correctamente... " << endl;
        cout << "Desea agregar más? Si = 1, No = 0: ";
        cin >> fin;
    }
    cout << "Por favor agregue los servicios" << endl;
     fin = 1;
     while (fin > 0){
        cout << "Por favor ingrese el código del Ã¡rea: ";
        cin >> codeA;;
        cout <<" Por favor ingrese la descripción del servicio: ";
        cin >> servic;
        cout << "Por favor ingrese el código del servicio: ";
        cin >> serviceCode;
        controller->addService(codeA,serviceCode, servic);
        cout << "Servicio agregado correctamente!" << endl;
        cout << "Desea agregar más? Si = 1, No = 0: ";
        cin >> fin;
    }

    //se imprime la bienvenida del programa
    cout << " ____________________________________________________________ "<< endl;
    cout << "|                        Bienvenido!                        |"<< endl;
    cout << "|____________________________________________________________| "<< endl;
    cout << "|  En nuestra institucion bancaria se le ofrecen distintos   |" << endl;
    cout << "|  servicios al cliente, a continuacion se le desplegara el  |" << endl;
    cout << "|  menu principal donde prodra elegir cual servicio desea    |" << endl;
    cout << "|  adquirir.                                                 |" << endl;
    cout << "|____________________________________________________________|" << endl;
   // system("cls");
        do {
            //opciones del menÃº

            cout << "\nMenu Principal de Opciones\n" << endl;
            cout << "1. Solicitar tiquete " << endl;
            cout << "2. Atender" << endl;
            cout << "3. Area de administracion " << endl;
            cout << "4. Estadasticas del sistema" << endl;
            cout << "5. Ver el estado de la colas " << endl;
            cout << "6. SALIR" << endl;
            cout << "\nIngrese una opcion: ";
            cin >> opcion;
            //variables para los metodos

            char areaCode;
            string serviceCode;

                //comienza a ejecutar las operaciones del programa
                switch (opcion) {
                case 1:
                    //Caso para solicitar un tiquete
                    cout << "Por favor escoja una de las opciones: " << endl;
                    cout << "1. Si es un cliente no-preferencial: " << endl;
                    cout << "2. Si usted es un cliente preferencial" << endl;
                    cin >> opcion;
                    if (opcion == 1){
                        
                    break;
                    }
                    if (opcion == 2){

                    break;
                    }

                case 2: //Caso para atender
                    cout <<"Atendiendo cliente";
                    cout << "Por favor digite el area en la que se encuentra el cliente: ";
                    cin >> areaCode;
                    cout << "Por favor digite el servicio en donde estÃ¡ el cliente: ";
                    cin >> serviceCode;
                    controller->attend(areaCode, serviceCode);
                    break;

                case 3:
                    //submenÃ¯Â¿Â½s

                    cout << "\nMenu Area de administracion" << endl;
                    cout << "1. Agregar Area " << endl;
                    cout << "2. Eliminar Area " << endl;
                    cout << "3. Agregar servicio " << endl;
                    cout << "4. Eliminar servicio" << endl;
                    cout << "5. Reordenar servicios " << endl;
                    cout << "6. Volver al menu principal " << endl;
                    cout << "\nIngrese una opcion: ";
                    cin >> opcion;

                        if (opcion==1){
                            string desc;
                            int wind;

                            cout << "Por favor ingrese la describciÃ³n del Ã¡rea: ";
                            cin >> desc;
                            cout << "Por favor ingrese el numero de ventanillas: ";
                            cin >> wind;
                            cout << "Por favor ingrese el codigo del Ã¡rea: ";
                            cin >> areaCode;
                            try{
                                controller->addArea(desc, areaCode, wind);
                                cout << "Se ha agregado el area correctamente... " << endl;
                            }catch(const std::exception& e){
                                std::cerr << e.what() << '\n';
                            }
                            break;
                            }
                        if (opcion==2){
                            cout << "Por favor digite el codigo del area que desea eliminar";
                            cin>> areaCode;
                            try{
                                controller->deleteArea(areaCode);
                            }catch(const std::exception& e){
                                std::cerr << e.what() << '\n';
                            }


                            break;
                        }

                        if (opcion==3){
                            string servic;
                            cout << "Por favor ingrese el codigo del Ã¡rea: ";
                            cin >> areaCode;
                            cout <<" Por favor ingrese la descripcion del servicio: ";
                            cin >> servic;
                            cout << "Por favor ingrese el codigo del servicio: ";
                            cin >> serviceCode;
                            try{
                                controller->addService(areaCode,serviceCode, servic);
                                cout << "Servicio agregado correctamente!" << endl;
                            }catch (const std:: exception& e){
                                std:: cerr << e.what() << '\n';

                            }

                             break;
                        }

                        if (opcion==4){
                            cout << "Por favor digite el código del Area donde se encuentra el servicio: ";
                            cin >> areaCode;
                            cout << "Por favor digite el cóigo del servicio que desea eliminar: ";
                            cin >> serviceCode;
                            try{
                                controller->deleteService(areaCode, serviceCode);
                                cout << "Servicio eliminado correctamente!" << endl;
                            }catch(const std:: exception& e){
                                std:: cerr << e.what() << '\n';
                            }
                            break;

                        }

                        if (opcion==5) // no se hizo
                            break;
                        if (opcion==6){
                            return repetir = true;
                        }




                case 4:
                    //submenÃ¯Â¿Â½s

                    cout << "\nMenÃº estadisticas del sistema" << endl;
                    cout << "1. Tiempo promedio de espera por area" << endl;
                    cout << "2. Total de tiquetes dispensados por area" << endl;
                    cout << "3. Total de tiquetes atendidos por ventanilla" << endl;
                    cout << "4. Total de tiquetes dispensados por servicio" << endl;
                    cout << "5. Total de tiquetes preferenciales dispensados en todo el sistema" << endl;
                    cout << "6. Volver al menÃº principal " << endl;
                    cout << "\nIngrese una opcion: ";
                    cin >> opcion;
                    if (opcion==1){
                        cout << "Por favor digite el codigo del area: ";
                        cin >> areaCode;
                        cout << "El tiempo promedio de atencion dentro de las areas es de: ";
                        try {
                            controller->getAverageWatingTime(areaCode);
                        }catch(const std:: exception& e){
                                std:: cerr << e.what()<< '\n';
                            }
                        break;
                    }

                    if (opcion==2){
                        char areaCode;
                        cout << "Digite el codigo del area: ";
                        cin >> areaCode;
                        cout << "La cantidad de tiquetes por area son: "<< endl;
                        try{
                            controller->getTicketQuantity(areaCode);
                        }catch(const std:: exception& e){
                                std:: cerr << e.what() <<'\n';
                            }
                        break;
                    }

                    if (opcion==3){
                        string windowCode;
                        cout << "Por favor digite el codigo del Ã¡rea: ";
                        cin >> areaCode;
                        cout << "Digite el codigo de la ventanilla: ";
                        cin >> windowCode;
                        cout << "El total de tiquetes atendidos atendidos por ventanilla es de: ";
                        try{
                            controller->getAttentedTicketsQuantity(areaCode, windowCode);
                        }catch(const std:: exception& e){
                                std:: cerr << e.what() <<'\n';
                            }
                        break;
                    }

                    if (opcion==4){
                        string serviceCode;
                        cout << "Por favor digite el codigo de area: ";
                        cin >> areaCode;
                        cout << "Por favor digite el codigo de servicio: ";
                        cin >> serviceCode;
                        try{
                            controller->getQuantityTicketsGiven(areaCode, serviceCode);
                        }catch(const std:: exception& e){
                                std:: cerr << e.what() << '\n';
                            }
                        break;
                    }
                    if (opcion==5){
                        cout << "La cantidad de tiquetes dados son: ";
                        try{
                            controller->getQuantityPrefTickets();
                        }catch(const std:: exception& e){
                                std:: cerr << e.what()<< '\n';
                            }
                        break;
                    }
                    if (opcion==6)
                        return repetir=true;

                case 5:
                    controller->printQueues();
                    break;
                case 6:
                    cout << "Muchas gracias por utilizar nuestros servicios, hasta pronto!" << endl;
                    repetir = false;
                    break;
                default:
                    cout << "opciÃ³n fuera de rango, por favor intente de nuevo" << endl;

                }
        } while (repetir);
        return 0;
        }
        //return 0;
