// https://www.hackerrank.com/challenges/append-and-delete/problem

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int k;
    cin >> k;
    bool ans = false;
    int index = -1;
    for (int i = 0; i < s1.size() && i < s2.size(); i++) {
        if (s1[i] == s2[i]) {
            index = i;
        }
        else {
            break;
        }
    }
    if (index == -1) {
        if (s1.size() + s2.size() <= k) {
            ans = true;
        }
    }
    else {
        int del = s2.size() - index - 1;
        int add = s1.size() - index - 1;
        int tobe = del + add;
        if (tobe > k) {
            ans = false;
        }
        else if (tobe == k || (k - tobe)%2 == 0 || (k - tobe >= 2*s2.size())) {
            ans = true;
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}
