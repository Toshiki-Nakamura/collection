#include "doubly_linked_list.hpp"

int	main()
{
	d_list<int> lst;

	for (int i = 0; i < 10; i++)
		lst.push_front(i);
	for (int i = 0; i < 5; i++)
		lst.push_back(42);

	lst.print_list();
	lst.remove(0);

	lst.print_list();
}
