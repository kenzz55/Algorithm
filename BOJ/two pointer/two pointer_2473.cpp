#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<long long> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    sort(v.begin(), v.end());

    long long best = LLONG_MAX;
    int a = 0, b = 1, c = 2;

    for (int i = 0; i < N - 2; i++) {
        int left = i + 1;
        int right = N - 1;

        while (left < right) {
            long long sum = v[i] + v[left] + v[right];

            if (llabs(sum) < best) {
                best = llabs(sum);
                a = i; b = left; c = right;
            }

            if (sum > 0) right--;
            else left++;
        }
    }

    cout << v[a] << " " << v[b] << " " << v[c];

    
}