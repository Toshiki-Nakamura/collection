#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;
typedef long double ld;
#define pi 3.14159265358979

int  main()
{
	int n,m; cin >> n >> m;
	if (n >= 12)
		n -= 12;
	ld s = (n * 30) + (0.5 * m);//長針
	ld l = 6 * m;//短針
	ld ans = min(abs(s- l), (ld)360 - abs(s - l));
	printf("%Lf", ans);
	return 0;
}
