#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int M, N, K;
        cin >> M >> N >> K;

        vector<vector<int>> v(N, vector<int>(M, 0));

        for (int i = 0; i < K; i++) {
            int X, Y;
            cin >> X >> Y;
            v[Y][X] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (v[i][j] == 1) {
                    cnt++;
                    queue < pair<int, int>> q;
                    q.push({ i,j });
                    v[i][j] = 0;

                    while (!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();

                        int y = cur.first;
                        int x = cur.second;

                        for (int d = 0; d < 4; d++) {
                            int ny = y + dy[d];
                            int nx = x + dx[d];

                            if (ny >= 0 && ny < N && nx >= 0 && nx < M && v[ny][nx] == 1) {
                                v[ny][nx] = 0;
                                q.push({ ny, nx });
                            }
                        }
                    }
                }
            }
        }
        cout << cnt << '\n';
    }


}


