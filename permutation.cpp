#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

void	permutate(string s)
{
	sort(s.begin(), s.end());

	do 
	{
		cout << s << endl;
	} 
	while (next_permutation(s.begin(), s.end()));
}

int  main()
{
	string s;
	cin >> s;
	permutate(s);
	return (0);
}
