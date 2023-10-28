#include <iostream>
#include <string>
#include <vector>

using namespace std;

int partition(vector<string>& arr, int low, int high) {
    string pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
//     cout << "i = " << i << endl;
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<string>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int count(vector<string> arr, int n) {
    quickSort(arr, 0, n - 1);

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int uniqueCount = count(arr, n);
    cout << uniqueCount << endl;

    return 0;
}