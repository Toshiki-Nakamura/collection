#ifndef TREE_HPP
#define TREE_HPP

#include <memory>
#include <iostream>

template<typename T1, typename T2>
struct MapNode {
public:
	typedef std::pair<T1, T2>	pair_type;
	int				height;
	pair_type		_pair;
	MapNode		*parent;
	MapNode		*left;
	MapNode		*right;
	MapNode(pair_type const &p = pair_type()) 
	: height(0), _pair(p), parent(NULL), left(NULL), right(NULL)
	{}
	MapNode(T1 key, T2 val) 
	: height(0), _pair(std::make_pair(key, val)), parent(NULL), left(NULL), right(NULL) {}
	MapNode(MapNode const &src) 
	: height(src.height), _pair(src._pair), parent(src.parent), left(src.left), right(src.right)
	{}
};

template<typename T1, typename T2, class Comp, class Alloc = std::allocator<MapNode<T1, T2> > >
class tree {
public:
	typedef	MapNode<T1, T2> node_type;
	typedef Alloc			_node_alloc;
	typedef Comp			_comp_type;
	typedef T1				key_type;
	typedef ptrdiff_t		difference_type;
	typedef size_t			size_type;
	node_type	*NIL;
	node_type	*root;
private:
	_node_alloc				node_alloc;
	std::allocator<node_type> _alloc;
	_comp_type	_comp;

	// tree() {}
	void	init() {
		NIL = _alloc.allocate(1);
		_alloc.construct(NIL, node_type(std::pair<T1,T2>()));
		NIL->right = NULL;
		NIL->left = NULL;
	}
	/* Left/ (node->ht < 0),  Right\ (node->ht > 0) */
	void	rotate(node_type* node) {
		if (node->height > 0 && node->right->height < 0)
		{
			rightRotate(node->right); /* if right is minus */
			leftRotate(node);
		}
		else if (node->height > 0) {
			leftRotate(node);
		}
		else if (node->height < 0 && node->left->height > 0) 
		{
			leftRotate(node->left); /* if left is plus */
			rightRotate(node);
		}
		else if (node->height < 0) {
			rightRotate(node);
		}
	}
	void updateBalance(node_type* node) {
		if (node->height < -1 || node->height > 1)
		{
			rotate(node);
			return;
		}
		if (node->parent != NULL)
		{
			if (node == node->parent->left) {
				node->parent->height -= 1;
			} 
			if (node == node->parent->right) {
				node->parent->height += 1;
			}
			if (node->parent->height != 0) {
				updateBalance(node->parent);
			}
		}
	}
public:
	tree(const _node_alloc& alloc = _node_alloc(), const _comp_type &comp = Comp()) 
	: NIL(NULL), root(NULL), _alloc(alloc), _comp(comp) {
		init();
	}
	tree(tree const &cpy) 
	: NIL(cpy.NIL), root(cpy.root), _alloc(cpy._alloc), _comp(cpy._comp) {}
	tree	&operator=(tree const &src)
	{
		if (this == &src)
			return *this;
		if (this->root)
			clear_order(this->root);
		if (NIL)
			_alloc.deallocate(NIL, 1);
		NIL = src.NIL;
		root = src.root;
		_alloc = src._alloc;
		_comp = src._comp;
		return *this;
	}

	void	swap(tree &x)
	{
		ft_swap(this->_alloc, x._alloc);
		ft_swap(this->_comp, x._comp);
		node_type *tmp_root = this->root;
		this->root = x.root;
		x.root = tmp_root;
		node_type *tmp_NIL = this->NIL;
		this->NIL = x.NIL;
		x.NIL = tmp_NIL;
	}

	virtual ~tree() {
		clear_order(root);
		if (NIL)
			_alloc.deallocate(NIL, 1);
	}

	void clear_order(node_type* node) {
		if (node == NIL || !node) return; //** if (node == NIL) return;
		if (node->left != NIL) clear_order(node->left);
		if (node->right != NIL) clear_order(node->right); 
		_alloc.deallocate(node, 1);
	}
	/* function */
	size_t		max_size() const { 
		return std::min<size_type>(node_alloc.max_size(), 
				std::numeric_limits<difference_type>::max());
	}
	int max(int a, int b) {return (a > b) ? a : b;}
	int min(int a, int b) {return (a < b) ? a : b;}
	int height(node_type *node) {
		if (node == NULL) return 0;
		return node->height;
	}
	node_type*	minimum(node_type* node) const
	{
		if (node == this->root && !node) return NIL;
		while (node->left != NULL) {
			node = node->left;
		}
		return node;
	}
	node_type*	minimum(node_type* node)
	{
		if (node == this->root && !node) return NIL;
		while (node->left != NULL) {
			node = node->left;
		}
		return node;
	}
	node_type*	maximum(node_type* node) const
	{
		if (node == this->root && !node) return NIL;
		while (node->right != NULL) {
			node = node->right;
		}
		return node;
	}
	node_type*	maximum(node_type* node)
	{
		if (node == this->root && !node) return NIL;
		while (node->right != NULL) {
			node = node->right;
		}
		return node;
	}

