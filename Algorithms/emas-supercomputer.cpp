// https://www.hackerrank.com/challenges/two-pluses/problem

#include <bits/stdc++.h>

using namespace std;

int getAns(vector<vector<char> > grid, int n, int m) {
    vector<vector<char> > newgrid(n);
    for (int i = 0; i < n; i++) {
        vector<char> row(m);
        for (int j = 0; j < m; j++) {
            row[j] = grid[i][j];
        }
        newgrid[i] = row;
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'G') {
                result = max(result, 1);
                for (int i = 0; i < n; i++) {
                    vector<char> row(m);
                    for (int j = 0; j < m; j++) {
                        row[j] = grid[i][j];
                    }
                    newgrid[i] = row;
                }
                int size = 1;
                int x[4] = {i-1, i, i+1, i}, y[4] = {j, j+1, j, j-1};
                bool fail = false;
                do {
                    for (int k = 0; k < 3; k++) {
                        if (x[k] < 0 || x[k] > n-1 || y[k] < 0 || y[k] > n-1) {
                            fail = true;
                            break;
                        }
                        if (grid[x[k]][y[k]] == 'B') {
                            fail = true;
                            break;
                        }
                    }
                    if (!fail) {
                        size += 2;
                        // x = {x[0]-1, x[1], x[2]+1, x[3]};
                        x[0] -= 1;
                        x[2] += 1;
                        // y = {y[0], y[1]+1, y[2], y[3]-1};
                        y[1] += 1;
                        y[3] -= 1;
                    }

                } while (!fail);
                newgrid[i][j] = 'B';
                for (int k = 1; k <= size/2; k++) {
                    newgrid[i-k][j] = 'B';
                    newgrid[i][j+k] = 'B';
                    newgrid[i+k][j] = 'B';
                    newgrid[i][j-k] = 'B';
                }
                result = max(result, (2*size - 1)*getAns(newgrid, n, m));
            }
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char> > originalGrid(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<char> v(m);
        for (int j = 0; j < m; j++) {
            v[j] = s[j];
        }
        originalGrid[i] = v;
    }

    int ans = getAns(originalGrid, n, m);
    cout << ans << endl;

    return 0;
}
