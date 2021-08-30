#include <bits/stdc++.h>
# include <vector>
using namespace std;

/* https://atcoder.jp/contests/typical90/tasks/typical90_d */

int		main()
{
	int H, W;
	cin >> H >> W;

	// H * W
	vector<vector<int> > a(H, vector<int>(W));
	vector<int> col(W+1, 0);
	vector<int> row(H+1, 0);
	for (int i = 0; i < H; i++)
	{
		int y_sum = 0;
		for (int j = 0; j < W; j++)
		{
			cin >> a[i][j];
			y_sum += a[i][j];
		}
		row[i] = y_sum;
	}

	for (int i = 0; i < W; i++)
	{
		int y_sum = 0;
		for (int j = 0; j < H; j++)
		{
			y_sum += a[j][i];
		}
		col[i] += y_sum;
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << (row[i] + col[j]) - a[i][j] << " ";
		}
		cout << endl;
	}
}
