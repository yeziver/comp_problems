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
    string key = "topsecret";
    string key2 = "TopSecret";
    sort(key2.begin(), key2.end());
    sort(key.begin(), key.end());
    for (int i = 0; i < secret.size(); i++) {
        secret[i] = tolower(secret[i]);
    }
    sort(secret.begin(), secret.end());
    if (key != secret) {
        cout << "No";
        return 0;
    }
    sort(duplicate.begin(), duplicate.end());
    int ans = 0;
    for (int i = 0; i < duplicate.size(); i++) {
        bool exist = false;
        for (int j = 0; j < duplicate.size(); j++) {
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
