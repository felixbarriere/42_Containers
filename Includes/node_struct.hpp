#ifndef NODE_HPP
# define NODE_HPP

# include "null_ptr.hpp"

namespace ft
{

    #define BLACK 0
    #define RED 1

    template <typename value_type>
    struct Node
    {
    // public:

        /* member types */
        value_type		data;
        size_t			color;
        // int         key;
        Node*			left;
        Node*			right;
        Node*			parent;
        // Node*			node_ptr; 

        // node*			right;
        // node*			parent;

        /* constructors */
        Node () : data(), color (BLACK), left(ft::null_ptr), right(ft::null_ptr),
                                        parent(ft::null_ptr)  //, node_ptr(ft::null_ptr)
        {}

		Node (const value_type  &data2) : data(data2), color (RED), left(ft::null_ptr), right(ft::null_ptr),
                                        parent(ft::null_ptr)  //, node_ptr(ft::null_ptr)
		{}

        Node (const value_type  &data2, Node *ptr_left, Node *ptr_right)
                        : data(data2), color (RED), left(ptr_left), right(ptr_right),
                                        parent(ft::null_ptr)  //, node_ptr(ft::null_ptr)
		{}

    };
};

#endif


