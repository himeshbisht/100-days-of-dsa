#include <iostream>
using namespace std;

struct Node {
    int coeff, exp;
    Node* next;
};

int main() {
    int n;
    cin >> n;

    Node *head = NULL, *temp, *newNode;

    for(int i = 0; i < n; i++) {
        newNode = new Node();
        cin >> newNode->coeff >> newNode->exp;
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

    // Print polynomial
    temp = head;
    while(temp != NULL) {
        if(temp->exp == 0)
            cout << temp->coeff;
        else if(temp->exp == 1)
            cout << temp->coeff << "x";
        else
            cout << temp->coeff << "x^" << temp->exp;

        if(temp->next != NULL)
            cout << " + ";

        temp = temp->next;
    }

    return 0;
}