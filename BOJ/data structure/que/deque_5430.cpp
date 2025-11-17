#include <iostream>
#include <string>
#include <deque>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;

    cin >> T;
    while (T--) {
        string p;
        int n;
        string s;
        cin >> p;
        cin >> n;
        cin >> s;

        deque<int> dq;
        int num = 0;
        bool inNum = false;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
                inNum = true;
            }
            else {
                if (inNum) {
                    dq.push_back(num);
                    num = 0;
                    inNum = false;
                }
            }
        }

        bool rev = false;
        bool err = false;
        for (char cmd : p) {
            if (cmd == 'R') {
                rev = !rev;
            }
            else if (cmd == 'D') {
                if (dq.empty()) {
                    err = true;
                    break;
                }
                if (!rev) dq.pop_front();
                else      dq.pop_back();
            }
        }

        if (err) {
            cout << "error\n";
            continue;
        }

        cout << '[';
        if (!rev) {
            for (int i = 0; i < dq.size(); i++) {
                cout << dq[i];
                if (i != dq.size() - 1) cout << ',';
            }
        }
        else {
            for (int i = 0; i < dq.size(); i++) {
                cout << dq[dq.size() - 1 - i];
                if (i != dq.size() - 1) cout << ',';
            }
        }
        cout << "]\n";
    }


}
