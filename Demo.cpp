/** noam sayada
 *  noamsayada1@gmail.com
 */

#include <iostream>
#include <string>
#include "Node.hpp"
#include "Tree.hpp"
#include "Complex.hpp"
using namespace std;

int main()
{
    Node<int> root_node(0);
    Tree<int> tree; 
    tree.add_root(root_node);
    Node<int> n1(1);
    Node<int> n2(2);
    Node<int> n3 (3);
    Node<int> n4(4);
    Node<int> n5(5);
    
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n2, n4);
    tree.add_sub_node(n2, n5);

    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << (*node)->getValue() << " ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << (*node)->getValue() << " ";
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << (*node)->getValue() << " ";
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << (*node)->getValue() << " ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        cout << (*node)->getValue() << " ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << endl;
    for (auto node : tree)
    {
        cout << node->getValue() << " ";
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << endl;
    tree.run_heap();
    for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node)
{
        std::cout << (*node)->getValue() << " ";
    }
    std::cout <<std::endl;

   tree.visualize();
}
