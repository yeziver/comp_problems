#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#import <string>
#include <cctype>
#include <algorithm>
using namespace std;
#define ll long long

int main(void) {
  int n;
  cin >> n;
  string necklace;
  cin >> necklace;
  if (necklace.find('b') == string::npos || necklace.find('r') == string::npos) {
    cout << n;
    return 0;
  }
  necklace = necklace + necklace;
  int res = 0;
  for (int i = 1; i < necklace.size(); i++) {
    if (necklace[i-1] != necklace[i]) {
      int total = 0;
      char c = 'r';
      if ((necklace[i-1] == 'r' || necklace[i-1] == 'w') && necklace[i] == 'b') {
        c = 'b';
      }
      int j = i - 1;
      while (j >= 0 && necklace[j] != c) {
        total++;
        j--;
      }
      if (c == 'r') {
        c = 'b';
      } else {
        c = 'r';
      }
      j = i;
      while (j < necklace.size() && necklace[j] != c) {
        total++;
        j++;
      }
      res = max(res, total);
    }
  }
  cout << res;
}
