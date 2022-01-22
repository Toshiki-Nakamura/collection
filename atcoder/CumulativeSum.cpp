#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;
#define MOD 1000000007

int  main()
{
	int n; cin >> n;
	vector<long> a(n);
	vector<long> b(n+1);
	long ans = 0;
	rep(i, n)
	{
		cin >> a[i];
	}
	b[0] = 0;
	rep1(i, n) //累積和
		b[i] = a[i - 1] + b[i - 1];

	for(int i = 0; i < n; i++)
	{
		//累積和を使って (A[i+1] + ... + A[N]) を求める
		long long asum = (b[n] - b[i + 1]) % MOD;
		ans += a[i] * asum; // A[i] * (A[i+1] + ... + A[N]) <==> (A[i] * A[i + 1]) + (A[i] * A[i + 2]) + ... + (A[i] * A[N]);
		ans %= MOD;
	}
	cout << ans << endl;
	return (0);
}