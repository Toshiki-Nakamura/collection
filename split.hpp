#ifndef SPLIT_HPP
#define SPLIT_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class T, class U>
bool contain(const std::basic_string<T>& s, const U& v)
{
	return s.find(v) != std::basic_string<T>::npos;
}

vector<string > split(string str, string sep)
{
	vector<string > vec;
	const size_t seplen = sep.length();
	size_t pos = 0, i = 0;

	if (contain(str, sep) == false)
	{
		vec.push_back(str);
		return vec;
	}
	while (contain(str, sep))
	{
		pos = str.find(sep);
		string s = str.substr(0, pos); //str[0]~str[pos-1]
		if (!s.empty()) vec.push_back(s);
		i = pos + seplen;
		str = str.substr(i, str.size() - i); // str[i]~str[len-1]
	}
	if (!str.empty())
		vec.push_back(str);
	return vec;
}

#endif
