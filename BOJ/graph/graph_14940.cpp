#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    pair<int, int> st = { -1,-1 };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 2) st = { i, j };
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;


    dist[st.first][st.second] = 0;
    q.push(st);

    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];


            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;


            if (a[nx][ny] == 0) continue;
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny });
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 0) {
                cout << 0 << ' ';
            }
            else {
                cout << dist[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;


}


