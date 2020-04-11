void backet_sort(int arr[], int n) {
    vector<float>temp[100];
    for (int i = 0; i < n; ++i) {
        int pos = arr[i] * n;
        temp[pos].push_back(arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        sort(temp[i].begin(), temp[i].end());
    }
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < temp[i].size(); ++j) {
            arr[index++] = temp[i][j];
        }
    }
}
