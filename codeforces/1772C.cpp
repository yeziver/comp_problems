#include <vector>
#include <fstream>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <map>

using namespace std;

void display(vector<int> arr, int k) {
    for (int i = 0; i < k; i++) {
        if (i != k-1) {
            cout << arr[i] << " ";
        } else {
            cout << arr[i];
        }
    }
}

void solve() {
    int k, n;
    cin >> k >> n;
    
    int counter = 0;
    int counter2 = 1;
    vector<int> newarr;
    
    for (int i = 1; i <= k; i++) {
        if (counter2+counter >= n) {
            newarr.push_back(i);
        }
        newarr.push_back(counter2+counter);
        counter++;
        counter2++;
    }
    sort(newarr.begin(), newarr.end());
    display(newarr, k);

}

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
        cout << endl;
    }
}
            
