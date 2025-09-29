#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;
vector<int> seq;

void dfs(int depth, int start) {
    if (depth == M) {
        for (int i = 0; i < M; ++i) {
            if (i) cout << ' ';
            cout << seq[i];
        }
        cout << '\n';
        return;
    }
    for (int i = start; i < v.size(); i++) {
        seq.push_back(v[i]);
        dfs(depth + 1, i);
        seq.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    dfs(0, 0);
    return 0;
}
