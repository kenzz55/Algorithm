#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;
vector<int> b;
vector<bool> used;


void dfs(int cnt) {

    if (cnt == M) {
        for (int x : b) {
            cout << x << " ";
        }
        cout << '\n';
        return;
    }

    int prev = -1;
    for (int i = 0; i < N; i++) {
        if (used[i])
            continue;
        if (prev == v[i])
            continue;
        used[i] = true;
        b.push_back(v[i]);
        prev = v[i];
        dfs(cnt + 1);
        b.pop_back();
        used[i] = false;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    used.assign(N, false);
    dfs(0);


}
