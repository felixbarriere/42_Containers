#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "node_struct.hpp"
# include "null_ptr.hpp"

namespace ft
{

	template <typename T, typename Compare, typename Node = ft::node<T>,
											typename Allocator = std::allocator<Node> >
	class RBT
	{
    /* ****************************************************************************************** */
	/****************************************** ALIASES *******************************************/
	public:
	    typedef T					                value_type;	       //change to ft                         
	    typedef std::size_t                         size_type;	                                 
	    typedef Allocator                           allocator_type;	                            
	    typedef value_type&                         reference;
		typedef	Compare								value_compare;
	    // typedef typename Allocator::node_ptr        pointer;	       //typename tells the compiler that an unknown identifier is a type (cf Allocator).                           
	    // typedef typename Node::node_ptr	            NodePtr;                          
	    typedef typename Allocator::pointer		        NodePtr;                          
		// typedef typename Node::color				color;

    /* ****************************************************************************************** */
	/****************************************** MEMBER DATAS **************************************/

	private:
		value_compare	_comp;
		allocator_type	_alloc;
		NodePtr			_end;
		NodePtr			_root;
		NodePtr			LEAF_NULL;
		// size_type		_size;

    /* ****************************************************************************************** */
	/****************************************** CONSTRUCTORS / DESTRUCTORS ************************/

	public:
	RBT(const value_compare& comp = value_compare())
			: _comp(comp), _alloc(allocator_type()), _end(_alloc.allocate(1)), _root(_end)
	{
		this->LEAF_NULL = _alloc.allocate(1);
		_alloc.construct(LEAF_NULL, Node(value_type()));	

		LEAF_NULL->parent = ft::null_ptr;
		LEAF_NULL->left = ft::null_ptr;
		LEAF_NULL->right = ft::null_ptr;
		LEAF_NULL->color = BLACK;
		// this->_root = LEAF_NULL;
	}

	~RBT() {}

    /* ****************************************************************************************** */
	/****************************************** MEMBER FUNCTIONS **********************************/

	void initializeNULLNode(NodePtr node, NodePtr parent)
	{
		node->key = 0;
		node->parent = parent;
		node->left = ft::null_ptr;
		node->right = ft::null_ptr;
		node->color = 0;
	}

	NodePtr
	minimum(NodePtr node)
	{
		if (!node || node == _end)
			return (node);
		while (node->left != _end)
			node = node->left;
		return (node);
	}

	NodePtr
	minimum(NodePtr node) const
	{
		if (!node || node == _end)
			return (node);
		while (node->left != _end)
			node = node->left;
		return (node);
	}

	NodePtr 
	maximum(NodePtr node) 
	{
		while (node->right != LEAF_NULL)
		{
		node = node->right;
    	}
    	return (node);
  	}

	
	NodePtr 
	maximum(NodePtr node) const
	{
		while (node->right != LEAF_NULL)
		{
		node = node->right;
    	}
    	return (node);
  	}

	void
	getLeafNULL() { return (this->LEAF_NULL); }

	void
	getRoot() { return (this->_root); }

	NodePtr
	begin() { return (minimum(_root)); }

	NodePtr
	begin() const { return (minimum(_root)); }

	NodePtr
	find(NodePtr node, int key)
	{
		if (node == LEAF_NULL || key == node->data)
			return (node);

		if (key < node->data)
			return find(node->left, key);

		return (find(node->right, key));
	}

	void
	insert(value_type key_value) 
	{
		NodePtr node = _alloc.allocate(1);
		_alloc.construct(node, Node(key_value));

		// NodePtr node = new Node;
		// node->parent = ft::null_ptr;
		// node->data = key;
		// node->left = LEAF_NULL;
		// node->right = LEAF_NULL;
		// node->color = 1;

		NodePtr y = ft::null_ptr;
		NodePtr x = this->_root;

		while (x != LEAF_NULL) {
		y = x;
		if (node->data.first < x->data.first) {
			x = x->left;
		} else {
			x = x->right;
		}
		}

		node->parent = y;
		if (y == ft::null_ptr) {
		_root = node;
		} else if (node->data.first < y->data.first) {				// < ok ou utiliser _comp ?
		y->left = node;
		} else {
		y->right = node;
		}

		if (node->parent == ft::null_ptr) {
		node->color = 0;
		return;
		}

		if (node->parent->parent == ft::null_ptr)
			return;
		insertFix(node);
  	}

	void
	insertFix(NodePtr k)
	{
		NodePtr u;
		while (k->parent->color == 1)
		{
			if (k->parent == k->parent->parent->right) {
			u = k->parent->parent->left;
			if (u->color == 1) {
				u->color = 0;
				k->parent->color = 0;
				k->parent->parent->color = 1;
				k = k->parent->parent;
			} else {
				if (k == k->parent->left) {
				k = k->parent;
				rightRotate(k);
				}
				k->parent->color = 0;
				k->parent->parent->color = 1;
				leftRotate(k->parent->parent);
			}
			} else {
			u = k->parent->parent->right;

			if (u->color == 1) {
				u->color = 0;
				k->parent->color = 0;
				k->parent->parent->color = 1;
				k = k->parent->parent;
			} else {
				if (k == k->parent->right) {
				k = k->parent;
				leftRotate(k);
				}
				k->parent->color = 0;
				k->parent->parent->color = 1;
				rightRotate(k->parent->parent);
			}
			}
			if (k == _root) {
			break;
			}
		}
		_root->color = 0;
	}

	void
	deleteNode(int data)
	{
    	deleteNodeHelper(this->_root, data);
	}

	void deleteNodeHelper(NodePtr node, int key)
	{
		NodePtr z = LEAF_NULL;
		NodePtr x, y;
		// Searching the node to delete
		while (node != LEAF_NULL)
		{
			if (node->data == key) {
				z = node;
			}

			if (node->data <= key)
				node = node->right;
			else
				node = node->left;
		}

		// The searched node is not in the tree
		if (z == LEAF_NULL)
		{
			std::cout << "Key not found in the tree" << std::endl;
			return;
		}

		y = z;
		int y_original_color = y->color;
		if (z->left == LEAF_NULL)
		{
			x = z->right;
			rbTransplant(z, z->right);
		}
		else if (z->right == LEAF_NULL)
		{
			x = z->left;
			rbTransplant(z, z->left);
		}
		else
		{
			y = minimum(z->right);
			y_original_color = y->color;
			x = y->right;
			if (y->parent == z)
				x->parent = y;
			else 
			{
				rbTransplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}
			rbTransplant(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		delete z;
		if (y_original_color == 0)
			deleteFix(x);
	}


	/* REEQUILIBRAGE */

	void leftRotate(NodePtr x) 
	{
		NodePtr y = x->right;
		x->right = y->left;
		if (y->left != LEAF_NULL) {
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == ft::null_ptr) {
			this->_root = y;
		} else if (x == x->parent->left) {
			x->parent->left = y;
		} else {
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}

	void rightRotate(NodePtr x) 
	{
		NodePtr y = x->left;
		x->left = y->right;
		if (y->right != LEAF_NULL) {
			y->right->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == ft::null_ptr) {
			this->_root = y;
		} else if (x == x->parent->right) {
			x->parent->right = y;
		} else {
			x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}

	void rbTransplant(NodePtr u, NodePtr v)
	{
		if (u->parent == ft::null_ptr)
			_root = v;
		else if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
		v->parent = u->parent;
  	}
	};
};









#endif