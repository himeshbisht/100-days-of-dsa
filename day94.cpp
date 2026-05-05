void countingSort(vector<int>& a) {
    int maxVal = *max_element(a.begin(), a.end());
    vector<int> count(maxVal + 1, 0), output(a.size());

    for (int x : a) count[x]++;

    for (int i = 1; i <= maxVal; i++)
        count[i] += count[i - 1];

    for (int i = a.size() - 1; i >= 0; i--) {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    a = output;
}