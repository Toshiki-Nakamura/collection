#include <bits/stdc++.h>
#include <sstream>
using namespace std;
#define rep(i, n) for (long i = 0; i < (int)(n); i++)
#define rep1(i, n) for (long i = 1; i <= (int)(n); i++)
typedef long long ll;

/* ABC233 C - Product */
ll	N, X;
ll	ans = 0;
void	dfs(vector<vector<ll>> &vec, ll pos, ll v)
{
	if (pos == N) {
		if (v == X) {
			ans++;
		}
		return ;
	}
	for (auto elm : vec[pos]) {
		if (elm * v > X) continue;
		dfs(vec, pos+1, elm * v);
	}
}

int		main()
{
	cin >> N >> X;
	vector<vector<ll>> vec(N);
	rep(i, N) {
		ll L; cin >> L;
		vector<ll> a(L);
		rep(j, L)
			cin >> a[j];
		vec[i] = a;
	}
	dfs(vec, 0, 1);
	cout << ans << "\n";
	return (0);
}
