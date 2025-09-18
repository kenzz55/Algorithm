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

    vector<int> dist(101, -1);
    vector<int> v(101);

    for (int i = 0; i <= 100; i++) {
        v[i] = i;
    }

    for (int i = 0; i < M + N; i++) {
        int index1, index2;
        cin >> index1 >> index2;
        v[index1] = index2;
    }

    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == 100) break;

        for (int d = 1; d <= 6; d++) {
            int y = x + d;
            if (y > 100)
                continue;
            int z = v[y];
            if (dist[z] == -1) {
                dist[z] = dist[x] + 1;
                q.push(z);
            }
        }
    }
    cout << dist[100];

}
