
namespace ft
{
    template <typename value_type>
    struct node
    {
        /* constructors */

        /* member types */
        value_type  data;
        int         color;
        int         key;
        node*       left;
        node*       right;
        node*       parent;
    }
};
