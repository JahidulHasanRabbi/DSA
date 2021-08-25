#include<iostream>

using namespace std;

struct Node *previousNode;

struct Node
{
    int value;
    struct Node* next;
};

struct Node* SearchList(struct Node *head, int SearchValue)
{
    cout << endl;

    struct Node *ptr;
    int isFound=0;
    int count = 0;
    ptr = head;
    while(ptr != NULL)
    {
        if(ptr->value == SearchValue) {
            isFound = 1;
            cout << SearchValue << " is found in Node : " << count << endl;
            cout << SearchValue << " is found in Address " << ptr << endl;
            break;
        }
        count++;
        previousNode = ptr;
        ptr = ptr->next;
    }

    if(isFound == 0) {
        cout << "Data Does not Exist" << endl;
    }

    return ptr;
}

void PrintList(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    int count = 0;

    cout << "Displaying List Information" << endl;
    while(ptr != NULL)
    {
        cout << "\nData : " << ptr->value << endl;
        cout << "Node Address : " << ptr << endl;
        cout << "Next Node address : " << ptr->next << endl;
        ptr = ptr->next;
        count++;
    }
    
    cout << "\nTotal Node is the List : " << count << endl;
}

struct Node* insertInhead(struct Node *head, struct Node *newNode)
{
    newNode->next = head;
    head = newNode;
    return head;
}
void insertList (struct Node *head, struct Node *newNode)
{
    struct Node *tptr;
    int previousNode;
    cout << "Enter Previous Node Value : ";
    cin >> previousNode;
    tptr = SearchList(head, previousNode);
    if(tptr == NULL) {
        cout << "Previous Node value does not Exixt" << endl;
    }
    else {
        newNode->next = tptr -> next;
        tptr -> next = newNode;
    }
}

struct Node* deleleFromlist(struct Node *head, int deletevalue)
{
    struct Node *ptr, *tobeDeleted;
    if(head == NULL)
    {
        cout << "UnderFlow" << endl;
    }
    else
    {
        tobeDeleted = SearchList(head, deletevalue);
        //head delete
        if(tobeDeleted == head)
        {
            ptr = head;
            head = head->next;
            ptr->next = NULL;
            free(ptr);
        }
        else {
            previousNode->next = tobeDeleted->next;
            tobeDeleted->next = NULL;
            free(tobeDeleted);
        }
    }

    return head;

}

int main()
{
    struct Node *ptr, *head, *one, *two, *three, *newNode;
    int searchValue, deleteValue;

    one = new Node();
    two = new Node();
    three = new Node();

    one -> value = 10;
    two -> value = 20;
    three ->value = 30;

    head = one;
    one->next = two;
    two->next = three;
    three->next = NULL;

    PrintList(head);

    //Searching Value in List
    cout << "\nEnter Value : ";
    cin >> searchValue;
    SearchList(head, searchValue);

    //Inset any position otherthan head
    cout << "\nInset New Value : ";
    newNode = new Node();
    cin >> newNode->value;
    newNode->next = NULL;
    insertList(head, newNode);

    //print the new list
    cout << "After inserting" << endl;
    PrintList(head);

    //insert the new value in head
    cout << "\nInset New Value : ";
    newNode = new Node();
    cin >> newNode->value;
    newNode->next = NULL;
    head = insertInhead(head, newNode);
    PrintList(head);

    //Delete from Link List
    cout << "Enter Value to Delete : ";
    cin >> deleteValue;
    head = deleleFromlist(head, deleteValue);
    PrintList(head);

    return 0;
}