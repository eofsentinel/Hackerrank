// https://www.hackerrank.com/challenges/plus-minus/problem

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int pos = 0, neg = 0, zer = 0;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x > 0) pos += 1;
		else if (x < 0) neg += 1;
		else zer += 1;
	}
	cout << setprecision(6) << (double)pos / n << endl;
	cout << setprecision(6) << (double)neg / n << endl;
	cout << setprecision(6) << (double)zer / n << endl;
	return 0;
}
