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

    vector<string> g(N);
    for (int i = 0; i < N; i++) {
        cin >> g[i];
    }
    vector<vector<int>> adj(N, vector<int>(M, 0));
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    adj[0][0] = 1;


    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];



            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (g[nx][ny] == '0')
                continue;
            if (adj[nx][ny] != 0)
                continue;

            adj[nx][ny] = adj[x][y] + 1;

            q.push({ nx, ny });
        }


    }
    cout << adj[N - 1][M - 1];

}


