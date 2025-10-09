#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    vector<int> dp(N, 1);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (v[j] < v[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}
