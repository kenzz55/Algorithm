#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
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

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<int> ans;

    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (s[i][j] == '1' && !visited[i][j]) {
                int cnt = 0;
                queue < pair<int, int>> q;
                q.push({ i,j });
                visited[i][j] = true;

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    cnt++;
                    for (int d = 0; d < 4; d++) {
                        int nx = dx[d] + x;
                        int ny = dy[d] + y;
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                            continue;
                        if (visited[nx][ny])
                            continue;
                        if (s[nx][ny] == '0')
                            continue;
                        visited[nx][ny] = true;
                        q.push({ nx,ny });
                    }
                }
                ans.push_back(cnt);
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int p : ans)
        cout << p << '\n';

}
