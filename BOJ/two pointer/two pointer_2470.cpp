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

    int N;
    cin >> N;

    vector<long long> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int left = 0;
    int right = N - 1;
    long long ans = 2000000000;
    long long ansl = 0;
    long long ansr = 0;
    while (left < right) {
        long long sum = v[left] + v[right];

        if (llabs(sum) < ans) {
            ans = llabs(sum);
            ansl = v[left];
            ansr = v[right];
        }

        if (sum < 0) {
            left++;
        }
        else if (sum > 0) {
            right--;
        }
        else {
            break;
        }
    }

    cout << ansl << " " << ansr;




    return 0;
}