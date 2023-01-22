#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string trophies;
    cin >> trophies;
    
    //case 1: if we see R L
    for (int i = 0; i < n-1; i++) {
        if (trophies[i] == 'R' && trophies[i+1] == 'L') {
            cout << '0' << endl;
            return;
        }
    }
    
    bool boolr = false;
    bool booll = false;
    //case 2: if it's only Ls or Rs
    for (int i = 0; i < n; i++) {
        if (trophies[i] == 'R') {
            boolr = true;
        }
        if (trophies[i] == 'L') {
            booll = true;
        }
    }
    if (!boolr || !booll) {
        cout << "-1" << endl;
        return;
    }
    
    //case 3: when you need to swap
    for (int i = 0; i < n-1; i++) {
        if (trophies[i] == 'L' && trophies[i+1] == 'R') {
            cout << i+1 << endl;
            return;
        }
    }
}

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}
            
