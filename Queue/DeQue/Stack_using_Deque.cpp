#include <iostream>
#include <queue>
#include <deque>
using namespace std;

class Stack
{
    deque<int> deq;

public:
    void push(int data)
    {
        deq.push_front(data);
    }
    void pop()
    {
        deq.pop_front();
    }
    int top()
    {
        return deq.front();
    }
    bool empty()
    {
        return deq.empty();
    }
};

int main()
{
    Stack s;
    for (int i = 0; i <= 5; i++)
    {
        s.push(i);
    }
    for (int i = 0; i <= 5; i++)
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}