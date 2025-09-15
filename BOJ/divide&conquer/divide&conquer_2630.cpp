#include <iostream>
using namespace std;

int whitecnt = 0;
int bluecnt = 0;
int arr[130][130];

bool samecolor(int x, int y, int sz) {
    int c = arr[x][y];
    for (int i = x; i < x + sz; i++) {
        for (int j = y; j < y + sz; j++) {
            if (arr[i][j] != c) return false;
        }
    }
    return true;
}

void cut(int x, int y, int sz) {
    if (samecolor(x, y, sz)) {
        if (arr[x][y] == 0) whitecnt++;
        else bluecnt++;
        return;
    }
    int h = sz / 2;

    cut(x, y, h);
    cut(x, y + h, h);
    cut(x + h, y, h);
    cut(x + h, y + h, h);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    cut(0, 0, N);
    cout << whitecnt << '\n' << bluecnt << '\n';
    return 0;
}
