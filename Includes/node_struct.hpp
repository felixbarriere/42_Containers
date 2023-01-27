#ifndef NODE_HPP
# define NODE_HPP

# include "null_ptr.hpp"

namespace ft
{
    template <typename value_type>
    class node
    {


        /* member types */
        value_type		key;
        int				color;
        // int         key;
        node*			left;
        node*			right;
        node*			parent;
        node*			node_ptr; 

        // node*			right;
        // node*			parent;

        /* constructors */

		node (value_type  &data2) : key(data2), color (RED), left(ft::null_ptr), right(ft::null_ptr), parent(ft::null_ptr)
		{}

    };
};

#endif