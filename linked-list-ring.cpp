#include <iostream>
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
        void mergeNewList(LinkedList);
        void printAll();
    private:
        Node *first;
};


LinkedList::LinkedList(int n)
{
    Node *f, *q;
    first = new Node;
    f = first;
    cin >> first->info;

    for (int i=2; i <= n ;i++ )
    {
        q = new Node;
        first->next = q;
        first = q;
        cin >> first->info;
    }

    first->next = f;
    f = first;
}

void LinkedList::mergeNewList(LinkedList newList)
{
    Node *firstElement = first->next;
    first->next = newList.first->next;
    first = newList.first;
    first->next = firstElement;
}

void LinkedList::printAll()
{
    cout<< "printing"<<endl;
    Node *temp = first;
    do
    {
        cout << temp->info << endl;
        temp = temp->next;
    } while (temp != first);
    
    cout << "list printed."<<endl;
}

int main()
{
    int n;
    cout << "how many Nodes do you want? ";
    cin >> n;
    LinkedList l1(n);
    cout << "how many Nodes do you want in list 2?";
    cin >> n;
    LinkedList l2(n);
    l1.printAll();
    l1.mergeNewList(l2);
    l1.printAll();


    return 0;
}