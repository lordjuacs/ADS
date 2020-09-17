//
// Created by AIO on 16/09/2020.
//

#ifndef WEEK_3_CIRCULARARRAY_H
#define WEEK_3_CIRCULARARRAY_H
#include <iostream>
#include "MergeSort.h"

using namespace std;
template<typename T>
class CircularArray {
private:
    T* arr;
    int capacity;
    int front;
    int rear;
public:
    CircularArray();
    ~CircularArray();
    CircularArray(int _capacity);
    T get_front();
    T back();
    void push_front(T data);
    void push_back(T data);
    T pop_front();
    T pop_back();
    void insert(T data, int pos);
    T operator[](int pos);
    bool empty();
    bool full();
    int size();
    void clear();
    void sort();
    void display();
    T* reverse();

};

template<typename T>
CircularArray<T>::CircularArray() {
    arr = new T[10];
    capacity = 10;
    front = rear = -1;
}

template<typename T>
CircularArray<T>::CircularArray(int _capacity) {
    arr = new T[_capacity];
    capacity = _capacity;
    front = rear = -1;
}

template<typename T>
CircularArray<T>::~CircularArray() {
    if (arr != nullptr){
        delete [] arr;
        arr = nullptr;
    }
    cout << "Array erased" << endl;
}

template<typename T>
T CircularArray<T>::get_front() {
    if (front != -1)
        return arr[front];
    cerr << "Empty Array" << endl;
    return -1;
}

template<typename T>
T CircularArray<T>::back() {
    if (rear != -1){
        return arr[rear];
    }
    cerr << "Empty Array" << endl;
    return -1;
}

template<typename T>
void CircularArray<T>::push_front(T data) {
    if(empty()){
        front = rear = 0;
        arr[rear] = data;
        return;
    }
    else if (full()){
        cerr << "Array is full" << endl;
        return;
    }
    front = ((front - 1) %capacity < 0)? ((front - 1)%capacity) + capacity: ((front - 1)%capacity);
    arr[front] = data;
}

template<typename T>
void CircularArray<T>::push_back(T data) {
    if(empty()){
        front = rear = 0;
        arr[rear] = data;
        return;
    }
    else if (full()){
        cerr << "Array is full" << endl;
        return;
    }
    ++rear %= capacity;
    arr[rear] = data;
}

template<typename T>
T CircularArray<T>::pop_front() {
    if (empty()){
        cerr << "Array is empty" << endl;
        return -1;
    }
    else if (front == rear){
        T temp = arr[front];
        front = rear = -1;
        return temp;
    }
    T temp = arr[front];
    ++front %= capacity;
    return temp;
}

template<typename T>
T CircularArray<T>::pop_back() {
    if(empty()){
        cerr << "Array is empty" << endl;
        return -1;
    }
    else if (front == rear){
        T temp = arr[rear];
        front = rear = -1;
        return temp;
    }
    T temp = arr[rear];
    rear = ((rear - 1) %capacity < 0)? ((rear - 1)%capacity) + capacity: ((rear - 1)%capacity);
    return temp;
}

template<typename T>
void CircularArray<T>::insert(T data, int pos) {
    int size = (front == -1 && rear == -1)? 0 : ((front > rear) ? (capacity - front + rear + 1) : (rear - front + 1));
    if(full()){
        cerr << "Array is full" << endl;
        return;
    }
    else if (pos >= 0 && pos <= size){
        if (size + 1 <= capacity){
            if (!size)
                front = rear = 0;
            int split = (front + pos)%capacity;
            int swaps = size - pos;
            int i = (size + front)%capacity;
            int new_rear = i;
            while(swaps--){
                arr[i] = arr[rear];
                rear = ((rear - 1) %capacity < 0)? ((rear - 1)%capacity) + capacity: ((rear - 1)%capacity);
                i = ((i - 1) %capacity < 0)? ((i - 1)%capacity) + capacity: ((i - 1)%capacity);
            }
            arr[split] = data;
            rear = new_rear;
        }
        else{
            cerr << "Capacity reached - Overload" << endl;
        }
    }
    else{
        cerr << "Unable to do that - Continous cells must be initialized" << endl;
    }
}

template<typename T>
T CircularArray<T>::operator[](int pos) {
    int size = (front > rear) ? (capacity - front + rear + 1) : (rear - front + 1);
    if (pos >= 0 && pos < size)
        return arr[(front + pos)%capacity];
    cerr << "Position not available" << endl;
    return nullptr;
}

template<typename T>
bool CircularArray<T>::empty() {
    return (front == -1) && (rear == -1);
}

template<typename T>
bool CircularArray<T>::full() {
    //return (rear + 1 == capacity && front == 0) || (rear - front == -1);
    return (((rear + 1) % capacity) == front);
}

template<typename T>
int CircularArray<T>::size() {
    return(front == -1 && rear == -1)? 0 : ((front > rear) ? (capacity - front + rear + 1) : (rear - front + 1));
}

template<typename T>
void CircularArray<T>::clear() {
    delete [] arr;
    arr = nullptr;
    cout << "Array cleared" << endl;
}

template<typename T>
void CircularArray<T>::sort() {
    int size = (front > rear) ? (capacity - front + rear + 1) : (rear - front + 1);
    T* rev_array = reverse();
    delete [] arr;
    arr = rev_array;
    front = 0;
    rear = size - 1;
    mergeSort(arr, front, rear);
}

template<typename T>
void CircularArray<T>::display() {
    if (empty()){
        cout << "Nothing to display" << endl;
        return;
    }
    int i = front;
    while ( i != rear){
        cout << arr[i] << " ";
        ++i %= capacity;
    }
    cout << arr[rear] << endl;
}

template<typename T>
T *CircularArray<T>::reverse() {
    if (empty()){
        cout << "Empty array" << endl;
        return nullptr;
    }
    T* rev_arr = new T[capacity];
    int i = front;
    int pos = capacity - 1;
    while ( i != rear){
        rev_arr[pos] = arr[i];
        ++i %= capacity;
        --pos;
    }
    rev_arr[pos] = arr[rear];
    return rev_arr;
}

#endif //CIRCULARARRAY_CIRCULARARRAY_H
