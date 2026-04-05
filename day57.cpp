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

int preIndex = 0;

Node* buildTree(vector<int>& pre, vector<int>& in, int start, int end) {
    if (start > end) return NULL;

    Node* root = new Node(pre[preIndex++]);

    int i;
    for (i = start; i <= end; i++)
        if (in[i] == root->data) break;

    root->left = buildTree(pre, in, start, i - 1);
    root->right = buildTree(pre, in, i + 1, end);

    return root;
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    int n; cin >> n;

    vector<int> pre(n), in(n);
    for (int i = 0; i < n; i++) cin >> pre[i];
    for (int i = 0; i < n; i++) cin >> in[i];

    Node* root = buildTree(pre, in, 0, n - 1);
    postorder(root);
}