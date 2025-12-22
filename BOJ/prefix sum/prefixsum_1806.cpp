#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <climits>  
#include <cstdlib>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int left = 0;
    int sum = 0;
    int ans = N;
    int tempsum = 0;
    for (int right = 0; right < N; right++) {
        sum += v[right];
        tempsum += v[right];
        while (sum >= M) {
            sum -= v[left];
            int a = right - left + 1;
            left++;
            ans = min(ans, a);
        }
    }

    if (tempsum < M) {
        cout << 0;
    }
    else {
        cout << ans;
    }



    return 0;
}