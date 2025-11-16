#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    vector<int> cnt(N + 1, 0);

    while (M--) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        cnt[B]++;
    }

    vector<int> order;
    order.reserve(N);

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= N; ++i) {
        if (cnt[i] == 0)
            pq.push(i);
    }

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            if (--cnt[v] == 0)
                pq.push(v);
        }
    }

    for (int i : order)
        cout << i << ' ';
}