#include <iostream>

using namespace std;

int Biendoi(int x){
    int u;
    int x4 = x %10;
    int x3 = (x / 10) % 10;
    int x2 = (x / 100) % 10;
    int x1 = x/1000;
    int u1 = x1 + x2;
    int u2 = x3 + x4;
    if (u1 < u2){
        swap(u1,u2);
    }
    else if(u2 < 10){
        u = u1 * 10 + u2;
    }
    else{
        u = u * 100 + u2;
    }
}
int main(){
    int x, u;
    for (x = 1000; x <= 9999;){
        cin >> x;    
        u = Biendoi(x);
        if (u == x){
            cout << x << endl;
            return 0;
        }
    }        

    
    

    return 0;
}


