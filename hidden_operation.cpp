/*
You are given a text string that contains lowercase characters and some mathematical operations in the form of a+b, a-b, a*b or a/b. Your task is to find the results of these operations and display them. 
Each operation is separated at least by 1 character. 
Results of a operation may not exceed 18 digits.
INPUT:
aabsde3345+432deeea224-120bdd
OUTPUT:
3777 104
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

bool isOperation(char c) {
  if (c == '+' || c == '*' || c == '-' || c == '/') {
    return true;
  } else {
    return false;
  }
}

int digit(char c) {
  if (c>=48 && c<=57) {
    return c-48;
  } else {
    return -1;
  }
}

long long operation(long long n1, long long n2, char op) {
  if (op == '+') {
    return n1+n2;
  } else if (op == '-') {
    return n1-n2;
  } else if (op == '*') {
    return n1*n2;
  } else {
    return n1/n2;
  }
}

long long getNum(string num, int &pos, char &op) {
  int len = num.length();
  while (pos < len && isalpha(num[pos])) {
    pos++;
  }
  long long res = 0;
  while (pos < len && !isOperation(num[pos])) {
    if(isalpha(num[pos])) {
      break;
    }
    res = res*10 + digit(num[pos]);
    pos++;
  }
  if (pos < len && isOperation(num[pos])) {
    op = num[pos];
  }
  pos++;
  return res;
}

int main(void) {
  string num;
  cin >> num;
  char op;
  int p = 0;
  int len = num.length();
  while (p < len) {
    long long n1 = getNum(num, p, op);
    if (p >= len) {
      break;
    }
    long long n2 = getNum(num, p, op);
    cout << operation(n1, n2, op) << " ";
  }
}
