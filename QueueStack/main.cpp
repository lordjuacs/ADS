#include "Stack.h"
#include "Queue.h"
#define test_stack
#define test_queue

int main() {

#ifdef test_stack
    Stack* stack = new Stack(3);
    stack->push(5);
    stack->push(10);
    stack->push(15);
    stack->push(20);
    cout << stack->pop() << endl;
    cout << stack->pop() << endl;
    cout << stack->pop() << endl;
    cout << stack->pop() << endl;
    //cout << stack->pop() << endl; // Error
    stack->display();
#endif

#ifdef test_queue

    Queue* queue = new Queue(3);
    queue->enqueue(5);
    queue->enqueue(10);
    queue->enqueue(15);
    queue->enqueue(20);
    cout << queue->dequeue() << endl;
    cout << queue->dequeue() << endl;
    cout << queue->dequeue() << endl;
    cout << queue->dequeue() << endl;
    //cout << queue->dequeue() << endl; // Error

    queue->display();
#endif

    return 0;
}
