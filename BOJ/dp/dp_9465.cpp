#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> up(n + 1);
        vector<int> dn(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> up[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> dn[i];
        }

        vector<int> dpU(n + 1, 0);
        vector<int> dpD(n + 1, 0);
        dpU[1] = up[1];
        dpD[1] = dn[1];

        for (int i = 2; i <= n; ++i) {
            dpU[i] = max(dpD[i - 1], dpD[i - 2]) + up[i];
            dpD[i] = max(dpU[i - 1], dpU[i - 2]) + dn[i];
        }

        cout << max(dpU[n], dpD[n]) << '\n';



    }

}
