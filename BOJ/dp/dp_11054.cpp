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
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    vector<int> LIS(N, 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j])
                LIS[i] = max(LIS[i], LIS[j] + 1);
        }
    }

    vector<int> LDS(N, 1);
    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= i; j--) {
            if (v[j] < v[i])
                LDS[i] = max(LDS[i], LDS[j] + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, LDS[i] + LIS[i] - 1);
    }

    cout << ans;

}
