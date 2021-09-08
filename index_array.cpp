#include <bits/stdc++.h>
using namespace std;

void  index_of_array()
{
	int N; cin >> N;
	vector<int> p(N+1);
	vector<int> Q(N+1);
	
	for (int i = 1; i <= N; i++)
	{
		cin >> p[i];
		Q[p[i]] = i;
	}
	for (int i = 1; i <= N; i++)
		cout << Q[i] << " ";
	cout << endl;
	return ;
}
