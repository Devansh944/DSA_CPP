#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
    ~Node()
    {
        cout << "Destructor of Node" << endl;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

class List
{

public:
    Node *head;
    Node *tail;
    List()
    {
        head = NULL;
        tail = NULL;
    }

    ~List()
    {
        cout << "Destructor of List" << endl;
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "LinkedList is Empty";
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
};

bool isCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout << "Cycle Exist " << endl;
            return true;
        }
    }
    cout << "No Cycle found";
    return false;
};
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
};

void removeCycle(Node *head)
{
    // detect cycle
    Node *slow = head;
    Node *fast = head;
    bool isCycle = false;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout << "Cycle Exist ";
            isCycle = true;
            break;
        }
    }
    if (!isCycle)
    {
        cout << "NO cycle exist";
    }

    // step 2
    slow = head;
    if (slow == fast)
    { // Case if tail is connected to head
        while (fast->next != slow)
        {

            fast = fast->next;
        }
        fast->next = NULL;
    }

    else
    {
        Node *prev = fast;
        while (slow != fast)
        {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        // step 3 remove cycle
        prev->next = NULL;
    }
};

int main()
{
    List ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.tail->next = ll.head;

    removeCycle(ll.head);
    printList(ll.head);

    return 0;
}