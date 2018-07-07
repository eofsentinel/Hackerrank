#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        long long c3 = (n-1) / 3;
        long long c5 = (n-1) / 5;
        long long c15 = (n-1) / 15;
        long long s3 = (c3 * (2*3 + (c3-1)*3)) / 2;
        long long s5 = (c5 * (2*5 + (c5-1)*5)) / 2;
        long long s15 = (c15 * (2*15 + (c15-1)*15)) / 2;
        cout << s3 + s5 - s15 << endl;
    }
    return 0;
}
