#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "node_struct.hpp"
# include "null_ptr.hpp"

namespace ft
{

	template <typename T, class Compare, typename Node = ft::Node<T>,
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
	    typedef typename Allocator::pointer		    NodePtr;                          

    /* ****************************************************************************************** */
	/****************************************** MEMBER DATAS **************************************/

	private:
		value_compare	_comp;
		allocator_type	_alloc;
		// NodePtr			_end;
		NodePtr			_root;
		NodePtr			LEAF_NULL;

    /* ****************************************************************************************** */
	/****************************************** CONSTRUCTORS / DESTRUCTORS ************************/

	public:
	RBT(const value_compare &comp = value_compare())
			: _comp(comp), _alloc(allocator_type()) //, _root(_end) //_end(_alloc.allocate(1)),
	{
		this->LEAF_NULL = _alloc.allocate(1);
		_alloc.construct(LEAF_NULL, Node(value_type()));	

		// LEAF_NULL->parent = ft::null_ptr;
		// LEAF_NULL->right = ft::null_ptr;
		// LEAF_NULL->left = ft::null_ptr;
		// LEAF_NULL->color = BLACK;

		this->_root = LEAF_NULL;
	}

	~RBT()
	{
		// _alloc.destroy(LEAF_NULL);
		// _alloc.deallocate(_end, 1);
		// _alloc.deallocate(_root, 1);

	}

    /* ****************************************************************************************** */
	/****************************************** MEMBER FUNCTIONS **********************************/

	// void initializeNULLNode(NodePtr node, NodePtr parent)
	// {
	// 	node->key = 0;
	// 	node->parent = parent;
	// 	node->left = ft::null_ptr;
	// 	node->right = ft::null_ptr;
	// 	node->color = 0;
	// }

	size_type max_size() const
	{
		return ( _alloc.max_size() ) ;    //std::allocator<T>::max_size
	}
	
	NodePtr
	minimum(NodePtr node)
	{
		if (!node)
			return (node);
		while (node->left != LEAF_NULL)
			node = node->left;
		return (node);
	}

	NodePtr
	minimum(NodePtr node) const
	{
		if (!node)
			return (node);
		while (node->left != LEAF_NULL)
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



	NodePtr
	getLeafNULL() const { return (this->LEAF_NULL); }

	NodePtr
	getRoot() const { return (this->_root); }

	NodePtr
	begin() { return (minimum(_root)); }

	NodePtr
	begin() const { return (minimum(_root)); }

	NodePtr
	find(const NodePtr node, const value_type& key) const
	{
		// std::cout << "********* FIND RBT ***********" << std::endl;
		// std::cout << "node->data.second =" << node->data.second << std::endl;
		// std::cout << "key.second =" << key.second << std::endl;

		if (node == LEAF_NULL)
			return (LEAF_NULL);
		else if (_comp(key, node->data))
			return find(node->left, key);
		else if(_comp(node->data, key))
			return (find(node->right, key));
		return (node);
	}

	/****************************************** INSERT **********************************/
	NodePtr
	insert(value_type key_value) 
	{
		NodePtr node = _alloc.allocate(1);
		_alloc.construct(node, Node(key_value, LEAF_NULL, LEAF_NULL));

		NodePtr y = ft::null_ptr;
		NodePtr x = this->_root;

		// check where to insert the node
		while (x != LEAF_NULL)
		{
			// std::cout << "************* ICI2 ***************" << std::endl;
			y = x;
			if (_comp(node->data, x->data))
			{
				// std::cout << "*************** ICI4 **************" << std::endl;

				x = x->left;
			}
			else if (_comp(x->data, node->data))
			{
				// std::cout << "************* ICI5 *****************" << std::endl;

				x = x->right;
			}
			else 
			{
				// std::cout << "************** ICI3 **************" << std::endl;
				_alloc.destroy(node);
				_alloc.deallocate(node, 1);
				return (ft::null_ptr);
			}
		}

		// std::cout << "************* INSERT RBT ***************" << std::endl;

		// insert node
		node->parent = y;
		if (y == ft::null_ptr)
			_root = node;
		else if (_comp(node->data, y->data))  // < ok ou utiliser _comp ?
			y->left = node;
		else
			y->right = node;

		// std::cout << "************* INSERT RBT2 ***************" << std::endl;

		// change color if needed
		if (node->parent == ft::null_ptr)
		{
			node->color = BLACK;

			// std::cout << "node->data.second =" << node->data.second << std::endl;

			return (node);
		}

		// std::cout << "************* INSERT RBT3 ***************" << std::endl;


		if (node->parent->parent == ft::null_ptr)
			return (node);
		insertFix(node);
		
		// std::cout << "node->data.second =" << node->data.second << std::endl;

		return (node);
  	}

	/****************************************** DELETE **********************************/

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

	void
	delete_tree(NodePtr node)
	{
		_root = LEAF_NULL;
		if (node == LEAF_NULL)
			return ;
		delete_tree(node->left);
		delete_tree(node->right);

		_alloc.destroy(node);
		_alloc.deallocate(node, 1);
	}

	void
	delete_LEAF_NULL()
	{
		_alloc.destroy(LEAF_NULL);
		_alloc.deallocate(LEAF_NULL, 1);
	}

	/****************************************** REEQUILIBRAGE **********************************/


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

	void
	insertFix(NodePtr k)
	{
		NodePtr u;
		while (k->parent->color == RED)
		{
			if (k->parent == k->parent->parent->right) {
			u = k->parent->parent->left;
			if (u->color == RED) {
				u->color = BLACK;
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				k = k->parent->parent;
			} else {
				if (k == k->parent->left) {
				k = k->parent;
				rightRotate(k);
				}
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				leftRotate(k->parent->parent);
			}
			} else {
			u = k->parent->parent->right;

			if (u->color == RED) {
				u->color = BLACK;
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				k = k->parent->parent;
			} else {
				if (k == k->parent->right) {
				k = k->parent;
				leftRotate(k);
				}
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				rightRotate(k->parent->parent);
			}
			}
			if (k == _root) {
			break;
			}
		}
		_root->color = BLACK;
	}

	};
};

#endif