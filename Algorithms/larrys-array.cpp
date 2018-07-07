// https://www.hackerrank.com/challenges/larrys-array/problem

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int steps = 1;
        for (int i = 1; i <= n; i++) {
            int curindex = -1;
            for (int j = 0; j < n; j++) {
                if (A[j] == i) {
                    curindex = j;
                    break;
                }
            }
            for (int j = curindex; j >= i; j--) {
                int temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                steps += 1;
            }
        }
        if (steps % 2 == 1) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
