#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    if (N >= K) {
        cout << (N - K) << '\n';
        return 0;
    }

    const int Max = 100000;
    vector<int> dist(Max + 1, -1);
    queue<int> q;

    dist[N] = 0;
    q.push(N);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int x[3] = { u - 1, u + 1, 2 * u };
        for (int a : x) {
            if (a < 0 || a > Max)
                continue;
            if (dist[a] != -1)
                continue;
            dist[a] = dist[u] + 1;
            if (a == K) {
                cout << dist[a];
                return 0;
            }
            q.push(a);
        }

    }



}
