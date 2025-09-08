#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

const int MaxN = 1005; // 문제 주어진거랑 같게 잡으면 배열크기 오프바이원 + 넉넉히잡기
int N, M, V;
vector<int> adj[MaxN]; 
bool visited[MaxN];

void dfs(int u) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

void bfs(int start) {
    fill(visited, visited + N + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> V;
    while (M--) {
        int i, j;
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    fill(visited, visited + N + 1, false);
    dfs(V);
    cout << '\n';

    bfs(V);
    cout << '\n';


}


