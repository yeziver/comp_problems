#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <cctype>
#include <algorithm>
using namespace std;

int findIndex(int n, vector<int> order) {
	for (int i = 0; i < order.size(); i++) {
		if (order[i] == n) {
			return i;
		} 
	}
	return 0;
}

int main(void) {
	int n, q;
	cin >> n >> q;
	vector<int> order(n);
	vector<int> censors(q);
	for (int i = 0; i < n; i++) {
		cin >> order[i];
	}
	for (int i = 0; i < q; i++) {
		cin >> censors[i];
	}
	
	for (int signal : censors) {
		if (signal == order[0]) {
			continue;
		} else {
			int index = findIndex(signal, order);
			int temp = order[index];
			order[index] = order[index-1];
			order[index-1] = temp;	
		}		
	}

	for (int i : order) {
		cout << i << " ";
	}
}
