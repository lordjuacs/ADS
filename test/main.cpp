#include <iostream>
#include "solution.h"

using namespace std;

int main() {
    Node* l1 = nullptr;
    Node* l2 = nullptr;
    int val;

    while(true){
        cin>>val;
        if(val == 0) break;
        push_front(l1, val);

    }
    while(true){
        cin>>val;
        if(val == 0) break;
        push_front(l2, val);

    }

    Node* l3 = SortedMerge(l1, l2);

    Node* temp = l3;
    while(temp != nullptr){
        cout<<temp->data<<endl;
        temp = temp->next;
    }

}