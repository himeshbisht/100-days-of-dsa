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

int LCA(Node* root, int a, int b) {
    if (root->data > a && root->data > b)
        return LCA(root->left, a, b);
    if (root->data < a && root->data < b)
        return LCA(root->right, a, b);
    return root->data;
}

int main() {
    int n; cin >> n;
    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        root = insert(root, x);
    }

    int a, b; cin >> a >> b;
    cout << LCA(root, a, b);
}