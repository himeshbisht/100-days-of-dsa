#include <iostream>
using namespace std;

#define MAX 100

int heap[MAX];
int size = 0;

void insert(int x) {
    heap[size] = x;
    int i = size;
    size++;

    // Heapify up
    while(i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin() {
    if(size <= 0) return -1;
    if(size == 1) return heap[--size];

    int root = heap[0];
    heap[0] = heap[--size];

    // Heapify down
    int i = 0;
    while(true) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;
        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != i) {
            swap(heap[i], heap[smallest]);
            i = smallest;
        } else break;
    }

    return root;
}

int peek() {
    if(size == 0) return -1;
    return heap[0];
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
        else if(op == "extractMin")
            cout << extractMin() << endl;
        else if(op == "peek")
            cout << peek() << endl;
    }

    return 0;
}