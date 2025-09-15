#include <iostream>
#include <algorithm>


using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<int, int> P1;
    pair<int, int> P2;
    pair<int, int> P3;

    cin >> P1.first >> P1.second;
    cin >> P2.first >> P2.second;
    cin >> P3.first >> P3.second;

    long long ans = (P2.first - P1.first) * (P3.second - P1.second) - (P2.second - P1.second) * (P3.first - P1.first);
    if (ans > 0)
        cout << 1;
    if (ans < 0)
        cout << -1;
    if (ans == 0)
        cout << 0;
}
