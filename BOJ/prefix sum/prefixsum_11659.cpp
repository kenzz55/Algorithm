#include <iostream>
#include <vector>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector <long long> p(m + 1, 0);

    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        p[i] = p[i - 1] + x;
    }

    while (n--) {
        int i, j;
        cin >> i >> j;
        cout << p[j] - p[i - 1] << '\n';
    }


}


