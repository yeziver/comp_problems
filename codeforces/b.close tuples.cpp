//the dumpy code

#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#import <string>
#include <cctype>
#include <algorithm>
using namespace std;
#define ll long long

int fact(int n) {
  if (n == 0 || n == 1)
    return 1;
  else
    return n * fact(n - 1);
}

int comb(int n, int r) {
    if (n < r) {
        return 0;
    }
  int res = fact(n) / (fact(r) * fact(n-r));
  return res;
}

void tuples() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  int num = 0;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    ll mn = a[i];
    ll mx = mn+2;
    int ind = upper_bound(a.begin(), a.end(), mx)-a.begin()-1;
    if (ind > i) {
      num += comb(ind-i, 2);
    }
  }
  cout << num;
}

int main(void) {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    tuples();
    cout << endl;
  }
}




////////////the working one
#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#import <string>
#include <cctype>
#include <algorithm>
using namespace std;
#define ll long long

ll countt(ll n) {
  ll ret = n*(n+1)/2;
  return ret;
}

void tuples() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  ll num = 0;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    ll mn = a[i];
    ll mx = mn+2;
    int ind = upper_bound(a.begin(), a.end(), mx)-a.begin()-1;
    if (ind > i) {
      num += countt(ind-i-1);
    }
  }
  cout << num;
}

int main(void) {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    tuples();
    cout << endl;
  }
}
