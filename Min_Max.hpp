#ifndef MIN_MAX_HPP
# define MIN_MAX_HPP

#include <vector>
#include <iostream>
#include <utility>

using namespace std;

template <typename T>
pair<T, T> min_max(vector<T> vec)
{
	pair<typename::vector<T>::iterator, typename::vector<T>::iterator> minmax;

	minmax = minmax_element(vec.begin(), vec.end());
	return make_pair<T, T>(*minmax.first, *minmax.second);
}

/*
** first    : min-value
** second   : count of min-value
*/
template <typename T>
pair<T, T> min_set(vector<T> vec)
{
	pair<T, T> set;

	set.first = *min_element(vec.begin(), vec.end());
	set.second = std::count(vec.begin(), vec.end(), set.first);
	return set;
}

/*
** first    : max-value
** second   : count of max-value
*/
template <typename T>
pair<T, T> max_set(vector<T> vec)
{
	pair<T, T> set;

	set.first = *max_element(vec.begin(), vec.end());
	set.second = std::count(vec.begin(), vec.end(), set.first);
	return set;
}

#endif
