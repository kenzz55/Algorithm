#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> v(n);
    vector<int> dp;
    for (int i = 0; i < n; i++) {
        v[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        dp.push_back(v[n - 1][i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[j] = v[i][j] + max(dp[j], dp[j + 1]);
        }
    }

    cout << dp[0];


}
