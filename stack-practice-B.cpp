//be

#include <iostream>
using namespace std;

#define n 5

class Stack
{
    public:
        Stack();
        bool isEmpty();
        bool isFull();
        void push( int );
        int pop();
        void prints();
        void printTop();

    private:
        int top;
        int items[n];
};

Stack::Stack()
{
    top = -2;
}

bool Stack::isEmpty()
{
    if ( top == -2 ) return false;
    else return true;
}

bool Stack::isFull()
{
    if ( top == n-2 ) return false;
    else return true; 
}

void Stack::push( int x )
{
    if ( isFull() ) items[ ++top + 1 ] = x;
    else          cout << "stack is full" << endl; 
}

int Stack::pop()
{
    if ( isEmpty() ) return items[ 1+ top-- ];
    else            {cout << "stack is already empty." << endl; exit(1);}
}

void Stack::prints()
{
    if ( isEmpty() )
        for (int i=0; i <= top+1 ;i++ )
            cout << items[i];
}

void Stack::printTop()
{
    cout << items[top+1];
}


int main()
{
    Stack stack;
    for (int i=1; i <= 5 ;i++)
        stack.push(i);
    stack.prints();
    cout << stack.pop();
    stack.prints();
    stack.printTop();
    return 0;
}