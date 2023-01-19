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
        node*			left, right, parent;
        node*			node_ptr; 

        // node*			right;
        // node*			parent;

        /* constructors */

		node (value_type  &data2) : key(data2), color (RED), left(ft::nullptr), right(ft::nullptr), parent(ft::nullptr)
		{}

    };
};

#endif