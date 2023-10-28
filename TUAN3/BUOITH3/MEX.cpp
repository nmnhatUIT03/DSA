#include <iostream>
#include <vector>

using namespace std;

int findMex(const vector<int>& arr) {
    int n = arr.size();
    vector<bool> marked(n + 1, false);

    for (int num : arr) {
        if (num >= 0 && num <= n) {
            marked[num] = true;
        }
    }

    for (int i = 0; i <= n; i++) {
        if (!marked[i]) {
            return i;
        }
    }

    return n + 1;
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int mex = findMex(arr);
    cout << mex << endl;

    return 0;
}