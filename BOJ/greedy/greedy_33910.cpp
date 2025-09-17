#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    long long mn = A.back();
    long long ans = mn;
    for (int i = N - 2; i >= 0; --i) {
        if (A[i] > mn) A[i] = mn;
        else mn = A[i];
        ans += A[i];
    }
    cout << ans << '\n';
    return 0;


}
