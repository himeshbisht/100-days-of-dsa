vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 0);

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[i]) count++;
        }
        res[i] = count;
    }
    return res;
}