#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node Node;

struct node {
    int value;
    Node *next;
};

Node *preNode;

void print(Node *head)
{
    Node *list;
    list = head;
    int count = 0;

    cout << "\nDisplaying LInk list" << endl;
    while(list != NULL)
    {

        cout << "Data : " << list->value << endl;
        cout << "Node Address : " << list << endl;
        cout << "Next Node Address : " << list->next << endl;
        count++;
        list = list->next;
    }

    cout << "\nTotal Node : " << count << endl;
}
Node* search(Node *head, int value)
{
    Node *list;
    int findvalue = 0, count = 0;
    list = head;
    
    while (list != NULL)
    {
        if(list->value == value) {
            findvalue = 1;
            cout << endl;
            cout << value << " Found in Node : " << count << endl;
            cout << value << " Address is " << list << endl;
            break;
        }

        else {
            count++;
            preNode = list;
            list = list->next;
        }
    }

    if(findvalue == 0) {
            cout << "Value does not Exitst" << endl;
        }
    
    return list;
    
}
Node* headinsert(Node *head, Node *nodenew)
{ 
     nodenew->next = head;
     head = nodenew;
     
     return head;
}

void insertinlist(Node *head, Node *nodenew)
{
    Node *tlist;
    int previewNode;
    cout << "Enter Previous Node value : ";
    cin >> previewNode;
    tlist = search(head, previewNode);

    if(tlist==NULL) {
        cout << "Value Does not Exitst" << endl;
    }
    else {
        if(tlist->next == NULL) {
            tlist->next = nodenew;
        }  
        else {
            nodenew->next = tlist->next;
            tlist->next = nodenew;
        }
    }    

}

Node *deletelist(Node *head, int value)
{
    Node *list, *toDelete;
    if(head == NULL) {
        cout << "UnderFlow" << endl;
    }
    else {
        toDelete = search(head, value);

        //head
        if(toDelete == head) {
            list = head;
            head = list->next;
            list->next = NULL;
            free(list);
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
    Node *list, *head, *nodenew, *tlist;
    int insertValue,  value, nodeV;

    cout << "How many Node : ";
    cin >> nodeV;
    
    head = NULL;
    
    for(int i=0; i<nodeV; i++) {
        nodenew = new Node();
        if(nodenew == NULL) {
            cout << "Mermory cannot be Allocated" << endl;
        }

        else {
            cout << "Enter Node Element : ";
            cin >> nodenew->value;
            nodenew->next = NULL;
            if(head == NULL) {
                head = nodenew;
                tlist = head;
            }
            else {
                tlist->next = nodenew;
                tlist = nodenew;
            }
        }
    }

    print(head);

    cout << "\nEnter Value to Search in List : ";
    cin >> value;
    search(head, value);

    cout << "\nInserting in Head List" << endl;
    nodenew = new Node();
    cout << "Enter Value " ;
    cin >> nodenew->value;
    nodenew->next = NULL;
    head = headinsert(head, nodenew);
    print(head);

    nodenew = new Node();
    cout <<"\nEnter Value to Insert in List : ";
    cin >> nodenew->value;
    nodenew->next = NULL;
    insertinlist(head, nodenew);
    print(head);

    cout << "Delete from LInk list" << endl;
    cout << "Enter value to Delete : " ;
    cin >> value;
    head = deletelist(head, value);
    print(head);

    return 0;
}