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

Node* buildTree(vector<int> &v) {
    if (v[0] == -1) return NULL;

    Node* root = new Node(v[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < v.size()) {
        Node* curr = q.front(); q.pop();

        if (v[i] != -1) {
            curr->left = new Node(v[i]);
            q.push(curr->left);
        }
        i++;

        if (i < v.size() && v[i] != -1) {
            curr->right = new Node(v[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

bool isMirror(Node* a, Node* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;

    return (a->data == b->data) &&
           isMirror(a->left, b->right) &&
           isMirror(a->right, b->left);
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    Node* root = buildTree(v);

    cout << (isMirror(root, root) ? "YES" : "NO");
}