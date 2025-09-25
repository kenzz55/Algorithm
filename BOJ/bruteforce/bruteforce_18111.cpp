#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, B;
    cin >> N >> M >> B;

    int Max = 0;
    int Min = 0;
    vector<vector<int>> mine(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mine[i][j];
            Max = max(mine[i][j], Max);
            Min = min(mine[i][j], Min);
        }
    }

    long long bestTime = LLONG_MAX;
    int bestH = -1;

    for (int h = 0; h <= 256; h++) {

        int rem = 0;
        int add = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int x = mine[i][j];
                if (x > h)
                    rem += x - h;
                else if (x < h)
                    add += h - x;
            }
        }

        if (B + rem < add)
            continue;

        long long t = 2 * rem + add;
        if (t < bestTime || (t == bestTime && h > bestH)) {
            bestTime = t;
            bestH = h;
        }

    }

    cout << bestTime << ' ' << bestH;
}
