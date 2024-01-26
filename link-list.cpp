#include<iostream>
using namespace std;

class Node 
{
    friend class LinkedList;
    private:
        Node()
        {
            info = 0;
            next = NULL;
        }

        int info;
        Node *next;
};

class LinkedList
{
    public:
        LinkedList(int);
        void addToFirst(Node &);
        void addToEnd(Node &);
        int length();
        void reverser();
    private:
        Node *first;
};



LinkedList::LinkedList(int n)
{
    Node *p, *q;
    p = new Node;
    first = p;

    for (int i=2; i <= n ;i++ )
    {
        q = new Node;
        p->next = q;
        p = q;
    }
}

void LinkedList::addToFirst(Node &p)
{
    Node* q; 
    q = &p;
    while(q->next != NULL)
        q = q->next;
    q->next = first;
    first = &p;
}

void LinkedList::addToEnd(Node &f2)
{
    Node *p;
    p = first;
    while (p->next != NULL)
        p=p->next;
    p->next=&f2;
}

int LinkedList::length()
{
    Node *temp = first;
    int i = 1;
    for ( ; temp->next != NULL ; i++ )
        temp = temp->next;

    return i;
}

void LinkedList::reverser()
{
    Node *temp = first;
    int thisLength = length();
    Node *arr[thisLength];
    
    for (int i=0; i < thisLength ;i++)
    {
        arr[i] = temp;
        temp->next = temp;
    }

    for (int i=thisLength-1; i >= 0 ;i--)
    {
        if (i == thisLength-1)
        {
            first = arr[i];
            continue;
        }
        else 
        {
            //edame sho bayad benevisam
        }
    }
}


int main()
{
    int n;
    cin >> n;
    LinkedList list1(n);
    LinkedList list1(2);
    return 0;
}

