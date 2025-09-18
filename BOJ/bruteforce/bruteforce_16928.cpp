#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int M;
    cin >> N >> M;

    vector<vector<int>> paper(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> paper[i][j];
        }
    }

    int tetris[19][4][2] = {
        //I
        {{0,0},{0,1},{0,2},{0,3}},
        {{0,0},{1,0},{2,0},{3,0}},
        // O
        {{0,0},{0,1},{1,0},{1,1}},
        // L 
        {{0,0},{1,0},{2,0},{2,1}},
        {{0,1},{1,1},{2,1},{2,0}},
        {{0,0},{0,1},{1,0},{2,0}},
        {{0,0},{0,1},{1,1},{2,1}},
        {{0,0},{0,1},{0,2},{1,0}},
        {{0,0},{0,1},{0,2},{1,2}},
        {{0,0},{1,0},{1,1},{1,2}},
        {{0,2},{1,0},{1,1},{1,2}},
        // Z 
        {{0,0},{1,0},{1,1},{2,1}},
        {{0,1},{1,0},{1,1},{2,0}},
        {{0,1},{0,2},{1,0},{1,1}},
        {{0,0},{0,1},{1,1},{1,2}},
        // T 
        {{0,0},{0,1},{0,2},{1,1}},
        {{0,1},{1,0},{1,1},{2,1}},
        {{0,1},{1,0},{1,1},{1,2}},
        {{0,0},{1,0},{1,1},{2,0}}
    };

    int ans = 0;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            for (int t = 0; t < 19; t++) {
                int sum = 0;

                for (int k = 0; k < 4; k++) {
                    int nx = x + tetris[t][k][0];
                    int ny = y + tetris[t][k][1];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
                    sum += paper[nx][ny];
                }

                ans = max(sum, ans);
            }
        }
    }

    cout << ans;
}
