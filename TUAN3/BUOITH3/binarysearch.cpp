#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarysearch(vector<int> a, int x)
{
    int L = 0, R = a.size() - 1;
    while (L <= R)
    {
        int mid = (L + R) / 2;
        if (a[mid] == x)
        {
            return true;
        }
        else if (a[mid] > x)
        {
            R = mid - 1;
        }
        else
        {
            L = mid + 1;
        }
    }
    return false;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < q ; i++){
        int x;
        cin >> x;
        if (binarysearch(a, x))
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
    
    