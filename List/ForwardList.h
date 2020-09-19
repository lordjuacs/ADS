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
    ~ForwardList(){
        clear();
    }

    T front() override {
        if(this->head == nullptr)
            throw "Head is empty";
        return this->head->data;
    }
    T back() override {
        if(this->tail == nullptr)
            throw "Tail is empty";
        return this->tail->data;
    }
    void push_front(T value) override {
        this->head = new Node<T>{value, this->head};
        if(this->tail == nullptr){
            this->tail = this->head;
        }
        this->nodes++;
    }
    void push_back(T value) override {
        Node<T>* new_tail = new Node<T>{value, nullptr};
        this->nodes++;
        if (this->head == nullptr) {
            this->head = this->tail = new_tail;
            return;
        }
        this->tail->next = new_tail;
        this->tail = new_tail;
    }
    void pop_front() override {
        if(empty())
            throw "List is empty";
        this->nodes--;
        if (this->head == this->tail){
            this->head->killSelf();
            this->tail->killSelf();
            this->head = nullptr;
            this->tail = nullptr;
            return;
        }
        Node<T>* new_head = this->head->next;
        this->head->killSelf();
        this->head = new_head;
    }
    void pop_back() override {
        if(empty())
            throw "List is empty";
        this->nodes--;
        if (this->head == this->tail){
            this->head->killSelf();
            this->tail->killSelf();
            this->head = nullptr;
            this->tail = nullptr;
            return;
        }
        Node<T>* new_tail = this->head;
        int last_pos = this->nodes - 1;
        while (last_pos--)
            new_tail = new_tail->next;
        new_tail->next = nullptr;
        this->tail->killSelf();
        this->tail = new_tail;
    }
    T operator[](int pos) override {
        if(empty())
            throw "List is empty";
        else if (pos < 0 || pos > this->nodes - 1)
            throw "Invalid position";
        Node<T>* current = this->head;
        while(pos--)
            current = current->next;
        return current->data;
    }
    bool empty() override {
        return (this->head == nullptr);
    }
    int size() override {
        return this->nodes;
    }
    void clear() override {
        Node<T> *current = this->head;
        while (current != nullptr) {
            Node<T> *next = current->next;
            current->killSelf();
            current = next;
        }
        this->head = nullptr;
        this->tail = nullptr;
        this->nodes = 0;
    }
    void sort() override {

    }
    void reverse() override {
        this->tail = this->head;
        Node<T>* current = this->head;
        Node<T>* prev = nullptr;
        Node<T>* next = this->head;
        while (next != nullptr) {
            next = next->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        this->head = prev;

    }
    void display() override {
        if(empty())
            throw "Nothing to display";
        Node<T>* current = this->head;
        while(current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


#endif //LIST_FORWARDLIST_H
