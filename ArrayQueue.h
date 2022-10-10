#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <iostream>
#include <stdexcept>
#include "Queue.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class ArrayQueue : public Queue<E>{
private:
    E * elements;
    int front;
    int back;
    int max;
    int size;
    
    void emptyWarning(){
        if (size == 0)
            throw runtime_error("Queue is empty. ");
    }

public:
    ArrayQueue(int max = DEFAULT_MAX_SIZE){
        if (max <= 0)
            throw runtime_error("Invalid max size. "); 
        elements = new E[max];
        size = front = back = 0;
        this->max = max;
    }
    ~ ArrayQueue(){
        delete [] elements;
    }
    void enqueue(E element){
        if (size == max)
            throw runtime_error("Queue is full. ");
        elements[back] = element;
        back = (back + 1) % max;
        size++;
    }
    E dequeue(){
        emptyWarning();
        front = (front + 1) % max;
        size--;
        return elements[(front+max-1)%max];
    }
    E frontValue(){
        emptyWarning();
        return elements[front];
    }
    bool isEmpty(){
        return size == 0;
    }
    void clear(){
        size = front = back = 0;
    }
    int getSize(){
        return size;
    }
    void print(){
        cout << "{ ";
        int i = front;
        while (i != back){
            cout << elements[i] << " - ";
            i = (i + 1) % max;
        }
        cout << " }"<< endl;
    }
    void enqueueFront(E element){
        if (size == max)
            throw runtime_error("Queue is full. ");
        front = (front + max - 1) % max;
        elements[front] = element;
        size++;
    }
    E dequeueBack(){
        emptyWarning();
        back = (back+max-1) % max;
        size--;
        return elements[back];
    }
    E backValue(){
        emptyWarning();
        return elements[(back+max-1)%max];
    }

};





#endif //ARRAYQUEUE_H