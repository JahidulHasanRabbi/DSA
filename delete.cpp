#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node *next, *prev;
};


int main()
{
    struct node *ptr, *head, *tobeDelete, *one , *two, *three;

    one = new node();
    two = new node();
    three = new node();

    head = one;
    one->data = 10;
    one->next = two;
    one->prev = NULL;

    two->data = 20;
    two->prev = one;
    two->next = three;

    three->data = 30;
    three->prev = two;
    three->next = NULL;
    ptr = head;

    while(ptr != NULL)
    {
        cout << "Data " << ptr->data << "<<<<<" << ptr->next << "<<<<<<<<" << ptr->prev << endl;
        ptr= ptr->next;
    }

    two->next = NULL;
    three->prev = NULL;
    free(three);

    ptr =  head;
    cout << "three " << three->data << "<<<<<" << three->next << "<<<<<<<<" << three->prev << endl;

    while(ptr != NULL)
    {
        cout << "Data " << ptr->data << "<<<<<" << ptr->next << "<<<<<<<<" << ptr->prev << endl;
        ptr= ptr->next;
    }


}