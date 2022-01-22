#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define repl(i, l, n) for (int i = l; i <= n; i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

/* https://qiita.com/drken/items/56a6b68edef8fc605821  */

template<typename T>
vector<T>	ruiseki(const vector<T> &vec)
{
	size_t	size = vec.size();
	vector<T> total(size + 1, 0);
	for (long i = 0; i < size; i++)
	{
		total[i+1] = total[i] + vec[i];
	}
	return total;
}

int  main()
{
	long N, K; cin >> N >> K;
	vector<long> a(N);
	vector<long> total;
	rep(i, N) {
		cin >> a[i];
	}
	//累積和の前処理
	total = ruiseki(a);
	long ans = LONG_MIN;
	
	for (long i = 0; i < N + K; i++) {
		long val = total[i + K] - total[i];
		ans = max(val, ans);
	}
	cout << ans << endl;
	return (0);
}
