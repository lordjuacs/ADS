//
// Created by AIO on 17/09/2020.
//

#ifndef LIST_FORWARDLIST_H
#define LIST_FORWARDLIST_H
#include "List.h"

template <typename T>
class ForwardList: public List<T> {
public:
    ForwardList():List<T>(){}
    ~ForwardList();

    T front() override {
        if(List<T>::head = nullptr)
            throw "Head is empty";
        return List<T>::head->data;
    }
    T back() override {
        if(List<T>::tail = nullptr)
            throw "Tail is empty";
        return List<T>::tail->data;
    }
    void push_front(T) override {

    }
    void push_back(T) override {

    }
    void pop_front() override {

    }
    void pop_back() override {

    }
    T operator[](int) override {

    }
    bool empty() override {

    }
    int size() override {

    }
    void clear() override {

    }
    void sort() override {

    }
    void reverse() override {

    }
};


#endif //LIST_FORWARDLIST_H
