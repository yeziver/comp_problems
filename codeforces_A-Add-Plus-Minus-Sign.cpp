#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <map>

using namespace std;

int totalSum(string a, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == '1') {
      sum++;
    }
  }
  return sum;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        string a;
        cin >> n >> a;
        int temp = totalSum(a, n);
        int counter = 0;
        if (a[0] == '1') {
            counter = 1;
        }
        //if total sum is even
        if (temp % 2 == 0) {
            //printing
            for (int j = 1; j < n; j++) {
                if (a[j] == '0') {
                    cout << "+";
                } else if (a[j] == '1' && counter % 2 == 0) {
                    cout << "+";
                    counter++;
                } else if (a[j] == '1' && counter % 2 != 0) {
                    cout << "-";
                    counter++;
                }
            }
        } else if (temp % 2 != 0) {
            //counting total num of 1s
            int ones = 0;
            for (int j = 1; j < n; j++) {
                if (a[j] == '1')
                    ones++;
            }
            for (int j = 1; j < n-1; j++) {
                if (a[j] == '0') {
                    cout << "+";
                } else if (a[j] == '1' && counter % 2 == 0) {
                    cout << "+";
                    counter++;
                } else if (a[j] == '1' && counter % 2 != 0) {
                    cout << "-";
                    counter++;
                }
            }
            cout << "+";
        }
        cout << endl;
    }
}
