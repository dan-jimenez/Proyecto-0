#include "Tiquete.h"
#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int main(int argc, char const *argv[]){
    Ticket * nuevo = new Ticket("S09", false);
    int flag; 
    cout << "Programa en pausa... Presione enter para continuar... " << endl; cin >> flag;
    cout << "Continuando programa..." << endl;
    nuevo->setEndingTime(system_clock::to_time_t(system_clock::now()));
    cout << "El tiquete duro: " << nuevo->getDuration() << "s\n";
    return 0;
}
