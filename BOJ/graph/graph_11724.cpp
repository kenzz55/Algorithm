#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    vector<bool> visited(N + 1, false);

    while (M--) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;

    int cnt = 0;

    for (int i = 1; i <= N; i++) {
        if (visited[i])
            continue;

        cnt++;
        visited[i] = true;
        q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    cout << cnt;

}


