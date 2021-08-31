#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

/* gcd(最大公約数) */
long gcd(long a, long b)
{
	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

/* lcm(最小公倍数) */
long lcm(long a, long b)
{
	return ( (a * b) / gcd(a, b) );
}

int main()
{
	long a, b;
	cin >> a >> b;
	long l = lcm(a,b);
	long g = gcd(a,b);
	cout << "lcm(a,b)= " << l << endl;
	cout << "gcd(a,b)= " << g << endl;
	return (0);
}
