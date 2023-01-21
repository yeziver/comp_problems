

#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <map>

using namespace std;

int main(void) {
        int t;
        cin >> t;
        for (int i = 0; i < t; i++) {
                int n;
                cin >> n;
                long long arr[n];
                long long ans = 0;
                //creates array of n
                for (int j = 0; j < n; j++) {
                        cin >> arr[j];
                }
            //checks for parity between adjacent elements
            for (int j = 0; j < n-1; j++) {
                    if ((arr[j] % 2 && arr[j+1] % 2) || (arr[j] % 2 == 0 && arr[j+1] % 2 == 0)) {
                            ans++;
                    }
            }
            cout << ans << endl;
    }
}
