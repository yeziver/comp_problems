#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#import <string>
#include <cctype>
#include <algorithm>
using namespace std;
#define ll long long

void inversions() {
  int n, k;
  cin >> n >> k;
  int n1 = 1;
  vector<int> a(n+1);
  //building a array
  for (int i = 1; i <= k; i++) {
    a[i] = i;
  }
  int x = k-1;
  for (int i = k+1; i <= n; i++){
    a[i]=x;
    x--;
  }
  
  vector<int> p(k+1);
  vector<int> b;
  for (int i = n; i >= 1; i--) {
    if (p[a[i]] == 1) {
      continue;
    } else {
      b.push_back(a[i]);
      p[a[i]] = 1;
    }
  }
  reverse(b.begin(), b.end());
  
  for (int i: b) {
    cout << i << " ";
  }
}

int main(void) {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    inversions();
    cout << endl;
  }
}
