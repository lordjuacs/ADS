#include "ForwardList.h"
int main() {
    ForwardList<int>* first = new ForwardList<int>;
    first->push_front(12);
    first->push_front(13);
    cout << first->back() << endl;
    first->push_back(11);
    first->display();
    first->reverse();
    first->display();
    first->pop_back();
    cout << "head:" << first->front() << "tail:" << first->back() << endl;
    first->display();
    first->pop_front();
    first->display();
    first->pop_front();
    first->pop_front();

    return 0;
}
