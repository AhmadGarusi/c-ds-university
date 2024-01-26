#include<iostream>
using namespace std;

class Node 
{
    friend class list;
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

class list
{
    public:
        Node *first;
        list(int n)
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

        void print()
        {
            Node *p;
            p = first;
            do{
                p=p->next;
            }while(p->next!=NULL);
            while (p->prev!=NULL)
            {
                cout << p->info << endl;
                p=p->prev;
            }
        }

};
int main ()
{
    list obj(6);
    obj.print();
    return 0;

}