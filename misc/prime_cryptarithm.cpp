//under review
/*
ID: harry47341
PROG: crypt1
LANG: C++
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> digits;
int a, b, c, d, e, abc, de;

bool checkDigit(int n) {
    int count1 = 1;
    while (true) {
        if (count1 > n) break;
        else {
            count1 = count1 * 10;
            int digit = n%count1 / (count1 / 10);
            if (!count(digits.begin(), digits.end(), digit) ){
                return false;
            }
            n = n - n%count1;

        }

    }
    return true;
}
bool check() {
    int n = abc*e;
    int n1 = abc*d;
    if (n > 999 || n < 100)return false;
    if (n1 > 999 || n1 < 100)return false;

    if ((n1 * 10 + n) > 9999 || (n1 * 10 + n) < 1000)return false;
    if (checkDigit(n) && checkDigit(n1) && checkDigit(n1 * 10 + n)) {
        return true;
    }
    return false;
}

int main() {
    int count = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int f;
        cin >> f;
        digits.push_back(f);
    }

    for (int i = 0; i < n; i++) {
        a = digits[i];
        for (int i1 = 0; i1 < n; i1++) {
            b = digits[i1];
            for (int i2 = 0; i2 < n; i2++) {
                c = digits[i2];
                for (int i3 = 0; i3 < n; i3++) {
                    d = digits[i3];
                    for (int i4 = 0; i4 < n; i4++) {
                        e = digits[i4];
                        abc = a * 100 + b * 10 + c;
                        de = d * 10 + e;
                        if (check()) {
                            count++;
                        }
                    }
                }
            }
        }

    }
    cout << count << endl;
    return 0;
}


