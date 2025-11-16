#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	vector<long long> x(N + 1);
	vector<long long > y(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}

	x[N] = x[0];
	y[N] = y[0];

	long long sum1 = 0;
	long long sum2 = 0;

	for (int i = 0; i < N; i++) {
		sum1 += x[i] * y[i + 1];
		sum2 += y[i] * x[i + 1];
	}

	long long diff = sum1 - sum2;
	if (diff < 0)
		diff = -diff;

	double area = (double)diff / 2.0;
	printf("%.1f\n", area);





}