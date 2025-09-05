#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;

    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    vector<bool> visitied(N + 1, false);
    queue<int> q;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }

    visitied[1] = true;
    q.push(1);
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visitied[v]) {
                visitied[v] = true;
                q.push(v);
                if (v != 1)
                    cnt++;
            }
        }
    }

    cout << cnt;
}

