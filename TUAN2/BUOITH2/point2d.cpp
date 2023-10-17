#include <bits/stdc++.h>

using namespace std;

struct Point2D {
    int x;
    int y;
};

Point2D a[1000000];

bool cmp(const Point2D& u, const Point2D& v) {
    if (u.x < v.x) {
        return true;
    } else if (u.x == v.x) {
        if(u.y > v.y){
            return true;
        }else{
            return false;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    
    sort(a, a + n, cmp);
    
    for (int i = 0; i < n; i++) {
        cout << a[i].x << " " << a[i].y << '\n';
    }
    
    return 0;
}