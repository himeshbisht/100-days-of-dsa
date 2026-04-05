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

int postIndex;

Node* buildTree(vector<int>& in, vector<int>& post, int start, int end) {
    if (start > end) return NULL;

    Node* root = new Node(post[postIndex--]);

    int i;
    for (i = start; i <= end; i++)
        if (in[i] == root->data) break;

    root->right = buildTree(in, post, i + 1, end);
    root->left = buildTree(in, post, start, i - 1);

    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n; cin >> n;

    vector<int> in(n), post(n);
    for (int i = 0; i < n; i++) cin >> in[i];
    for (int i = 0; i < n; i++) cin >> post[i];

    postIndex = n - 1;

    Node* root = buildTree(in, post, 0, n - 1);
    preorder(root);
}