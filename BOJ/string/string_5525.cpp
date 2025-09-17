#include <iostream>
#include <vector>
#include <string>


using namespace std;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int M;
    cin >> M;

    string s;
    cin >> s;

    int cnt = 0;
    int k = 0;
    for (int i = 1; i + 1 < M;) {
        if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') {
            k++;
            if (k >= N)
                cnt++;
            i += 2;
        }
        else {
            k = 0;
            i++;
        }
    }


    cout << cnt;
}
