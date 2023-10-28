#include <iostream>
#include <algorithm>

using namespace std;

struct Point3D {
    int x;
    int y;
    int z;
};

Point3D a[1000000];

bool cmp(const Point3D& u, const Point3D& v) {
    if (u.x < v.x) {
        return true;
    } else if (u.x == v.x) {
        if(u.y > v.y){
            return true;
        } else if (u.y == v.y){
            return u.z < v.z;
        }
    }
    return false;
}

int partition(Point3D arr[], int low, int high) {
    Point3D pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (cmp(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(Point3D arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i].x << " " << a[i].y << " " << a[i].z << "\n";
    }

    return 0;
}