#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n;
    cin >> n;

    Node *head = NULL, *temp, *newNode;

    for(int i = 0; i < n; i++) {
        newNode = new Node();
        cin >> newNode->data;

        if(head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            temp = head;
            while(temp->next != head)
                temp = temp->next;

            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Traversal
    temp = head;
    if(head != NULL) {
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while(temp != head);
    }

    return 0;
}