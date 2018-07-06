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

        vector<vector<int> > dp(n+1);
        for (int i = 0; i <= n; i++) {
            vector<int> tp(m+1);
            if (i == 0) {
                tp[0] = 0;
                for (int j = 1; j <= m; j++) {
                    tp[j] = tp[j-1] + B[j-1];
                }
            }
            else {
                tp[0] = dp[i-1][0] + A[i-1];
                for (int j = 1; j <= m; j++) {
                    tp[j] = tp[j-1] + B[j-1];
                }
            }
            dp[i] = tp;
        }

        int maxcount = INT_MIN, curcount = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
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
