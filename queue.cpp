#include<iostream>

using namespace std;

#define SIZE 5

class Queue {
    private:
    int items[SIZE], front, rear;

    public:

    Queue() {
        front= rear = -1;
    }

    bool isFull() {
        if(front == 0 && rear == SIZE-1) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isEmpty() {
        if(front == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    void enQurue(int item) {
        if(isFull()) {
            cout << "Queue is Full" << endl;
        }
        else {
            if(front == -1) {
                front = 0;
            }
            rear++;
            items[rear] = item;
            cout << "Inserted Item =" << item << endl;
        }
    }

    void deQurue() {
        int item;
        if(isEmpty()) {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        else {
            item = items[front];
            if(front >= rear) {
                front = rear = -1;
            }
            else {
                front++;
            }
            cout << "Dequeue Item =" << item << endl;
        }
    }

    void Display() {
        int i;
        if(isEmpty()) {
            cout << "Queue is Empty" << endl;
        }
        else {
            cout << "Front Index =>" << front << endl;
            cout << "Items -> ";
            for(i = front; i <= rear; i++) {
                cout << items[i] << " ";
            }
            cout << endl;
            cout << "Rear Index -> " << rear << endl;
        }
    }
};

int main()
{
    Queue q;

    int i;
    cout << "Enter Queue Items(Size 5)" << endl;
    for(i=0; i<5; i++) {
        int n;
        cout << "Items : ";
        cin >> n;
        q.enQurue(n);
    }

    q.Display();

    while(1)
    {
        int a;
        cout << "1. Dequeue" << endl;
        cin >> a;
        if(a == 1) {
            q.deQurue();
            q.Display();
        }
    }

    return 0;
}