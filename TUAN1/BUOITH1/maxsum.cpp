#include <iostream>
#include <vector>
using namespace std;

int main() {
 int n;
 cin >> n;

 vector<int> a(n + 1);
 for (int i = 1; i <= n; ++i) {
  cin >> a[i];
 }

 int s1 = 0;
 for (int i = 1; i <= n; i++) {
  if (i % 2 == 1) {
   s1 += a[i];
  }
  else {
   s1 -= a[i];
  }
 }

 int id1 = 1;
 int id2 = 2;

 for (int i = 1; i <= n; i += 2) {
  if (a[i] < a[id1]) {
   id1 = i;
  }
 }

 for (int i = 2; i <= n; i += 2) {
  if (a[i] > a[id2]) {
   id2 = i;
  }
 }

 swap(a[id1], a[id2]);

 int s2 = 0;
 for (int i = 1; i <= n; i++) {
  if (i % 2 == 1) {
   s2 += a[i];
  }
  else {
   s2 -= a[i];
  }
 }

 cout << max(s1, s2);

 return 0;
}//Đề bài: "C:\Đề bài CTDL&GT TH\BUOI1\bai3.png"