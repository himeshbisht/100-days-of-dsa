#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createList(int n) {
    Node *head = NULL, *temp, *newNode;

    for(int i = 0; i < n; i++) {
        newNode = new Node();
        cin >> newNode->data;
        newNode->next = NULL;

        if(head == NULL)
            head = newNode;
        else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

Node* merge(Node* l1, Node* l2) {
    Node *result = NULL, *temp = NULL;

    while(l1 != NULL && l2 != NULL) {
        Node* newNode = new Node();

        if(l1->data < l2->data) {
            newNode->data = l1->data;
            l1 = l1->next;
        } else {
            newNode->data = l2->data;
            l2 = l2->next;
        }
        newNode->next = NULL;

        if(result == NULL) {
            result = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Remaining nodes
    while(l1 != NULL) {
        Node* newNode = new Node();
        newNode->data = l1->data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
        l1 = l1->next;
    }

    while(l2 != NULL) {
        Node* newNode = new Node();
        newNode->data = l2->data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
        l2 = l2->next;
    }

    return result;
}

int main() {
    int n, m;
    cin >> n;
    Node* l1 = createList(n);

    cin >> m;
    Node* l2 = createList(m);

    Node* res = merge(l1, l2);

    while(res != NULL) {
        cout << res->data << " ";
        res = res->next;
    }

    return 0;
}