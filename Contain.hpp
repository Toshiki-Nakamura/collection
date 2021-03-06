#ifndef CONTAIN_HPP
#define CONTAIN_HPP
#include <string>

template<class T, class U>
bool contain(const std::basic_string<T>& s, const U& v)
{
	return s.find(v) != std::basic_string<T>::npos;
}

#endif
