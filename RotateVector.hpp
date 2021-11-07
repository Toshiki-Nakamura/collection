#ifndef ROTATEVECTOR_HPP
# define ROTATEVECTOR_HPP

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
vector<vector<T> >	rotate_vec(vector<vector<T> > col, int wide)
{
	int height = col.size();
	vector<vector<T> > row(wide, vector<T>(height));
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < wide; j++)
			row[j][i] = col[i][j];
	}
	return row;
}

vector<string>	rotate_strings(vector<string> col)
{
	int wide = col[0].size();
	int height = col.size();
	vector<string> row(wide, string(' ', height));
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < wide; j++)
			row[j][i] = col[i][j];
	}
	return row;
}

#endif
