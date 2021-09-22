#include <bits/stdc++.h>
using namespace std;

template <typename T>
pair<T, T> min_max(vector<T> vec)
{
	pair<typename::vector<T>::iterator, typename::vector<T>::iterator> minmax;

	minmax = minmax_element(vec.begin(), vec.end());
	return make_pair<T, T>(*minmax.first, *minmax.second);
}


/*
int		main()
{
	int N; cin >> N;
	vector<int> v(N);
	for (int i=0; i < N; i++)
		cin >> v[i];

	pair<int, int> p = min_max(v);
	cout << p.first << " " << p.second << endl;

	return 0;
}
*/
