#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <climits>  
#include <cstdlib>
#include <algorithm>


using namespace std;

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long t = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (t > 0) return 1;
    if (t < 0) return -1;
    return 0;
}

bool overlap(long long a1, long long a2, long long b1, long long b2) {
    if (a1 > a2) swap(a1, a2);
    if (b1 > b2) swap(b1, b2);
    return max(a1, b1) <= min(a2, b2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x1;
    long long x2;
    long long x3;
    long long x4;
    long long y1;
    long long y2;
    long long y3;
    long long y4;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    int c1 = ccw(x1, y1, x2, y2, x3, y3);
    int c2 = ccw(x1, y1, x2, y2, x4, y4);
    int c3 = ccw(x3, y3, x4, y4, x1, y1);
    int c4 = ccw(x3, y3, x4, y4, x2, y2);

    if (c1 == 0 && c2 == 0 && c3 == 0 && c4 == 0) {
        if (overlap(x1, x2, x3, x4) && overlap(y1, y2, y3, y4))
            cout << 1;
        else
            cout << 0;
    }
    else {
        if (c1 * c2 <= 0 && c3 * c4 <= 0)
            cout << 1;
        else
            cout << 0;
    }


    return 0;
}