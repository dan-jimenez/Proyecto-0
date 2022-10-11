#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#define DEFAULT_MAX_SIZE 1024

#include <stdexcept>
#include <iostream>
#include "List.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class ArrayList : public List<E> {
protected:
    E *elements;
    int max;
    int size;
    int pos;

    void checkFullList() {
        if (size == max)
            throw runtime_error("List is full.");
    }
    void emptyList(){
        if (size == 0)
            throw runtime_error("List is empty.");
    }
    void expand(){
        //Expande la lista al doble de su tamanio sin borrar los datos
        // Probar metodo
        E * L = new E[max*2];
        for(int i = 0; i < size; i++){
            L[i] = elements[i];
        }
        delete [] elements;
        elements = L;
        max = max*2;
    }
public:
    ArrayList(int max = DEFAULT_MAX_SIZE) {
        if (max < 1)
            throw runtime_error("Invalid max size.");
        elements = new E[max];
        this->max = max;
        size = 0;
        pos = 0;
    }
    ~ArrayList() {
        delete [] elements;
    }
    void insert(E element) {
        if(size == max)
            expand();
        for (int i = size; i > pos; i--)
            elements[i] = elements[i - 1];
        elements[pos] = element;
        size++;
    }
    void append(E element) {
        if(size == max)
            expand();
        elements[size] = element;
        size++;
    }
    E remove() {
        emptyList();
        if (pos == size)
            throw runtime_error("No current element.");
        E result = elements[pos];
        for (int i = pos; i < size - 1; i++)
            elements[i] = elements[i + 1];
        size--;
        return result;
    }
    void clear() {
        size = pos = 0;
        //delete [] elements;
        //elements = new E[max];
    }
    E getElement() {
        if (size == 0)
            throw runtime_error("List is empty.");
        if (pos == size)
            throw runtime_error("No current element.");
        return elements[pos];
    }
    void goToStart() {
        pos = 0;
    }
    void goToEnd() {
        pos = size;
    }
    void goToPos(int pos) {
        if (pos < 0 || pos > size)
            throw runtime_error("Invalid index.");
        this->pos = pos;
    }
    void next() {
        if (pos < size)
            pos++;
    }
    void previous() {
        if (pos > 0)
            pos--;
    }
    bool atStart() {
        return pos == 0;
    }
    bool atEnd() {
        return pos == size;
    }
    int getPos() {
        return pos;
    }
    int getSize() {
        return size;
    }
    void print() {
        int pos = getPos();
        cout << "[ ";
        for (goToStart(); !atEnd(); next())
            cout << getElement() << " - ";
        cout << " ]" << endl;
        goToPos(pos);
    }
    int indexOf(E element){
        emptyList();
        //Recibe un elemento E y retorna la posicion en donde se encuentra
        int posi = 0;
        int currentPos = getPos();
        for (goToStart(); !atEnd(); next()){
            if(getElement() == element){
                goToPos(currentPos);
                return posi;
            }
            posi++;
        }
        return -1;
    }
    bool contains(E element){
        emptyList();
        //Busca un elemento y si lo encuentra retorna true
        int pos = getPos();
        for (goToStart(); !atEnd(); next()){
            if(getElement() == element){
                goToPos(pos);
                return true;
            }
        }
        return false;
    }
    void extend(List<E> *L){
        //Extiende la lista en un x2
        // Probar metodo
        int i = L->getPos();
        for (L->goToStart(); !L->atEnd(); L->next()){
            this->append(L->getElement());
        }
        L->goToPos(i);
    }

    bool equals(List<E> *L){
        //Comprueba si dos listas son iguales tanto en forma como en contenido
        // Probar metodo
        if(L->getSize() != size)
            return false;
        int i = L->getPos();
        int currentPos = getPos();
        goToStart();
        for (L->goToStart(); !L->atEnd(); L->next()){
            if(L->getElement() != getElement()){
                goToPos(currentPos);
                L->goToPos(i);
                return false;
            }
            next();
        }
        goToPos(currentPos);
        L->goToPos(i);
        return true;
    }
};

#endif // ARRAYLIST_H
