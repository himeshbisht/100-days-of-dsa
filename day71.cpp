#include <iostream>
#include <vector>
using namespace std;

class HashTable {
    vector<int> table;
    int m;

public:
    HashTable(int size) {
        m = size;
        table.assign(m, -1);
    }

    int hashFunc(int key) {
        return key % m;
    }

    void insert(int key) {
        int h = hashFunc(key);
        int i = 0;

        while (i < m) {
            int idx = (h + i*i) % m;
            if (table[idx] == -1) {
                table[idx] = key;
                return;
            }
            i++;
        }
    }

    void search(int key) {
        int h = hashFunc(key);
        int i = 0;

        while (i < m) {
            int idx = (h + i*i) % m;
            if (table[idx] == key) {
                cout << "FOUND\n";
                return;
            }
            if (table[idx] == -1) break;
            i++;
        }
        cout << "NOT FOUND\n";
    }
};

int main() {
    int m, q;
    cin >> m >> q;

    HashTable ht(m);

    while (q--) {
        string op;
        int x;
        cin >> op >> x;

        if (op == "INSERT") ht.insert(x);
        else ht.search(x);
    }
}