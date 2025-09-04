#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;


        if (N >= 6) {
            vector<long long> P(N + 1, 0);
            P[1] = 1;
            P[2] = 1;
            P[3] = 1;
            P[4] = 2;
            P[5] = 2;
            for (int i = 6; i <= N; i++) {
                P[i] = P[i - 1] + P[i - 5];
            }
            cout << P[N] << '\n';
        }

        if (N == 1 || N == 2 || N == 3) {
            cout << 1 << '\n';
        }
        else if (N == 4 || N == 5) {
            cout << 2 << '\n';
        }

    }



    return 0;
}

