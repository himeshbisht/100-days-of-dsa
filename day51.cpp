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

Node* LCA(Node* root, int a, int b) {
    if (!root) return NULL;
    if (root->data == a || root->data == b)
        return root;

    Node* left = LCA(root->left, a, b);
    Node* right = LCA(root->right, a, b);

    if (left && right) return root;
    return left ? left : right;
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int a, b; cin >> a >> b;

    Node* root = buildTree(v);
    Node* ans = LCA(root, a, b);

    if (ans) cout << ans->data;
}