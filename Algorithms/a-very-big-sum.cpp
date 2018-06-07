// https://www.hackerrank.com/challenges/a-very-big-sum/problem

#include <bits/stdc++.h>

using namespace std;

long getSum (vector<long> numbers, int n) {
	long ans = 0;
	for (vector<long>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		ans += *it;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<long> numbers(n);
	for (int i = 0; i < n; i++) {
		long x;
		cin >> x;
		numbers[i] = x;
	}
	long ans = getSum(numbers, n);
	cout << ans << endl;
	return 0;
}
