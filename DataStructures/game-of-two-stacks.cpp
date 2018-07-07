// https://www.hackerrank.com/challenges/game-of-two-stacks/problem

#include <bits/stdc++.h>

using namespace std;

int main() {
    int g;
    cin >> g;
    while (g--) {
        int n, m, x;
        cin >> n >> m >> x;
        vector<int> A(n), B(m);
        for (int i = 0; i < n; i++) {
            int z;
            cin >> z;
            A.at(i) = z;
        }
        for (int i = 0; i < m; i++) {
            int z;
            cin >> z;
            B.at(i) = z;
        }

        int n1 = n, m1 = m, temp = 0;
        for (int i = 0; i < n; i++) {
            temp += A[i];
            if (temp > x) {
                n1 = i + 1;
                break;
            }
        }
        temp = 0;
        for (int j = 0; j < m; j++) {
            temp += B[j];
            if (temp > x) {
                m1 = j + 1;
                break;
            }
        }

        vector<vector<int> > dp(n1+1);
        for (int i = 0; i <= n1; i++) {
            vector<int> tp(m1+1);
            if (i == 0) {
                tp[0] = 0;
                for (int j = 1; j <= m1; j++) {
                    tp[j] = tp[j-1] + B[j-1];
                }
            }
            else {
                tp[0] = dp[i-1][0] + A[i-1];
                for (int j = 1; j <= m1; j++) {
                    tp[j] = tp[j-1] + B[j-1];
                }
            }
            dp[i] = tp;
        }

        int maxcount = INT_MIN, curcount = 0;
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= m1; j++) {
                if (dp[i][j] <= x) {
                    curcount = i + j;
                    if (curcount > maxcount) {
                        maxcount = curcount;
                    }
                }
            }
        }
        cout << maxcount << endl;
    }
    return 0;
}
