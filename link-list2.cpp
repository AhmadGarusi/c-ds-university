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
            prev = NULL;
        }

        int info;
        Node *prev;
        Node *next;
};

class LinkedList
{
    public:
        LinkedList(int);
        void addToFirst(LinkedList &);
        void addToEnd(LinkedList &);
        void deleteFromFirst(int);
        int length();
        void printAll();
    private:
        Node *first;
};



LinkedList::LinkedList(int n)
{
    Node *p, *q;
    p = new Node;
    p->info = 1;
    first = p;

    for (int i=2; i <= n ;i++ )
    {
        q = new Node;
        p->next = q;
        q->prev = p;
        q->info = i;
        p = q;
    }
}

void LinkedList::addToFirst(LinkedList &p)
{
    Node* q; 
    q = p.first;
    while(q->next != NULL)
        q = q->next;
    q->next = first;
    first->prev = q;
    first = q;
}

void LinkedList::addToEnd(LinkedList &f2)
{
    Node *p;
    p = first;
    while (p->next != NULL)
        p=p->next;
    p->next=f2.first;
    p->next->prev = p;
}

void LinkedList::deleteFromFirst(int n)
{
    if (length() <= n) cout << "Error input invalid"; return;

    for (int i=0; i<n ;i++){
        first->next = first;
        delete first->prev;
    }
    first->prev = NULL;
}

int LinkedList::length()
{
    Node *temp = first;
    int i = 1;
    for ( ; temp->next != NULL ; i++ )
        temp = temp->next;

    return i;
}

void LinkedList::printAll()
{
    Node *p;
    p = first;
    do
    {
        cout << p->info << endl;
        p = p->next;
    } while (p->next != NULL);
    cout << "......................................................................." << endl;
}

int main()
{
    LinkedList list0(4);
    LinkedList list1(3);
    LinkedList list2(2);
    list0.printAll();
    list0.addToFirst(list1);
    list0.printAll();
    list0.addToEnd(list2);
    list0.printAll();
    list0.deleteFromFirst(2);
    list0.printAll();
    cout << list0.length();
    return 0;
}