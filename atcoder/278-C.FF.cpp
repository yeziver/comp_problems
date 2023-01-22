#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

int main(void) {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> follows;
    vector<vector<int>> data;

    for (int i = 0; i < q; i++) {  //creates the matrix of given input
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> urmom = {a, b, c};
        data.push_back(urmom);
    }

    for (int i = 0; i < q; i++) {
            int t, a, b;
            t = data[i][0];
            a = data[i][1];
            b = data[i][2];
            vector<int> vals = {a, b};
            if (t == 1) {
                bool isPresent = std::find(follows.begin(), follows.end(), vals) != follows.end();
                if (!isPresent) {
                    follows.push_back(vals);
                }
            } 
            if (t == 2) {
                bool isPresent = std::find(follows.begin(), follows.end(), vals) != follows.end();
                if (isPresent) {
                    auto ind = find(follows.begin(), follows.end(), vals);
                    follows.erase(ind);
                }
            }
            if (t == 3) {
                vector<int> rev = {b, a};
                bool isPresent = std::find(follows.begin(), follows.end(), vals) != follows.end();
                bool isPresent2 = std::find(follows.begin(), follows.end(), rev) != follows.end();
                if (isPresent && isPresent2) { 
                    cout << "Yes" << "\n";
                } else {
                    cout << "No" << "\n";
                }
            }
    }
}

