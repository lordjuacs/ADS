#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};

// TODO: implement here
void push_front(Node* &head, int val){
    Node* nodo = new Node();
    nodo->data = val;
    nodo->next = head;
    head = nodo;
}

void push_back(Node* &tail, int val){
    if(tail == nullptr){
        Node* nodo = new Node();
        nodo->data = val;
        nodo->next = nullptr;
        tail = nodo;
        return;
    }
    Node* nodo = new Node();
    nodo->data = val;
    nodo->next = tail;
    tail = nodo;

}

Node* SortedMerge(Node* l1, Node* l2){
    Node* t1 = l1;
    Node* t2 = l2;
    Node* l3 = nullptr;
    while(t1 != nullptr && t2!= nullptr){
        if(t1->data == t2->data){
            push_back(l3, t1->data);
            push_back(l3, t2->data);
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->data > t2->data){
            push_back(l3, t1->data);
            t1 = t1->next;
        }
        else {
            push_back(l3, t2->data);
            t2 = t2->next;
        }
    }
    if(t1 == nullptr){
        while(t2 != nullptr){
            push_back(l3, t2->data);
            t2 = t2->next;
        }
    }
    else {
        while(t1 != nullptr){
            push_back(l3, t1->data);
            t1 = t1->next;
        }
    }
    return l3;
}

