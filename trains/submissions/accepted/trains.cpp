#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Operation = n, n-k-1, 1.

// for k = 2:
// abcdefg -> badefgc, (ba) (defg) (c)
// moves c to the back, maintains the order from 3 - n, reverses from 1 - 2.
void op(vector<int>& a, vector<int>& moves, int n, int k) {

	if (k == n-1) {
		return;
	}

	moves.push_back(n);
	moves.push_back(n-k-1);
	moves.push_back(1);

	vector<int> ret(n);
	for (int i = 0; i < k; i++) {
		ret[k-i-1] = a[i]; 
	}
	for (int i = k+1; i < n; i++) {
		ret[i-1] = a[i];
	}

	ret[n-1] = a[k];

	a = std::move(ret);
}


int main () {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int count = 0;

	vector<int> moves;

	// Find the number i, and use OP to move it to the back of the array.
	for (int i = 1; i <= n ; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j] == i) op(a, moves, n, j);
		}
	}

	cout << moves.size() << endl;
	for (auto& x : moves) cout << x << " ";
	cout << endl;
}