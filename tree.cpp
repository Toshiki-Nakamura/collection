#include "tree.hpp"

int		main()
{
	tree <int, char, std::less<int> > _tree;

	_tree.insert(42, '*');
	_tree.insert(97, 'a');
	_tree.insert(98, 'b');
	_tree.insert(99, 'c');

	MapNode<int, char> *node; 
	node = _tree.find(97);
	std::cout << "find(98): " << node->_pair.second << std::endl;

	node = _tree.maximum(_tree.root);
	std::cout << "maximum " << node->_pair.second << std::endl;

	_tree.delete_node(98);

	_tree.inorder(_tree.root);
	std::cout << std::endl;

}


