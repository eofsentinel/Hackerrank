// https://www.hackerrank.com/challenges/queens-attack-2/problem

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int rq, cq;
    cin >> rq >> cq;
    rq -= 1;
    cq -= 1;
    vector<int> rob(k), cob(k);
    for (int i = 0; i < k; i++) {
        cin >> rob[i] >> cob[i];
        rob[i] -= 1;
        cob[i] -= 1;
    }
    int totalmoves = 0, besti, bestj;

    // 1 North
    besti = n;
    bestj = cq;
    for (int i = 0; i < k; i++) {
        if (rob[i] > rq && cob[i] == cq) {
            if (rob[i] < besti) {
                besti = rob[i];
            }
        }
    }
    totalmoves += besti - rq - 1;
    // cout << "N: " << besti - rq - 1 << endl;

    // 2 North-East
    besti = n;
    bestj = n;
    for (int i = 0; i < k; i++) {
        if (rob[i] > rq && cob[i] > cq && abs(rob[i] - cob[i]) == abs(rq - cq)) {
            if (rob[i] < besti) {
                besti = rob[i];
                bestj = cob[i];
            }
        }
    }
    totalmoves += besti - rq - 1;
    // cout << "NE: " << besti - rq - 1 << endl;

    // 3 East
    besti = rq;
    bestj = n;
    for (int i = 0; i < k; i++) {
        if (rob[i] == rq && cob[i] > cq) {
            if (cob[i] < bestj) {
                bestj = cob[i];
            }
        }
    }
    totalmoves += bestj - cq - 1;
    // cout << "E: " << bestj - cq - 1 << endl;

    // 4 South-East
    besti = -1;
    bestj = n;
    for (int i = 0; i < k; i++) {
        if (rob[i] < rq && cob[i] > cq && (rob[i] + cob[i] == rq + cq)) {
            if (cob[i] < bestj) {
                bestj = cob[i];
            }
        }
    }
    totalmoves += bestj - cq - 1;
    // cout << "SE: " << bestj - cq - 1 << endl;

    // 5 South
    besti = -1;
    bestj = cq;
    for (int i = 0; i < k; i++) {
        if (rob[i] < rq && cob[i] == cq) {
            if (rob[i] > besti) {
                besti = rob[i];
            }
        }
    }
    totalmoves += rq - besti - 1;
    // cout << "S: " << rq - besti - 1 << endl;


    // 6 South-West
    besti = -1;
    bestj = -1;
    for (int i = 0; i < k; i++) {
        if (rob[i] < rq && cob[i] < cq && abs(rob[i] - cob[i]) == abs(rq - cq)) {
            if (cob[i] > bestj) {
                bestj = cob[i];
            }
        }
    }
    totalmoves += cq - bestj - 1;
    // cout << "SW: " << cq - bestj - 1 << endl;

    // 7 West
    besti = rq;
    bestj = -1;
    for (int i = 0; i < k; i++) {
        if (rob[i] == rq && cob[i] < cq) {
            if (cob[i] > bestj) {
                bestj = cob[i];
            }
        }
    }
    totalmoves += cq - bestj - 1;
    // cout << "W: " << cq - bestj - 1 << endl;

    // 8 North-West
    besti = n;
    bestj = -1;
    for (int i = 0; i < k; i++) {
        if (rob[i] > rq && cob[i] < cq && (rob[i] + cob[i] == rq + cq)) {
            if (rob[i] < besti) {
                besti = rob[i];
            }
        }
    }
    totalmoves += besti - rq - 1;
    // cout << "NW: " << besti - rq - 1 << endl;

    cout << totalmoves << endl;
    return 0;
}
