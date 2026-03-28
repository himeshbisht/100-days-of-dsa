#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n, key;
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

    cin >> key;

    temp = head;
    Node* prev = NULL;

    // Delete node
    while(temp != NULL) {
        if(temp->data == key) {
            if(prev == NULL)  // first node
                head = temp->next;
            else
                prev->next = temp->next;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    // Print list
    temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}