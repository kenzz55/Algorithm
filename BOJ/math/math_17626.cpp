#include <iostream>
#include <cmath>
using namespace std;

bool isSquare(int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (isSquare(n)) {
        cout << 1;
        return 0;
    }

    for (int i = 1; i * i <= n; i++) {
        if (isSquare(n - i * i)) {
            cout << 2;
            return 0;
        }
    }

    // 레장드르 정리

    int m = n;
    while (m % 4 == 0) {
        m /= 4;
    }
    if (m % 8 == 7) {
        cout << 4;
        return 0;
    }

    cout << 3;
    return 0;

}

bool isSquare(int x)
{
    int r = static_cast<int>(sqrt((double)x));
    return r * r == x;
}
