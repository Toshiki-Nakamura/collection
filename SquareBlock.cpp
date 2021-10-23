#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long ll;

// https://paiza.jp/career/challenges/69/retry

void	devide_square(int N, int K)
{
	int block = N / K;// 6 / 3 = 2
	vector<vector<int> > vec(N, vector<int>(N));
	vector<vector<int> > S(block, vector<int>(block, 0));

	int x = 0, y = 0;
	for (int i = 0; i < N; i++)
	{
		x = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> vec[i][j];
			S[y][x] += vec[i][j];
			if ((j+1) % K == 0)
				x++;
		}
		if ((i+1) % K == 0)
			y++;
	}
	for (int i = 0; i < block; i++)
	{
		for (int j = 0; j < block; j++)
		{
			cout << S[i][j] / (K * K);
			if (j + 1 != block)
				cout << " ";
		}
		cout << endl;
	}
}

/* 
int		main(void)
{
	int N, K; cin >> N >> K;
	devide_square(N, K);
} 
*/
