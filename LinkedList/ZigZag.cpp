#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }
    ~Node() {
        cout << "Destructor of Node" << endl;
        if (next != NULL) {
            delete next;
            next = NULL;
        }
    }
};

class List {
    Node *head;
    Node *tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }

    ~List() {
        cout << "Destructor of List" << endl;
        if (head != NULL) {
            delete head;
            head = NULL;
        }
    }

    Node *getHead() { return head; }
    void setHead(Node* h) { head = h; } // helper to update head

    void push_front(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// ---------- Helper functions outside List ----------

// reverse moved outside List
Node* reverse(Node *head) {
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *splitAtMid(Node *head) {
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev != NULL) {
        prev->next = NULL;
    }
    return slow; // right head
}

Node* zigZag(Node *head) {
    Node *rightHead = splitAtMid(head);
    Node *rightHeadRev = reverse(rightHead);

    // alternate merging
    Node *left = head;
    Node *right = rightHeadRev;
    Node *tail = right;

    while (left != NULL && right != NULL) {
        Node *nextLeft = left->next;
        Node *nextRight = right->next;

        left->next = right;
        right->next = nextLeft;

        tail = right;

        left = nextLeft;
        right = nextRight;
    }
    if (right != NULL) {
        tail->next = right;
    }
    return head; // fixed: now return Node*
}

// ---------- Main ----------
int main() {
    List ll;
    ll.push_back(4);
    ll.push_back(2);
    ll.push_back(1);
    ll.push_back(3);

    cout << "Original list: ";
    ll.printList();

    cout << "Zig-Zag: ";
    Node* newHead = zigZag(ll.getHead());
    ll.setHead(newHead); // update list head
    ll.printList();

    return 0;
}
