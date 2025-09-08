#include <iostream>
#include <vector>
#include <climits>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<long long> p(N + 1, 0);

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        p[i + 1] = p[i] + x;
    }
    long long max = LLONG_MIN;
    for (int i = 0; i + K <= N; i++) {
        long long sum = p[i + K] - p[i];
        if (sum > max)
            max = sum;
    }
    cout << max;


}


