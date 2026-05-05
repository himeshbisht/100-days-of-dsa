long long merge(vector<int>& a, int l, int m, int r) {
    vector<int> temp;
    int i = l, j = m + 1;
    long long inv = 0;

    while (i <= m && j <= r) {
        if (a[i] <= a[j]) temp.push_back(a[i++]);
        else {
            temp.push_back(a[j++]);
            inv += (m - i + 1);
        }
    }

    while (i <= m) temp.push_back(a[i++]);
    while (j <= r) temp.push_back(a[j++]);

    for (int k = 0; k < temp.size(); k++)
        a[l + k] = temp[k];

    return inv;
}

long long mergeSort(vector<int>& a, int l, int r) {
    long long inv = 0;
    if (l < r) {
        int m = (l + r) / 2;
        inv += mergeSort(a, l, m);
        inv += mergeSort(a, m + 1, r);
        inv += merge(a, l, m, r);
    }
    return inv;
}