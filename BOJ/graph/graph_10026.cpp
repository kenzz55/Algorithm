#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> s(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    vector<string> rs = s;

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };

    int cnt = 0;
    queue < pair <int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                cnt++;
                q.push({ i,j });

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int d = 0; d < 4; d++) {
                        int nx = dx[d] + x;
                        int ny = dy[d] + y;
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                            continue;
                        if (visited[nx][ny])
                            continue;
                        if (s[nx][ny] != s[x][y])
                            continue;
                        visited[nx][ny] = true;
                        q.push({ nx,ny });

                    }

                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (rs[i][j] == 'R')
                rs[i][j] = 'G';
        }
    }

    int rcnt = 0;
    vector<vector<bool>> rvisited(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!rvisited[i][j]) {
                rvisited[i][j] = true;
                rcnt++;
                q.push({ i,j });

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int d = 0; d < 4; d++) {
                        int nx = dx[d] + x;
                        int ny = dy[d] + y;
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                            continue;
                        if (rvisited[nx][ny])
                            continue;
                        if (rs[nx][ny] != rs[x][y])
                            continue;
                        rvisited[nx][ny] = true;
                        q.push({ nx,ny });

                    }

                }
            }
        }
    }

    cout << cnt << " " << rcnt;
}
