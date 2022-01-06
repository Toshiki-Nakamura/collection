#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string > split(string str, string sep);

int		main(int ac, char **av)
{
	if (ac != 3) return 0;
	vector<string> lhs = split(string(av[1]), ",");
	vector<string> rhs = split(string(av[2]), ",");

	cout << "==============   LHS   ===========" << endl;
	cout << lhs.size() << endl;
	for (auto x : lhs)
	{
		if (std::find(rhs.begin(), rhs.end(), x) != rhs.end()) {
			cout << x << endl;
		} 
		else {
			cout << "\033[31m" << x << "\033[0m" << endl;
		}
	}
	cout << "==============  RHS  ==================" << endl;
	cout << rhs.size() << endl;
	for (auto x : rhs)
	{
		if (std::find(lhs.begin(), lhs.end(), x) != lhs.end()) {
			cout << x << endl;
		} 
		else {
			cout << "\033[32m" << x << "\033[0m" << endl;
		}
	}
	return (0);
}
