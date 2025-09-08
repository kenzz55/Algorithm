#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        unordered_map<string, int> kindcount;

        for (int i = 0; i < n; i++) {
            string name, kind;
            cin >> name >> kind;
            kindcount[kind]++;
        }

        long long ans = 1;
        for (auto& kv : kindcount) {
            ans *= (kv.second + 1); //안입는 경우
        }
        cout << ans - 1 << '\n'; // 다 안입는 경우
    }


}

