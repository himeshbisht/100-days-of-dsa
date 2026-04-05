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

// Build tree from inorder & postorder
Node* buildTree(vector<int>& inorder, vector<int>& postorder, int start, int end) {
    if (start > end) return NULL;

    // Pick current root from postorder
    Node* root = new Node(postorder[postIndex--]);

    // Find root in inorder
    int i;
    for (i = start; i <= end; i++) {
        if (inorder[i] == root->data)
            break;
    }

    // IMPORTANT: build right first (postorder rule)
    root->right = buildTree(inorder, postorder, i + 1, end);
    root->left  = buildTree(inorder, postorder, start, i - 1);

    return root;
}

// Preorder traversal
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    cin >> n;

    vector<int> inorder(n), postorder(n);

    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    for (int i = 0; i < n; i++)
        cin >> postorder[i];

    postIndex = n - 1;

    Node* root = buildTree(inorder, postorder, 0, n - 1);

    preorder(root);
}