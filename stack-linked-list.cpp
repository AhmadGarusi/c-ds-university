#include<iostream>
using namespace std;

class Node
{
    friend class Stack;
    private:
        Node *next;
        int info;
    public:
        Node()
        {
            next = NULL;
        }
};

class Stack
{
    private:
        Node *top;

    public:
        Stack(int);
        void pop(int&,int&);
        void push(int, int);
        bool empty();
        void printAll();
};


Stack::Stack(int n)
{
    if( n>0 ){
        Node *temp1, *temp2;
        temp1=new Node;
        temp1->info = 0;

        for (int i=1; i<n ;i++){
            temp2=new Node;
            temp2->info = i;
            temp2->next = temp1;
            temp1 = temp2;
        }
        top = temp1;
    }
    else {cout << "-_-"; exit;}
}

bool Stack::empty()
{
    if (top == NULL) return true;
}

void Stack::push(int n1, int n2)
{
    Node *p;
    p= new Node;
    p->info = n1;
    p->next = top;
    top = p;

    p=new Node;
    p->info = n2;
    p->next = top;
    top = p;
}

void Stack::pop(int &pop1, int &pop2)
{
    if (!empty() && top->next != NULL){
        pop1 = top->info;
        pop2 = top->next->info;

        Node *temp, *temp2;
        temp = top;
        temp2 = top->next;
        top = temp2->next;
        delete temp, temp2;
    }
    else cout << "doesn't have enough nodes!!!" << endl;
}

void Stack::printAll()
{
    Node *temp = top;

    if (top!=NULL)
    {
        do    
        {
            cout << temp->info << endl;
            temp = temp->next;
        }while ( temp != NULL );
    }    
} 

int main()
{   
    int pop1=0, pop2=0;
    Stack s1(3);
    s1.printAll();
    s1.pop(pop1, pop2);
    s1.printAll();
    s1.push(2,3);
    s1.printAll();
} 