	node_type*	getNext(node_type* node)
	{
		if (node->right != NULL)
			return minimum(node->right);
		node_type *top = node->parent;
		while (top != NULL && node == top->right) {
			node = top;
			top = top->parent;
		}
		return top;
	}
	node_type*	getPrev(node_type* node)
	{
		if (node->left != NULL)
			return maximum(node->left);
		node_type *top = node->parent;
		while (top != NULL && node == top->left) {
			node = top;
			top = top->parent;
		}
		return top;
	}

	void	leftRotate(node_type* x) {
		node_type* y = x->right;
		x->right = y->left;
		if (y->left != NULL) {
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == NULL) {
			this->root = y;
		} else if (x == x->parent->left) {
			x->parent->left = y;
		} else {
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
		// update the balance factor
		x->height = (x->height - 1) - max(0, y->height);
		y->height = (y->height - 1) + min(0, x->height);
	}
	void	rightRotate(node_type* x) {
		node_type* y = x->left;
		x->left = y->right;
		if (y->right != NULL)
			y->right->parent = x;
		y->parent = x->parent;
		if (y->parent == NULL)
			this->root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else 
			x->parent->right = y;
		y->right = x;
		x->parent = y;
		// update the balance factor
		x->height = (x->height + 1) - min(0, y->height);
		y->height = (y->height + 1) + max(0, x->height);
	}
	int getBalance(node_type *node)
	{
		if (node == NULL)
			return 0;
		return height(node->left) - height(node->right);
	}
	node_type* newNode(T1 key, T2 val)
	{
		node_type *node = _alloc.allocate(1);
		_alloc.construct(node, node_type(key, val));
		node->parent = NULL;
		node->left = NULL;
		node->right = NULL;
		node->height = 0;
		return(node);
	}
	void insert(T1 key, T2 val) {
		node_type* node = newNode(key, val);
		node_type* x = this->root;
		node_type* y = NULL;
		while (x != NULL) {
			y = x;
			if (_comp(key, x->_pair.first)) /* node->data < x->data */
				x = x->left;
			else
				x = x->right;
		}
		node->parent = y;
		if (y == NULL) {
			root = node;
		} else if (_comp(node->_pair.first, y->_pair.first)) {
			y->left = node;
		} else {
			y->right = node;
		}
		updateBalance(node);
	}


	void delete_node(T1 key) {
		node_type *x, *y, *z;

		z = find(key);
		if (!z || z == NIL) return ;
		if (z->left == NULL || z->right == NULL)// child 0 or 1
			y = z;
		else {  // child 2
			y = getNext(z);/* next_node(z); */
		}
		// x = y's child
		if (y->left != NULL) x = y->left;
		else x = y->right;

		if (x != NULL) x->parent = y->parent;
		if (y->parent == NULL) this->root = x;
		else if (y == y->parent->left) // left or right
			y->parent->left = x;
		else 
			y->parent->right = x;
		// if child 2
		// node_type* node = y->parent;
		if (z != y) z->_pair = y->_pair;
		_alloc.destroy(y);
		_alloc.deallocate(y, 1);
		y = NULL;
		if (z && z != y) {
			updateBalance(z);
		}
	}

	void	clear(node_type* node) 
	{
		if (!node) return; //** if (node == NIL) return;
		if (node->left != NIL) clear(node->left);
		delete_node(node->_pair.first);
		if (node->right != NIL) clear(node->right); 
	}

	node_type*	search(node_type*	node, T1 key) const
	{
		if (node == NULL || key == node->_pair.first)
			return node;
		if (_comp(key, node->_pair.first))//key < node->_pair
			return search(node->left, key);
		return search(node->right, key);
	}
	node_type* find(T1 key) const
	{
		return search(this->root, key);
	}

	void inorder(node_type* node) {
		if (node == NIL || !node) return; //** if (node == NIL) return;
		if (node->left != NIL && node->left) inorder(node->left);
		std::cout << node->_pair.first << " ";
		std::cout << node->_pair.second << "\n";
		if (node->right != NIL && node->right) inorder(node->right);
	}

};



#endif
