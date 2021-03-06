#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long ll;

//xが2の何乗か 指数を計算
size_t		npow(long long x)
{
	size_t ret = (size_t)floor(log2(x)); //ex:)x = 8〜15 => 2の3乗 == 3;
	return ret;
}

// update こっちの方が正確
size_t	logN(long long n)
{
	size_t cnt = 0;
	while (n > 1) {
		n /= 2;
		cnt++;
	}
	return cnt;
}

int  main()
{
	long long N; cin >> N;
	int p = npow(N);
	cout << p << "乗" << endl;
	long long nb = (1 << p); /* 2 ^ p */

	cout << "2^" << p << " = "<< nb << endl;
	return (0);
}
