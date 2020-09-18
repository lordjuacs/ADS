//
// Created by AIO on 10/09/2020.
//

#ifndef WEEK_2_QUEUE_H
#define WEEK_2_QUEUE_H


class Queue {
private:
    int* array;
    int capacity;
    int size;
public:
    explicit Queue(int _capacity){
        array = new int[_capacity];
        capacity = _capacity;
        size = 0;
    }
    ~Queue(){
        delete[] array;
        array = nullptr;
    }
    void enqueue(int data){
        //Best case: 1
        if (size == capacity)
        {
            capacity *= int(1.5);
            int* aux = new int[capacity];
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
    int dequeue(){
        //Best case: n
        if (!size)
        {
            throw runtime_error("Empty Queue");
        }
        int front = array[0];
        for(int i = 1; i < size; ++i)
            array[i-1] = array[i];
        size--;
        return front;
    }
    void display(){
        if(!size)
            cout << "Empty Queue" << endl;
        for (int i = size - 1; i >= 0; i--)
        {
            cout << array[i] << endl;
        }
    }
};


#endif //WEEK_2_QUEUE_H
