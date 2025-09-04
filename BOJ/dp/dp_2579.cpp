#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> a(N + 1, 0);     // 점수 배열
    for (int i = 1; i <= N; i++) cin >> a[i];

    if (N == 1) { cout << a[1] << '\n'; return 0; }
    if (N == 2) { cout << a[1] + a[2] << '\n'; return 0; }

    vector<int> dp(N + 1, 0);    // DP 배열
    dp[1] = a[1];
    dp[2] = a[1] + a[2];
    dp[3] = max(a[1], a[2]) + a[3];

    for (int i = 4; i <= N; i++) {
        dp[i] = max(dp[i - 2], dp[i - 3] + a[i - 1]) + a[i];
    }

    cout << dp[N] << '\n';
    return 0;
}
