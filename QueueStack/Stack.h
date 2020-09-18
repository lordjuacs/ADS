//
// Created by AIO on 10/09/2020.
//

#ifndef WEEK_2_STACK_H
#define WEEK_2_STACK_H
#include <iostream>
using namespace std;

class Stack {
private:
    int* array;
    int capacity;
    int size;
public:
    explicit Stack(int _capacity){
        array = nullptr;
        array = new int[_capacity];
        capacity = _capacity;
        size = 0;
    }
    ~Stack(){
        delete[] array;
        array = nullptr;
    }
    void push(int data){
        //Best case: 1, Worst case: n
        if (size == capacity)
        {
            capacity *= int(1.5);
            int* aux = nullptr;
            aux = new int[capacity];
            for (int i = 0; i < size; ++i)
                aux[i] = array[i];
            aux[size] = data;
            size++;
            delete[] array;
            array = nullptr;
            array = aux;
        }
        else
        {
            array[size++] = data;
        }
    }
    int pop(){
        //Best case: 1
        if (!size)
        {
            throw runtime_error("Empty Stack");
        }
        return array[--size];
    }
    void display(){
        if(!size)
            cout << "Empty Stack" << endl;
        for (int i = size - 1; i >= 0; i--)
        {
            cout << array[i] << endl;
        }
    }
};


#endif //WEEK_2_STACK_H
