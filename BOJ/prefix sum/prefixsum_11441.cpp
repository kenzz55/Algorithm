#include <iostream>
#include <vector>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> p(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        p[i] = p[i - 1] + x;
    }

    int M;
    cin >> M;
    while (M--) {
        int i, j;
        cin >> i >> j;
        cout << p[j] - p[i - 1] << '\n';
    }


}


