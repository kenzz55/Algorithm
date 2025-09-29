#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long mul(long long x) {
    return 2 * x;
}

long long addone(long long x) {
    return x * 10 + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;

    queue<pair<long long, int>> q;
    q.push({ A,1 });
    while (!q.empty()) {
        long long x = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (x == B) {
            cout << cnt;
            return 0;
        }
        if (x < B) {
            q.push({ mul(x), cnt + 1 });
            q.push({ addone(x), cnt + 1 });
        }

    }
    cout << -1;
}
