#include <vector>
#include <fstream>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <map>

using namespace std;


void solve() {
    int w, d, h, a, b, f, g;
    cin >> w >> d >> h >> a >> b >> f >> g;
    int answ1 = 0;
    int answ2 = 0;
    int answ3 = 0;
    int answ4 = 0;

    //possibility one: front wall
    answ1 = h + g + b;
    if (a > f) {
        answ1 += a-f;
    } else {
        answ1 += f-a;
    }
    
    //possibility two: back wall
    answ2 = (d-g) + (d-b) + h;
    if (a > f) {
        answ2 += a-f;
    } else {
        answ2 += f-a;
    }

    //possibilty three: right wall
    answ3 = h + (w-f) + (w-a);
    if (g > b) {
        answ3 += g-b;
    } else {
        answ3 += b-g;
    }
    
    //possibilty four: left wall
    answ4 = h + a + f;
    if (g > b) {
        answ4 += g-b;
    } else {
        answ4 += b-g;
    }

    int min1 = min(answ1, answ2);
    int min2 = min(answ3, answ4);

    int answ = min(min1, min2);
    
    cout << answ;
}

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
        cout << endl;
    }
}
            
