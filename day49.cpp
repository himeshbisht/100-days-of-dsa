#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

bool search(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

int main() {
    int n; cin >> n;
    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        root = insert(root, x);
    }

    int key; cin >> key;
    cout << (search(root, key) ? "FOUND" : "NOT FOUND");
}