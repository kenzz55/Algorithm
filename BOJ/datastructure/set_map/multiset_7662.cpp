#include <iostream>
#include <algorithm>
#include <set>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int T;
    cin >> T;



    while (T--) {
        int k;
        cin >> k;
        multiset<int> ms;
        for (int i = 0; i < k; i++) {
            char c;
            int n;
            cin >> c >> n;
            if (c == 'I') {
                ms.insert(n);
            }
            else {
                if (ms.empty()) continue;
                if (n == 1) {
                    auto it = prev(ms.end());
                    ms.erase(it);
                }
                else {
                    auto it = ms.begin();
                    ms.erase(it);
                }
            }
        }

        if (ms.empty()) {
            cout << "EMPTY" << '\n';
        }
        else {
            auto mx = *prev(ms.end());
            auto mn = *ms.begin();
            cout << mx << " " << mn << '\n';
        }
    }


}
