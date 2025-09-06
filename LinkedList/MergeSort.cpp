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

    Node* getHead() { return head; }

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

// ⚠️ Your original merge kept: using List ans and push_back
Node *merge(Node *left, Node *right) {
    List ans;   // you used this, keeping it
    Node *i = left;
    Node *j = right;

    while (i != NULL && j != NULL) {
        if (i->data <= j->data) {
            ans.push_back(i->data);
            i = i->next;
        } else {
            ans.push_back(j->data);
            j = j->next;
        }
    }
    while (i != NULL) {
        ans.push_back(i->data);
        i = i->next;
    }
    while (j != NULL) {
        ans.push_back(j->data);
        j = j->next;
    }
    return ans.getHead();   // ✅ fixed: must return Node*, not List
}

Node *mergeSort(Node *head) {
    if (!head || !head->next) return head;

    Node *rightHead = splitAtMid(head);

    Node *leftSorted = mergeSort(head);       // left head
    Node *rightSorted = mergeSort(rightHead); // right head

    return merge(leftSorted, rightSorted);
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

    Node* sortedHead = mergeSort(ll.getHead());
    cout << "Sorted list: ";
    Node* temp = sortedHead;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";

    return 0;
}
