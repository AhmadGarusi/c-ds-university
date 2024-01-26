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
    top = -1;
}

bool Stack::isEmpty()
{
    if ( top == -1 ) return false;
    else return true;
}

bool Stack::isFull()
{
    if ( top == n-1 ) return false;
    else return true; 
}

void Stack::push( int x )
{
    if ( isFull() ) items[ ++top ] = x;
    else          cout << "stack is full" << endl; 
}

int Stack::pop()
{
    if ( isEmpty() ) return items[ top-- ];
    else            {cout << "stack is already empty." << endl; exit(1);}
}

void Stack::prints()
{
    if ( isEmpty() )
        for (int i=0; i <= top ;i++ )
            cout << items[i];
}

void Stack::printTop()
{
    cout << items[top];
}


int main()
{
    Stack stack;
    stack.push(9);
    stack.prints();   

    return 0;
}