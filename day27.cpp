#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Create list
Node* create(int n) {
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

// Length
int length(Node* head) {
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

int main() {
    int n, m;
    cin >> n;
    Node* l1 = create(n);

    cin >> m;
    Node* l2 = create(m);

    int len1 = length(l1);
    int len2 = length(l2);

    // Move pointer of longer list
    Node *t1 = l1, *t2 = l2;

    if(len1 > len2) {
        for(int i = 0; i < len1 - len2; i++)
            t1 = t1->next;
    } else {
        for(int i = 0; i < len2 - len1; i++)
            t2 = t2->next;
    }

    // Find intersection
    while(t1 != NULL && t2 != NULL) {
        if(t1->data == t2->data) {
            cout << t1->data;
            return 0;
        }
        t1 = t1->next;
        t2 = t2->next;
    }

    cout << "No Intersection";
    return 0;
}