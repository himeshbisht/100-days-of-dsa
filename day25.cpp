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

    int count = 0;
    temp = head;

    while(temp != NULL) {
        if(temp->data == key)
            count++;
        temp = temp->next;
    }

    cout << count;

    return 0;
}