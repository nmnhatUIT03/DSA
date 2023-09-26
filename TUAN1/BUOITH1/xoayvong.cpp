#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        b[(i + k) % n] = a[i];
    }

    for (int i = 0; i < n; i++){
        cout << b[i] << " ";
    }
    return 0;
}
//Đề bài: "C:\Đề bài CTDL&GT TH\BUOI1\bai4.png"