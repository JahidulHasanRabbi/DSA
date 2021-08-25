#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node Node;

struct node {
    int value;
    Node *next;
};

Node *preNode;

void printList(Node *head)
{
    Node *ptr;
    ptr = head;
    int count = 0;

    cout << "\nDisplaying LInk list" << endl;
    while(ptr != NULL)
    {

        cout << "Data : " << ptr->value << endl;
        cout << "Node Address : " << ptr << endl;
        cout << "Next Node Address : " << ptr->next << endl;
        count++;
        ptr = ptr->next;
    }

    cout << "\nTotal Node : " << count << endl;
}
Node* searchList(Node *head, int searchValue)
{
    Node *ptr;
    int isFound = 0, count = 0;
    ptr = head;
    
    while (ptr != NULL)
    {
        if(ptr->value == searchValue) {
            isFound = 1;
            cout << endl;
            cout << searchValue << " Found in Node : " << count << endl;
            cout << searchValue << " Address is " << ptr << endl;
            break;
        }

        else {
            count++;
            preNode = ptr;
            ptr = ptr->next;
        }
    }

    if(isFound == 0) {
            cout << "Value does not Exitst" << endl;
        }
    
    return ptr;
    
}
Node* insertHead(Node *head, Node *newNode)
{ 
     newNode->next = head;
     head = newNode;
     
     return head;
}

void insertList(Node *head, Node *newNode)
{
    Node *tptr;
    int previewNode;
    cout << "Enter Previous Node value : ";
    cin >> previewNode;
    tptr = searchList(head, previewNode);

    if(tptr==NULL) {
        cout << "Value Does not Exitst" << endl;
    }
    else {
        if(tptr->next == NULL) {
            tptr->next = newNode;
        }  
        else {
            newNode->next = tptr->next;
            tptr->next = newNode;
        }
    }    

}

Node *deleteFromlist(Node *head, int deleteValue)
{
    Node *ptr, *toDelete;
    if(head == NULL) {
        cout << "UnderFlow" << endl;
    }
    else {
        toDelete = searchList(head, deleteValue);

        //head
        if(toDelete == head) {
            ptr = head;
            head = ptr->next;
            ptr->next = NULL;
            free(ptr);
        }

        else {
            //End
            if(toDelete->next == NULL)  {
                preNode->next == NULL;
                free(toDelete);
            }
            //Middle
            else {
                preNode->next = toDelete->next;
                toDelete->next = NULL;
                free(toDelete);
            }
        }
    }

    return head;

}

int main()
{
    Node *ptr, *head, *newNode, *tptr;
    int insertValue, SearchValue, deleteValue, nodeV;

    cout << "How many Node : ";
    cin >> nodeV;
    
    head = NULL;
    
    for(int i=0; i<nodeV; i++) {
        newNode = new Node();
        if(newNode == NULL) {
            cout << "Mermory cannot be Allocated" << endl;
        }

        else {
            cout << "Enter Node Element : ";
            cin >> newNode->value;
            newNode->next = NULL;
            if(head == NULL) {
                head = newNode;
                tptr = head;
            }
            else {
                tptr->next = newNode;
                tptr = newNode;
            }
        }
    }

    printList(head);

    cout << "\nEnter Value to Search in List : ";
    cin >> SearchValue;
    searchList(head, SearchValue);

    cout << "\nInserting in Head List" << endl;
    newNode = new Node();
    cout << "Enter Value " ;
    cin >> newNode->value;
    newNode->next = NULL;
    head = insertHead(head, newNode);
    printList(head);

    newNode = new Node();
    cout <<"\nEnter Value to Insert in List : ";
    cin >> newNode->value;
    newNode->next = NULL;
    insertList(head, newNode);
    printList(head);

    cout << "Delete from LInk list" << endl;
    cout << "Enter value to Delete : " ;
    cin >> deleteValue;
    head = deleteFromlist(head, deleteValue);
    printList(head);

    return 0;
}