void bucketSort(float arr[], int n) {
    vector<float> buckets[n];

    for (int i = 0; i < n; i++) {
        int idx = n * arr[i];
        buckets[idx].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
        sort(buckets[i].begin(), buckets[i].end());

    int k = 0;
    for (int i = 0; i < n; i++)
        for (float x : buckets[i])
            arr[k++] = x;
}