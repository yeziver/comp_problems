#include <vector>
#include <iostream>
using namespace std;

void bitsEqualizer(int num) {
    string S, T;
    cin >> S >> T;
    int ans = 0;
    int onetoZero = 0;
    int zerotoOne = 0;
    int onetoOne = 0;
    int questionMarks = 0;
    vector<int> questionMarksPos;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '?') { 
            questionMarks++;
            questionMarksPos.push_back(i);
        }
        if (S[i] == '1' && T[i] == '0') {
            onetoZero++;
        }
        if (S[i] == '0' && T[i] == '1') {
            zerotoOne++;
        } 
        if (S[i] == '1' && T[i] == '1') {
            onetoOne++;
      }
    }
    if (onetoZero == zerotoOne) {
        ans += onetoZero;
        ans += questionMarks; 
    } else if (onetoZero == 0) {
        ans += zerotoOne;
        ans += questionMarks;
    } else if (onetoZero > onetoOne) {
        if (questionMarks >= onetoZero) {
            for (int i = 0; i < questionMarksPos.size(); i++) {
                if (T[questionMarksPos[i]] == '0') {
                    ans++;
                }
            }
            ans += zerotoOne;
            ans += questionMarks; 
        } else {
          cout << -1;
        } 
    } 
}

int main(void) {
    int C;
    cin >> C;
    for (int  i = 0; i < C; i++) {
        bitsEqualizer(i+1);
        cout << endl;
    }
}
