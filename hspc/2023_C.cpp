#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
    string secret;
    cin >> secret;
    string duplicate = secret;
    int len = duplicate.length();
    string key = "topsecret";
    string key2 = "TopSecret";
    int len2 = 9;
    sort(key2.begin(), key2.end());
    sort(key.begin(), key.end());
    for (int i = 0; i < len; i++) {
        secret[i] = tolower(secret[i]);
    }
    sort(secret.begin(), secret.end());
    if (key != secret) {
        cout << "No";
        return 0;
    }
    sort(duplicate.begin(), duplicate.end());
    int ans = 0;
    for (int i = 0; i < len2; i++) {
        bool exist = false;
        for (int j = 0; j < len; j++) {
            if (duplicate[j] == key2[i]) {
                exist = true;
            }
        }
        if (!exist) {
            ans++;
        }
    }

    cout << ans;

}
