#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <memory>
#include <iostream>

template<typename T>
struct Node {
	Node	*next;
	Node	*prev;
	T		value;
	void	init() {
		next = this;
		prev = this;
	}
};

template<typename T>
class d_list {
public:
	typedef	T				value_type;
	typedef	size_t			size_type;
	typedef	Node<T>			node_type;

	std::allocator<Node<T> >	_node_alloc;
	size_t					_size;
	node_type				*_nil;

private:
	void	delete_node(node_type* node) {
		if (node == _nil) return;  // nodeが番兵の時は何もしない
		// リンクつなぎ変え
		node->prev->next = node->next; 
		node->next->prev = node->prev;
		_node_alloc.destroy(node);        //destroy node
		_node_alloc.deallocate(node, 1); //delete node;
		_size--;
	}
	void	addfront(T const &val) {
		node_type* x = new Node<value_type>();
		x->value = val;

		x->next = this->_nil->next;
		this->_nil->next->prev = x;
		this->_nil->next = x;
		x->prev = this->_nil;
		_size++;
	}
	void	addback(T const &val) {
		node_type* x = new Node<value_type>();
		x->value = val;

		x->prev = this->_nil->prev;
		this->_nil->prev->next = x;
		this->_nil->prev = x;
		x->next = this->_nil;
		_size++;
	}

	void	addmiddle(T const &val, node_type* pos) {
		// node_type* x = new Node<value_type>();
		node_type* x =_node_alloc.allocate(1);
		_node_alloc.construct(x, Node<value_type>());
		x->value = val;

		x->prev = pos->prev;
		pos->prev->next = x;
		pos->prev = x;
		x->next = pos;
		_size++;
	}
	// Returns first node(pointer) which has val.
	node_type*	list_search(T val) {
		node_type *current = _nil->next;
		while (current != _nil && current->value != val)
		{
			current = current->next;
		}
		if (_nil == current)
			return (NULL);
		return current;
	}


public:

		/* For debug */
	void	print_list() {
		int cnt = 0;
		node_type* current = _nil->next;
		while (current != _nil) {
			if (cnt++ > 0) std::cerr << " ";
			std::cerr << current->value;
			current = current->next;
		}
		// std::cerr << " < " << current->value;   // 番兵
		// std::cerr << " > " << current->next->value; // 先頭に戻る
		std::cerr << std::endl;
	}

	d_list()
	: _size(0)
	{
		_nil = _node_alloc.allocate(1);
		_node_alloc.construct(_nil, Node<T>());
		_nil->init();
	}
	d_list&	operator=(const d_list &src)
	{
		if (this == &src)
			return *this;
		assign(src.begin(), src.end());
		return *this;
	}

	~d_list() {
		this->clear();
		_node_alloc.destroy(_nil);
		_node_alloc.deallocate(_nil, 1);
	}

	void				push_front(const value_type& val) {addfront(val);}
	void				pop_front() {delete_node(_nil->next);}

	void				push_back(const value_type& val) {addback(val);}
	void				pop_back() {delete_node(_nil->prev);}

	void				assign(size_type n, const value_type& val) {
		this->clear();
		for (size_t i = 0; i < n; i++) {
			addfront(val);
		}
	}

	void					remove(const value_type& val) {
		node_type	*tmp;
		while ((tmp = list_search(val)) != NULL) {
			delete_node(tmp);
		}
	}

	void				clear() {
		node_type* current = _nil->next;
		node_type* tmp_next;
		while (current != _nil) {
			tmp_next = current->next;
			delete_node(current);
			current = tmp_next;
		}
	}

};

#endif
