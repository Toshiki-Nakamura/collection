#ifndef SORT_MAP_VEC_HPP
# define SORT_MAP_VEC_HPP

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Comp_desc {
public:
	bool operator() (const pair<char, int>& a, const pair<char, int>& b) {
		return a.second > b.second;
	}
};

bool Comp_asc(const pair<char, int>& a, const pair<char, int>& b) {
	return a.second < b.second;
}

/* https://cpprefjp.github.io/reference/type_traits/add_lvalue_reference.html */
template<typename Key, typename Val, class Comp>
vector<pair<Key, Val> >	map_sort(map<Key, Val> mp, Comp _comp)
{
	vector<pair<Key, Val> > vec;
	typedef typename __comp_ref_type<Comp>::type _Comp_ref;
	typename::map<Key, Val>::iterator itr = mp.begin();
	for (; itr != mp.end(); itr++) {
		vec.push_back(*itr);
	}
	// _Comp_ref => map_sort(mp, Comp_asc)でもmap_sort(mp, Comp_desc())でもsegvしない
	std::sort(vec.begin(), vec.end(), _Comp_ref(_comp));
	return vec;
}

/*
int		main()
{
	map<char, int> mp;
	for (size_t i = 0; i < 5; i++)
		mp['A' + i] = rand() % 99;
	vector<std::pair<char, int> > vec;
	vec = map_sort(mp, Comp_desc());
	for (auto &x : vec)
		cout << x.first << " " << x.second << endl;
	cout << "========================\n";
	vector<std::pair<char, int> > vec2;
	vec2 = map_sort(mp, Comp_asc);
	for (auto &x : vec)
		cout << x.first << " " << x.second << endl;
}
*/

#endif
