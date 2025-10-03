#include <iostream>
#include <vector>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> v(N + 1);
    vector<int> w(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }
    vector<int> backpack(K + 1, 0);

    for (int i = 1; i <= N; i++) {
        for (int j = K; j >= w[i]; j--) {
            backpack[j] = max(backpack[j], (backpack[j - w[i]] + v[i]));
        }
    }

    cout << backpack[K];



}
