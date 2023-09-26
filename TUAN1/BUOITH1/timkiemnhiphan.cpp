#include  <iostream>
#include <vector>
#include <climits>
using namespace std;



int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i <= n-3; i++){
        for (int j = 0; j <= m-3; j++) {
            int tong = a[i][j] + a[i][j+1] + a[i][j+2];
            tong += a[i+1][j] + a[i+1][j+1] + a[i+1][j+2];
            tong+= a[i+2][j] + a[i+2][j+1] + a[i+2][j+2];
            ans = min(ans, tong);
        }
        
    }
    cout << ans;
    return 0;
}//Đề bài: "C:\Đề bài CTDL&GT TH\BUOI1\bai1.png"