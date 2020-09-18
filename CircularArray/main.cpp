#include "CircularArray.h"
#include <assert.h>
using namespace std;
#define test1
#define test2
int main() {
#ifdef test1
    CircularArray<int>* first = new CircularArray<int>(5);

    first->push_back(1);
    first->push_back(2);
    first->push_front(3);
    first->push_front(4);
    first->push_back(5);
    assert(first->get_front() == 4);
    assert(first->back() == 5);
    first->push_back(13);
    first->display();
    cout << "SIZE: " << first->size() << endl;
    int* reverse_first = first->reverse();
    for(int i = 0; i < first->size(); ++i)
        cout << reverse_first[i] << " ";
    cout << endl;
    first->sort();
    first->pop_back();
    first->pop_front();
    first->pop_back();
    first->pop_front();
    first->pop_front();
    first->display();
    assert(first->pop_front() == -1);
    first->display();
    delete first;
#endif
#ifdef test2
    CircularArray<double>* second = new CircularArray<double>(5);
    cout << "SIZE:" << second->size() << endl;
    second->insert(7, 0);
    second->display();
    second->insert(6, 1);
    second->display();
    second->push_back(11);
    second->push_front(10);
    second->push_front(9);
    second->push_front(8);
    second->display();
    second->insert(7, 0);
    second->display();
    delete second;
#endif
    return 0;
}
