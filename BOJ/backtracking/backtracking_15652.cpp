#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int N, M;
vector<int> v;

void dfs(int start, int cnt) {
    if (cnt == M) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = start; i <= N; i++) {
        v.push_back(i);
        dfs(i, cnt + 1);
        v.pop_back();

    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> N >> M;

    dfs(1, 0);

}
