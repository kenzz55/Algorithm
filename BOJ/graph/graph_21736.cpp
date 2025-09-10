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

    vector<vector<char>> adj(N, vector<char>(M));
    pair<int, int> st;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> adj[i][j];

            if (adj[i][j] == 'I')
                st = { i,j };
        }
    }

    int dy[4] = { 0,0,1,-1 };
    int dx[4] = { 1,-1,0,0 };
    queue < pair<int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    
    q.push(st);
    visited[st.first][st.second] = true;
    int cnt = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (adj[x][y] == 'P')
            cnt++;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (visited[nx][ny])
                continue;
            if (adj[nx][ny] == 'X')
                continue;
            visited[nx][ny] = true;
            q.push({ nx,ny });
        }
    }

    if (cnt == 0)
        cout << "TT";
    else
        cout << cnt;


}


