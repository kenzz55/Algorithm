#include <iostream>
#include <vector>


using namespace std;

int N;
int ans = 0;
vector<bool> colused;
vector<bool> diag1;
vector<bool> diag2;

void dfs(int r) {
    if (r == N) {
        ans++;
        return;
    }
    for (int c = 0; c < N; c++) {
        if (colused[c])
            continue;
        if (diag1[r + c])
            continue;
        if (diag2[r - c + (N - 1)])
            continue;

        colused[c] = diag1[r + c] = diag2[r - c + (N - 1)] = true;
        dfs(r + 1);
        colused[c] = diag1[r + c] = diag2[r - c + (N - 1)] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    colused.assign(N, false);
    diag1.assign(2 * N - 1, false);
    diag2.assign(2 * N - 1, false);

    dfs(0);
    cout << ans;

}
