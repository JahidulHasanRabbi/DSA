#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node Node;

struct node {
    int data;
    Node *next, *prev;
};

void printList(Node *head)
{
    Node *ptr;
    ptr = head;
    int count = 0;

    cout << "\nDisplaying Link List" << endl;

    while(ptr != NULL)
    {
        cout << "\nData : " << ptr->data << endl;
        cout << "Node Address : " << ptr << endl;
        cout << "Previous Node Address : " << ptr->prev << endl;
        cout << "Next Node Address : " << ptr->next << endl;
        count++;
        ptr = ptr->next;
    }

    cout << "\nTotal Node : " << count << endl;

}

Node* searchinList(Node *head, int searchValue)
{
    Node *ptr;
    int isFound = 0, count = 0;
    ptr = head;

    while (ptr != NULL)
    {
        if(ptr->data == searchValue) {
            cout << endl;
            cout << searchValue << " is Found" << endl;
            cout << searchValue << " is Found in Node " << count+1 << endl;
            cout << "Node Address " << ptr << endl;
            isFound = 1;
            break;
        }
        else {
            count++;
            ptr = ptr->next;
        }
    }

    if(isFound == 0) {
        cout << "Data doesnot Exist" << endl;
    }
    
    return ptr;

}

Node* insertInList(Node *head, Node *newNode)
{
    newNode->next = head;
    newNode->next ->prev = newNode;
    head = newNode;

    return head;
}

void insertInListAny(Node *head, Node *newNode)
{
    Node *tptr;
    int previousNode;
    cout << "\nEnter Previous Node : ";
    cin >> previousNode;
    tptr = searchinList(head, previousNode);

    if(tptr == NULL) {
        cout << "\nData Doesnot Exist" << endl;
    }
    
    else {
        //End
        if(tptr->next == NULL) {
            tptr->next = newNode;
            newNode->prev = tptr;
        }
        else {
            newNode->next = tptr->next;
            tptr->next = newNode;
            newNode->prev = tptr;
            newNode->next->prev = newNode;
        }
    }
}

Node* deletefromList(Node *head, int deleteValue)
{
    Node *tptr, *tobeDelete;
    tobeDelete = searchinList(head, deleteValue);
    if(tobeDelete == NULL) {
        cout << "\nData does not Exisi" << endl;
    }
    else if(tobeDelete == head) {
        //head
            tptr = tobeDelete->next;
            tptr->prev = NULL;
            head = tptr;
            tobeDelete->next = NULL;
            free(tobeDelete);
    }
    else if(tobeDelete->next != NULL) {
             //Middle
            tobeDelete->prev->next = tobeDelete->next;
            tobeDelete->next->prev = tobeDelete->prev;
            tobeDelete->next = NULL;
            tobeDelete->prev = NULL;
            free(tobeDelete);
    }
            else if(tobeDelete->next == NULL) {
                //End
            tobeDelete->prev->next=NULL;
            free(tobeDelete);
            }
        

    return head;
}

int main()
{
    Node *ptr, *head, *newNode, *tptr;
    int nodeValue, searchValue, insertValue, deleteValue;

    cout << "How many Node : ";
    cin >>  nodeValue;

    head = NULL; 

    for(int i=0; i<nodeValue; i++) {
        newNode = new Node();
        cout << "Enter Value : ";
        newNode->prev = NULL;
        newNode->next = NULL;

        if(newNode == NULL) {
            cout << "Memory Cannot be Allocated" << endl;
        }

        else {
            cin >> newNode->data;
            if(head == NULL) {
                head = newNode;
                tptr = head;
            }
            else {
                tptr->next = newNode;
                newNode->prev = tptr;
                tptr = newNode;
            }
        }
    }

    printList(head);

    //Search in List
    cout << "\nEnter Search Value : ";
    cin >> searchValue;
    searchinList(head, searchValue);

    //insert in head
    cout << "\nInsert Value in Head" << endl;
    cout << "Insert Value : ";
    newNode = new Node();
    newNode->next = NULL;
    newNode->prev = NULL;
    cin >> newNode->data;
    head = insertInList(head, newNode);
    printList(head);

    //insert in Middle and End
    cout << "\nInsert Value Anywhere" << endl;
    cout << "Insert Value : ";
    newNode = new Node();
    newNode->next = NULL;
    newNode->prev = NULL;
    cin >> newNode->data;
    insertInListAny(head, newNode);
    printList(head); 

    //Delete From LInk LIst
    cout << "\nDelete from LInk List" << endl;
    cout << "Detele Value : ";
    cin >> deleteValue;
    head = deletefromList(head, deleteValue);
    printList(head);    

    return 0;
}