#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, H;
    cin >> M >> N >> H;

    vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M)));
    vector<vector<vector<int>>> dist(H, vector<vector<int>>(N, vector<int>(M, -1)));

    queue<tuple<int, int, int>> q;
    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                cin >> box[z][y][x];
                if (box[z][y][x] == 1) {
                    q.emplace(z, y, x);
                    dist[z][y][x] = 0;
                }
            }
        }
    }

    int dz[6] = { 0,0,0,0,1,-1 };
    int dy[6] = { 1,-1,0,0,0,0 };
    int dx[6] = { 0,0,1,-1,0,0 };

    while (!q.empty()) {
        tuple<int, int, int> cur = q.front();
        int z = get<0>(cur);
        int y = get<1>(cur);
        int x = get<2>(cur);
        q.pop();

        for (int d = 0; d < 6; d++) {
            int nz = dz[d] + z;
            int ny = dy[d] + y;
            int nx = dx[d] + x;

            if (nz < 0 || nz >= H || ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            if (box[nz][ny][nx] == 0 && dist[nz][ny][nx] == -1) {
                box[nz][ny][nx] = 1;
                dist[nz][ny][nx] = dist[z][y][x] + 1;
                q.emplace(nz, ny, nx);
            }

        }
    }

    int cnt = 0;
    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (box[z][y][x] == 0) {
                    cout << -1;
                    return 0;
                }
                cnt = max(cnt, dist[z][y][x]);
            }
        }
    }

    cout << cnt;
}
