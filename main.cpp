#include <iostream>
#include "Area.h"
#include "Controller.h"
using namespace std;
//El c�digo del men� se hace con una estructura switch que recibe n�meros enteros
//como entrada para poder realizar las operaciones del programa


int main (){
    Controller * controller = new Controller();
//    setlocale(LC_ALL, "spanish");
    // se declaran las variables
    int opcion;
    bool repetir = true;
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
            //opciones del men�
            cout << "\nMenu Principal de Opciones\n" << endl;
            cout << "1. Solicitar tiquete " << endl;
            cout << "2. Atender" << endl;
            cout << "3. Area de administracion " << endl;
            cout << "4. Estadasticas del sistema" << endl;
            cout << "5. Ver el estado de la colas " << endl;
            cout << "6. Regresar al menu principal" << endl;
            cout << "0. SALIR" << endl;
            cout << "\nIngrese una opcion: ";
            cin >> opcion;
                //comienza a ejecutar las operaciones del programa
                switch (opcion) {
                case 1:
                    //Caso para solicitar un tiquete
                    cout << "Ingrese los datos necesarios: ";
                    break;

                case 2: //Caso para atender
                    cout <<"Atendiendo cliente";
                    break;

                case 3:
                    //submen�s

                    cout << "\nMenu Area de administracion" << endl;
                    cout << "1. Agregar Area " << endl;
                    cout << "2. Eliminar Area " << endl;
                    cout << "3. Agregar servicio " << endl;
                    cout << "4. Eliminar servicio" << endl;
                    cout << "5. Reordenar servicios " << endl;
                    cout << "6. Volver al menu principal " << endl;
                    cout << "\nIngrese una opcion: ";
                    cin >> opcion;

                        if (opcion==1)
                            break;
                        if (opcion==2)
                            break;
                        if (opcion==3)
                            break;
                        if (opcion==4)
                            break;
                        if (opcion==5)
                            break;
                        if (opcion==6){
                            return repetir = true;
                        }




                case 4:
                    //submen�s

                    cout << "\nMen� estad�sticas del sistema" << endl;
                    cout << "1. Tiempo promedio de espera por �rea  " << endl;
                    cout << "2. Total de tiquetes dispensados por �rea  " << endl;
                    cout << "3. Total de tiquetes atendidos por ventanilla  " << endl;
                    cout << "4. Total de tiquetes dispensados por servicio " << endl;
                    cout << "5. Total de tiquetes preferenciales dispensados en todo el sistema " << endl;
                    cout << "6. Volver al men� principal " << endl;
                    cout << "\nIngrese una opcion: ";
                    cin >> opcion;
                    if (opcion==1)
                        break;
                    if (opcion==2)
                        break;
                    if (opcion==3)
                        break;
                    if (opcion==4)
                        break;
                    if (opcion==5)
                        break;
                    if (opcion==6)
                        return repetir=true;

                case 5:
                    break;
                case 6:
                    break;
                case 0:
                    cout << "Muchas gracias por utilizar nuestros servicios, hasta pronto!" << endl;
                    repetir = false;
                    break;
                default:
                    cout << "opci�n fuera de rango, por favor intente de nuevo" << endl;

                }
        } while (repetir);
        return 0;
        }
        //return 0;

