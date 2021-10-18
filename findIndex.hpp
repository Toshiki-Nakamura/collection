#ifndef FINDINDEX_HPP
# define FINDINDEX_HPP

#include <vector>

template <typename T>
int		findIndex(std::vector<T> vec, T elm)
{
	typename std::vector<T>::iterator itr;
	itr = std::find(vec.begin(), vec.end(), elm);
	if (itr == vec.end())
		return -1;
	const int index = std::distance(vec.begin(), itr);
	return index;
}

#endif
