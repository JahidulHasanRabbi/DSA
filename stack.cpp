#include<iostream>

using namespace std;

#define MAX 10
int size = 0;
struct stack {
    int items[MAX];
    int top;
};

typedef struct stack stack;

void createStack(stack *s)
{
    s->top = -1;
}

bool isFull(stack *s)
{
    if(s->top == MAX - 1) {
        return true;
    }
    else {
        return false;
    }
}

bool isEmpty(stack *s)
{
    if(s->top = -1) {
        return true;
    }
    else {
        return false;
    }
}

void push(stack *s, int items)
{
    if(isFull(s)) {
        cout << "Stack Is Full" << endl;
    }
    else {
        s->top++;
        s->top[s->items] = items;
    }
    size++;
}

void pop(stack *s)
{
    if(isEmpty(s)) {
        cout << "Stack is Empty" << endl;
    }
    else {
        s->top--;
    }
    size--;
}

void printStack(stack *s)
{
    cout << "Stack :";
    for(int i=0; i<size; i++) {
        cout << s->items[i] << " -> ";
    }
    cout << endl;
}

int main()
{
    stack *s = new stack();
    createStack(s);

    int n;
    cout << "Enter Stack Size MAX[10]" << endl;
    cin >> n;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        push(s, a);
    }

    printStack(s);

    int b;
    while(b != 0)
    {
        cout << "Exit (0)" << endl;
        cin >> b;
        if(b == 0) {
            exit(0);
        }
        pop(s);
        printStack(s);
    }

    printStack(s);

    return 0;
}