#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

//declaration
indexed_set s;

// The function find_by_order returns an iterator to the element at a given position:
auto x = s.find_by_order(2);

// the function order_of_key returns the position of a given element:
cout << s.order_of_key(7) << "\n";

//If the element does not appear in the set, we get the position that the element would have in the set:
