#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <map>

using namespace std;

int main() {
    long long t;
    cin >> t;
    
    for (long long i = 0; i < t; i++) {
        bool if_zero = false;
        long long n;
        cin >> n;
        vector<int> requirements;
        int answ = 1;
        //making requirements vector
        for (long long j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            if (temp == 0) {
                if_zero = true;
            }
            requirements.push_back(temp);
        }

        sort(requirements.begin(), requirements.end());
        for (int j = 0; j < n-1; j++) {
            if (requirements[j] < j+1 && j+1 < requirements[j+1]) {
                answ++;
            }
        }
        if (if_zero == false) {
            answ++;
        }
        cout << answ << endl;
    }
}

