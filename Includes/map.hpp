/* Red Black Tree:
- Red/Black Property: Every node is colored, either red or black.
- Root Property: The root is black.
- Leaf Property: Every leaf (NIL) is black.
- Red Property: If a red node has children then, the children are always black.
- Depth Property: For each node, any simple path from this node to any of 
    its descendant leaf has the same black-depth (the number of black nodes).
*/


namespace ft
{

    template <typename T>
    class map
    {
    public:
        /* ****************************************************************************************** */
		/****************************************** ALIASES *******************************************/
    
    /* left_rotate */
    /* right_rotate */
    /* insert */
    /* delete */
    
        /* ****************************************************************************************** */
		/****************************************** ALIASES *******************************************/
        explicit
        map (const key_compare& comp = key_compare(),              const allocator_type& alloc = allocator_type());

        template <class InputIterator>
        map (InputIterator first, InputIterator last,       const key_compare& comp = key_compare(),       const allocator_type& alloc = allocator_type()); 

        map (const map& x);
    }




};