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
	vector<int> indeg(N + 1, 0);

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		adj[A].push_back(B);
		indeg[B]++;
	}

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (indeg[i] == 0)
			q.push(i);
	}

	vector<int> order;
	order.reserve(N);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		order.push_back(u);

		for (int v : adj[u]) {
			if (--indeg[v] == 0)
				q.push(v);
		}
	}

	for (int i : order) {
		cout << i << ' ';
	}

}