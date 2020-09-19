//
// Created by AIO on 19/09/2020.
//

#ifndef LIST_NODE_H
#define LIST_NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    //Node<T>* prev = nullptr;
    void killSelf(){
        delete this;
    }
};


#endif //LIST_NODE_H
