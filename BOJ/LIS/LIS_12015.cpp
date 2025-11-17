#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <climits>  
#include <cstdlib>


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
    for (int x : v) {
        if (lis.empty() || lis.back() < x) {
            lis.push_back(x);
        }
        else {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            *it = x;
        }
    }

    cout << lis.size();
    return 0;
}