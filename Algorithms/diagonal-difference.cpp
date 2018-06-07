// https://www.hackerrank.com/challenges/diagonal-difference/problem

#include <bits/stdc++.h>

using namespace std;

int getResult (vector<vector<int>> arr, int n) {
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < n; i++) {
		sum1 += arr[i][i];
		sum2 += arr[i][n-1-i];
	}
	return abs(sum1 - sum2);
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> arr(n);
	for (int i = 0; i < n; i++) {
		arr[i].resize(n);
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = getResult(arr, n);
	cout << ans << endl;
	return 0;
}
