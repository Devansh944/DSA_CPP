#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Queue
{
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = tail = NULL;
    }
    void push(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop()
    {
        If(empty()){
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    int front()
    {
        return head->data;
    }
    bool empty()
    {
        return head == NULL;
    }
}