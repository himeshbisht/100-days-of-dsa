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

    map<int, vector<int>> m;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front(); q.pop();
        Node* node = p.first;
        int hd = p.second;

        m[hd].push_back(node->data);

        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    for (auto x : m) {
        for (int val : x.second)
            cout << val << " ";
        cout << endl;
    }
}