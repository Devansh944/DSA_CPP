#include <iostream>
using namespace std;

template <class T>
class Node
{
    T data;
    Node<T> *next;

public:
    Node(T val)
    {
        data = val;
        next = NULL;
    }

    // Make Stack class a friend so it can access private members
    template <class U>
    friend class Stack;
};

template <class T>
class Stack
{
    Node<T> *head;

public:
    Stack()
    {
        head = NULL;
    }

    void push(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop()
    {
        if (head == NULL)
            return;

        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }

    T top()
    {
        if (head == NULL)
            throw runtime_error("Stack is empty!");
        return head->data;
    }

    bool isEmpty()
    {
        return head == NULL;
    }
};

int main()
{
    Stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    while (!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
