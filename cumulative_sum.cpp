#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main()
{
	int N; cin >> N;
	vector<int> A(N);
	vector<int> total(N + 1, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		total[i + 1] = total[i] + A[i];
	}
	return (0);
}
