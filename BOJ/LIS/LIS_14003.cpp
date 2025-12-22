#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <climits>  
#include <cstdlib>
#include <algorithm>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    vector<int> lis;

    vector<int> pos(N);
    vector<int> prev(N, -1);

    for (int i = 0; i < N; i++) {
        int x = v[i];
        int idx;
        if (lis.empty() || lis.back() < x) {
            lis.push_back(x);
            idx = (int)lis.size() - 1;
        }
        else {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            idx = (int)(it - lis.begin());
            *it = x;
        }

        pos[idx] = i;

        if (idx > 0) {
            prev[i] = pos[idx - 1];
        }
    }

    int L = lis.size();
    vector<int> ans;
    int cur = pos[L - 1];
    while (cur != -1) {
        ans.push_back(v[cur]);
        cur = prev[cur];
    }

    cout << L << '\n';
    for (int i = L - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
    return 0;
}