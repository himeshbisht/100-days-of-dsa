#include <iostream>
using namespace std;

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x) {
    pq[size++] = x;
}

int getMinIndex() {
    if(size == 0) return -1;

    int minIdx = 0;
    for(int i = 1; i < size; i++) {
        if(pq[i] < pq[minIdx])
            minIdx = i;
    }
    return minIdx;
}

void deleteMin() {
    int idx = getMinIndex();
    if(idx == -1) {
        cout << -1 << endl;
        return;
    }

    cout << pq[idx] << endl;

    pq[idx] = pq[size - 1];
    size--;
}

void peek() {
    int idx = getMinIndex();
    if(idx == -1)
        cout << -1 << endl;
    else
        cout << pq[idx] << endl;
}

int main() {
    int n;
    cin >> n;

    while(n--) {
        string op;
        cin >> op;

        if(op == "insert") {
            int x;
            cin >> x;
            insert(x);
        }
        else if(op == "delete")
            deleteMin();
        else if(op == "peek")
            peek();
    }

    return 0;
}