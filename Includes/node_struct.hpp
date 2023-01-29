#ifndef NODE_HPP
# define NODE_HPP

# include "null_ptr.hpp"

namespace ft
{
    template <typename value_type>
    class node
    {
    public:

        /* member types */
        value_type		data;
        int				color;
        // int         key;
        node*			left;
        node*			right;
        node*			parent;
        node*			node_ptr; 

        // node*			right;
        // node*			parent;

        /* constructors */
        node () : data(), color (BLACK), left(ft::null_ptr), right(ft::null_ptr),
                                        parent(ft::null_ptr), node_ptr(ft::null_ptr)
        {}

		node (const value_type  &data2) : data(data2), color (RED), left(ft::null_ptr), right(ft::null_ptr),
                                        parent(ft::null_ptr), node_ptr(ft::null_ptr)
		{}

        node (const value_type  &data2, node *ptr_left, node *ptr_right)
                        : data(data2), color (RED), left(ptr_left), right(ptr_right),
                                        parent(ft::null_ptr), node_ptr(ft::null_ptr)
		{}

    };
};

#endif