#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

/* https://atcoder.jp/contests/typical90/tasks/typical90_j */

int  main()
{
	int N; cin >> N;
	vector<pair<int, int> > vec(N + 1, pair<int, int>());
	vector<int> sum1(N+1, 0), sum2(N+1, 0);
	for (int i = 0; i < N; i++)
	{
		int C, P; cin >> C >> P;
		vec[i].first = C; vec[i].second = P;
		if (C == 1)
		{
			sum1[i + 1] += sum1[i] + P;
			sum2[i + 1] = sum2[i];
		}
		else if (C == 2)
		{
			sum2[i + 1] += sum2[i] + P;
			sum1[i + 1] = sum1[i];
		}
	}
	int Q; cin >> Q;
	vector<pair<int, int> > res(Q + 1, pair<int, int>());
	for (int i = 0; i < Q; i++)
	{
		int L, R; cin >> L >> R;
		res[i].first = sum1[R] - sum1[L - 1];
		res[i].second = sum2[R] - sum2[L - 1];
	}
	for (int i = 0; i < Q; i++)
	{
		cout << res[i].first << " " << res[i].second << "\n";
	}
	return (0);
}
