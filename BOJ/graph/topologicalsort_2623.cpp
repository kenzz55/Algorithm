#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> adj(N + 1);
	vector<int> cnt(N + 1, 0);

	while (M--) {
		int p;
		cin >> p;
		vector<int> temp;
		for (int i = 0; i < p; i++) {
			int x;
			cin >> x;
			temp.push_back(x);
		}

		for (int i = 0; i < p; i++) {
			if (i + 1 == p)
				break;
			adj[temp[i]].push_back(temp[i + 1]);
			cnt[temp[i + 1]]++;
		}
	}

	vector<int> order;
	order.reserve(N + 1);

	queue<int> q;
	for (int i = 1; i < cnt.size(); i++) {
		if (cnt[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		order.push_back(u);

		for (int v : adj[u]) {
			if (--cnt[v] == 0)
				q.push(v);
		}

	}

	if ((int)order.size() != N) {
		cout << 0 << '\n';
		return 0;
	}

	for (int x : order) {
		cout << x << '\n';
	}

}