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

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    Node* root = buildTree(v);

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> temp(size);

        for (int i = 0; i < size; i++) {
            Node* node = q.front(); q.pop();

            int index = leftToRight ? i : size - i - 1;
            temp[index] = node->data;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        for (int x : temp) cout << x << " ";
        leftToRight = !leftToRight;
    }
}