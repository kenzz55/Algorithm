#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <climits>  
#include <cstdlib>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int left = 0;
    int right = N - 1;

    long long best = LLONG_MAX;
    long long ans1 = v[0];
    long long ans2 = v[N - 1];

    while (left < right) {
        long long sum = v[left] + v[right];
        long long absSum = llabs(sum);

        if (absSum < best) {
            best = absSum;
            ans1 = v[left];
            ans2 = v[right];
        }

        if (sum > 0) {
            right--;
        }
        else {
            left++;
        }
    }

    cout << ans1 << ' ' << ans2 << '\n';
    return 0;
}