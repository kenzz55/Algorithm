#include <iostream>
#include <string>
#include <queue>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;

        vector<bool> visited(10000, false);
        queue<pair<int, string>> q;
        q.push({ A, "" });
        visited[A] = true;
        while (!q.empty()) {
            int cur = q.front().first;
            string path = q.front().second;
            q.pop();

            if (cur == B) {
                cout << path << '\n';
                break;
            }
            int D = (2 * cur) % 10000;
            if (!visited[D]) {
                visited[D] = true;
                q.push({ D,path + "D" });
            }

            int S = (cur == 0 ? 9999 : cur - 1);
            if (!visited[S]) {
                visited[S] = true;
                q.push({ S, path + "S" });
            }

            int L = (cur % 1000) * 10 + (cur / 1000);
            if (!visited[L]) {
                visited[L] = true;
                q.push({ L, path + "L" });
            }

            int R = (cur / 10) + (cur % 10) * 1000;
            if (!visited[R]) {
                visited[R] = true;
                q.push({ R, path + "R" });
            }
        }
    }

}
