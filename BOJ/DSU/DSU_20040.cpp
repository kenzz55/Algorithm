#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <climits>  
#include <cstdlib>
#include <algorithm>


using namespace std;

const int MAX = 500000;
int parent[MAX];
int rnk[MAX];

int findparent(int x) {
    if (parent[x] == x)
        return x;
    return findparent(parent[x]);
}


bool union_set(int a, int b) {
    a = findparent(a);
    b = findparent(b);

    if (a == b)
        return false;

    if (rnk[a] < rnk[b]) swap(a, b);

    parent[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;

    return true;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        rnk[i] = 0;
        parent[i] = i;
    }

    int ans = 0;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        if (!union_set(a, b)) {
            if (ans == 0) ans = i;
        }
    }

    cout << ans << '\n';




    return 0;
}