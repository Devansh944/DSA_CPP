#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int capacity;
    int currSize;
    int f, r;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0;
        f = r = -1;
    }

    void push(int data)
    {
        if (currSize == capacity)
        {
            cout << "Queue full!\n";
            return;
        }
        if (f == -1)
            f = 0; // first element
        r = (r + 1) % capacity;
        arr[r] = data;
        currSize++;
    }

    void pop()
    {
        if (currSize == 0)
        {
            cout << "Queue empty!\n";
            return;
        }
        if (f == r)
        {
            f = r = -1; // queue becomes empty
        }
        else
        {
            f = (f + 1) % capacity;
        }
        currSize--;
    }

    int front()
    {
        if (f == -1)
        {
            cout << "Queue empty!\n";
            return -1;
        }
        return arr[f];
    }

    bool empty()
    {
        return currSize == 0;
    }
};

int main()
{
    Queue q(4);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5); // will print "Queue full!"

    cout << q.front() << endl; // should print 1

    q.pop();
    cout << q.front() << endl; // should print 2

    return 0;
}
