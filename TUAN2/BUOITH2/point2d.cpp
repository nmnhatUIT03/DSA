#include <iostream>

using namespace std;

struct Point2D{
    int x;
    int y;
};

Point2D a[10^5];

bool cmp(Point2D u, Point2D v){
    if (u.x < v.x) return true;
    else if (u.x == v.x){
        if (u.y > v.y) return true;
        else if(u.y == v.y){
            return 
        } 
        
         return false;
    }
}


int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
    }
    sort(a + 1, a + 1 + n, cmp);
    
}