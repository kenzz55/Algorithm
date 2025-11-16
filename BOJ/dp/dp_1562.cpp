#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int fullmask = (1 << 10) - 1;

int mod = 1000000000;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int dp[101][10][1 << 10];
	for (int i = 1; i < 10; i++) {
		dp[1][i][1 << i] = 1;
	}

	for (int len = 2; len <= N; len++) {
		for (int last = 0; last < 10; last++) {
			for (int mask = 0; mask <= fullmask; mask++) {
				int nmask = mask | (1 << last);

				long long add = 0;

				if (last > 0) {
					add += dp[len - 1][last - 1][mask];
				}

				if (last < 9) {
					add += dp[len - 1][last + 1][mask];
				}

				if (add) {
					dp[len][last][nmask] = (dp[len][last][nmask] + (int)(add % mod)) % mod;
				}
			}
		}
	}

	long long ans = 0;
	for (int last = 0; last < 10; last++) {
		ans = (ans + dp[N][last][fullmask]) % mod;
	}
	cout << ans;




}