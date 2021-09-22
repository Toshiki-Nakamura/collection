#ifndef MIN_MAX_HPP
# define MIN_MAX_HPP

#include <bits/stdc++.h>
using namespace std;

template <typename T>
pair<T, T> min_max(vector<T> vec)
{
	pair<typename::vector<T>::iterator, typename::vector<T>::iterator> minmax;

	minmax = minmax_element(vec.begin(), vec.end());
	return make_pair<T, T>(*minmax.first, *minmax.second);
}

#endif
