#ifndef SORT_MAP_VEC_HPP
# define SORT_MAP_VEC_HPP

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Comp_dec {
public:
	bool operator() (const pair<char, int>& a, const pair<char, int>& b) {
		return a.second > b.second;
	}
};

template<typename Key, typename Val, class Comp>
vector<pair<Key, Val> >	map_sort(map<Key, Val> mp, Comp _comp)
{
	vector<pair<Key, Val> > vec;
	typename::map<Key, Val>::iterator itr = mp.begin();
	for (; itr != mp.end(); itr++) {
		vec.push_back(*itr);
	}
	std::sort(vec.begin(), vec.end(), Comp_dec());
	return vec;
}

/*
int		main()
{
	size_t n; cin >> n;
	map<char, int> mp;
	for (size_t i = 0; i < n; i++)
	{
		char c; int a; 
		cin >> c >> a;
		mp[c] += a;
	}
	vector<std::pair<char, int> > vec;
	vec = map_sort(mp, Comp_dec());
	for (auto &x : vec) {
		cout << x.first << " " << x.second << endl;
	}
	return (0);
}
*/

#endif
