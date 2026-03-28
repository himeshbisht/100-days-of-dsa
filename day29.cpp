#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n, k;
    cin >> n;

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

    cin >> k;

    // Count nodes
    int count = 0;
    temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    k = k % count;

    if(k == 0) {
        temp = head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        return 0;
    }

    // Make circular
    temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = head;

    // Move to new head
    int steps = count - k;
    temp = head;
    for(int i = 1; i < steps; i++)
        temp = temp->next;

    Node* newHead = temp->next;
    temp->next = NULL;

    // Print
    temp = newHead;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}