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
	    typedef typename Node::node_ptr	            node_ptr;                          
		typedef typename Node::color				color;

    /* ****************************************************************************************** */
	/****************************************** MEMBER DATAS **************************************/

	private:
		value_compare	_comp;
		allocator_type	_alloc;
		node_ptr		_end;
		node_ptr		_root;
		node_ptr		LEAF_NULL;
		// size_type		_size;

    /* ****************************************************************************************** */
	/****************************************** CONSTRUCTORS / DESTRUCTORS ************************/

	RBT(const value_compare& comp)
				: _comp(comp), _alloc(allocator_type()), _end(_alloc.allocate(1)), _root(_end)
	{
		this->LEAF_NULL = _alloc.allocate(1);
		_alloc.construct(LEAF_NULL, Node(value_type()), 1);

		LEAF_NULL->parent = ft::null_ptr;
		LEAF_NULL->left = ft::null_ptr;
		LEAF_NULL->right = ft::null_ptr;
		LEAF_NULL->color = BLACK;
		this->_root = LEAF_NULL;

	}

	~RBT() {}

    /* ****************************************************************************************** */
	/****************************************** MEMBER FUNCTIONS **********************************/

	/*  preorder (data, left, right)
		inorder (left, data, right)
		postorder (left, right, data) */

	node_ptr
	min(node_ptr node)
	{
		if (!node || node == _end)
			return (node);
		while (node->left != _end)
			node = node->left;
		return (node);
	}

	node_ptr
	min(node_ptr node) const
	{
		if (!node || node == _end)
			return (node);
		while (node->left != _end)
			node = node->left;
		return (node);
	}

	node_ptr
	begin() { return (minimum(_root)); }

	node_ptr
	begin() const { return (minimum(_root)); }

	node_ptr
	insert (value_type key)
	{
		/* trouver l'emplacement où inserer (left ou right) */
		node_ptr n = _alloc.allocate(1);
		_alloc.construct();
		(void)key;
		/* insertion */

		/* equilibrer l'arbre */
	}


	};




};

#endif