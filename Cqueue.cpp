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
        if(front == rear + 1) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if(front == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    int enQurue(int item) {
        if(isFull()) {
            cout << "Queue is Full" << endl;
            cout << endl;
        }
        else {
            if(front == -1) {
                front = 0;
            }
            rear = (rear +1) % SIZE;
            items[rear] = item;
            cout << "Inserted Item = " << item << endl;
        }
        return item;
    }

    void deQurue() {
        int item;
        if(isEmpty()) {
            cout << "Queue is Empty" << endl;
        }
        else {
            item = items[front];
            if(front >= rear) {
                front = rear = -1;
            }
            else {
                front = (front + 1) % SIZE;
            }
            cout << "Dequeue Item = " << item << endl;
        }
    }

    void Display() {
        int i;
        if(isEmpty()) {
            cout << "Queue is Empty" << endl;
        }
        else {
            cout << "Front Index => " << front << endl;
            cout << "Items -> ";
            for(i = front; i != rear; i= (i+1) % SIZE) {
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
        int n;
        cout << "1. Queue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "....";
        cin >> n;
        if(n == 1) {
            int a;
            cout << "Items : ";
            cin >> a;
            int b = q.enQurue(n);
            q.Display();
        }
        if(n == 2) {
            q.deQurue();
            q.Display();
        }
        if(n == 0) {
            break;
        }

    }

    return 0;
}