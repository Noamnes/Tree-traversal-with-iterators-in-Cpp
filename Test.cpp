/** noam sayada
 *  noamsayada1@gmail.com
 */
#include "Tree.hpp"
#include "Node.hpp"
#include "doctest.h"
#include "Complex.hpp"
#include <string>
using namespace std;

TEST_CASE("Test with double")
{
   // binary tree of doubles
        Node<double> node_string(1.1); 
        Tree<double> tree1;           
        tree1.add_root(node_string);
        Node<double> n1(1.2);
        Node<double> n2(1.3);
        Node<double> n3(1.4);
        Node<double> n4(1.5);
        Node<double> n5(1.6);
        tree1.add_sub_node(node_string, n1);
        tree1.add_sub_node(node_string, n2);
        tree1.add_sub_node(n1, n3);
        tree1.add_sub_node(n1, n4);
        tree1.add_sub_node(n2, n5);
        // The tree should look like:
        /**
         *       root = 1.1
         *     /       \
         *    1.2      1.3
         *   /  \      /
         *  1.4  1.5  1.6
         */
        CHECK(tree1.get_root()->get_children().at(0)->getValue() == n1.getValue());// V
        CHECK(n1.get_children().at(0)->getValue() == n3.getValue()); // V
        CHECK(n2.get_children().at(0)->getValue() == n5.getValue()); // V
        Node<double> n6(1.7);
        CHECK_THROWS_WITH(tree1.add_sub_node(n1, n6), "Error in number of children."); // V

      
            std::vector<double> ans1 = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
            auto it1 = ans1.begin();
            for (auto node = tree1.begin_pre_order(); node != tree1.end_pre_order(); ++node)
            {
                CHECK((*node)->getValue() == *it1++);
            }
    

            std::vector<double> ans2 = {1.4, 1.5, 1.2, 1.6, 1.3, 1.1};
            auto it2 = ans2.begin();
            for (auto node = tree1.begin_post_order(); node != tree1.end_post_order(); ++node)
            {
                CHECK((*node)->getValue() == *it2++);
            }
            

            std::vector<double> ans3 = {1.4, 1.2, 1.5, 1.1, 1.6, 1.3};
            auto it3 = ans3.begin();
            for (auto node = tree1.begin_in_order(); node != tree1.end_in_order(); ++node)
            {
                CHECK((*node)->getValue() == *it3++);
            }


            std::vector<double> ans4 = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
            auto it4 = ans4.begin();
            for (auto node = tree1.begin_bfs_scan(); node != tree1.end_bfs_scan(); ++node)
            {
                CHECK((*node)->getValue() == *it4++);
            }

            
            std::vector<double> ans5 = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
            auto it5 = ans5.begin();
            for (auto node = tree1.begin_dfs_scan(); node != tree1.end_dfs_scan(); ++node)
            {
                CHECK((*node)->getValue() == *it5++);
            }
        
   
}

TEST_CASE("Tree with complex")
{
        Node<Complex> node_complex(Complex(1, 1)); 
        Tree<Complex> tree1;                    
        tree1.add_root(node_complex);
        Node<Complex> n1(Complex(2, 2));
        Node<Complex> n2(Complex(3, 3));
        Node<Complex> n3(Complex(4, 4));
        Node<Complex> n4(Complex(5, 5));
        Node<Complex> n5(Complex(6, 6));

        tree1.add_sub_node(node_complex, n1);
        tree1.add_sub_node(node_complex, n2);
        tree1.add_sub_node(n1, n3);
        tree1.add_sub_node(n1, n4);
        tree1.add_sub_node(n2, n5);

        /**
         *       root = 1,1
         *     /       \
         *    2,2      3,3
         *   /  \      /
         *  4,4  5,5  6,6
         */

        CHECK(tree1.get_root()->get_children().at(0)->getValue() == n1.getValue()); // V
        CHECK(n2.get_children().at(0)->getValue() == n5.getValue()); //V
            std::vector<Complex> ans = {Complex(1, 1), Complex(2, 2), Complex(4, 4), Complex(5, 5), Complex(3, 3), Complex(6, 6)};
            auto it = ans.begin();
            for (auto node = tree1.begin_pre_order(); node != tree1.end_pre_order(); ++node)
            {
                CHECK((*node)->getValue() == *it++);
            }
        

            std::vector<Complex> ans1 = {Complex(4, 4), Complex(5, 5), Complex(2, 2), Complex(6, 6), Complex(3, 3), Complex(1, 1)};
            auto it1 = ans1.begin();
            for (auto node = tree1.begin_post_order(); node != tree1.end_post_order(); ++node)
            {
                CHECK((*node)->getValue() == *it1++);
            }
        

  
            std::vector<Complex> ans2 = {Complex(4, 4), Complex(2, 2), Complex(5, 5), Complex(1, 1), Complex(6, 6), Complex(3, 3)};
            auto it2 = ans2.begin();
            for (auto node = tree1.begin_in_order(); node != tree1.end_in_order(); ++node)
            {
                CHECK((*node)->getValue() == *it2++);
            }
        

            std::vector<Complex> ans3 = {Complex(1, 1), Complex(2, 2), Complex(3, 3), Complex(4, 4), Complex(5, 5), Complex(6, 6)};
            auto it3 = ans3.begin();
            for (auto node = tree1.begin_bfs_scan(); node != tree1.end_bfs_scan(); ++node)
            {
                CHECK((*node)->getValue() == *it3++);
            }
        


            std::vector<Complex> ans4 = {Complex(1, 1), Complex(2, 2), Complex(4, 4), Complex(5, 5), Complex(3, 3), Complex(6, 6)};
            auto it4 = ans4.begin();
            for (auto node = tree1.begin_dfs_scan(); node != tree1.end_dfs_scan(); ++node)
            {
                CHECK((*node)->getValue() == *it4++);
            }
 
}

TEST_CASE("Tree with String"){
   
        Node<string> node_string("a"); 
        Tree<string> tree1;         
        tree1.add_root(node_string);
        Node<string> n1("b");
        Node<string> n2("c");
        Node<string> n3("d");
        Node<string> n4("e");
        Node<string> n5("f");

        tree1.add_sub_node(node_string, n1);
        tree1.add_sub_node(node_string, n2);
        tree1.add_sub_node(n1, n3);
        tree1.add_sub_node(n1, n4);
        tree1.add_sub_node(n2, n5);
        CHECK(tree1.get_root()->get_children().at(0)->getValue() == n1.getValue());
        CHECK(n2.get_children().at(0)->getValue() == n5.getValue());

        Node<string> n6("g");
        CHECK_THROWS_WITH(tree1.add_sub_node(n1, n6), "Error in number of children.");

            std::vector<string> ans = {"a", "b", "d", "e", "c", "f"};
            auto it = ans.begin();
            for (auto node = tree1.begin_pre_order(); node != tree1.end_pre_order(); ++node){
                CHECK((*node)->getValue() == *it++);
            }

            std::vector<string> ans1 = {"d", "e", "b", "f", "c", "a"};
            auto it1 = ans1.begin();
            for (auto node = tree1.begin_post_order(); node != tree1.end_post_order(); ++node){
                CHECK((*node)->getValue() == *it1++);
            }
 
            std::vector<string> ans2 = {"d", "b", "e", "a", "f", "c"};
            auto it2 = ans2.begin();
            for (auto node = tree1.begin_in_order(); node != tree1.end_in_order(); ++node){
                CHECK((*node)->getValue() == *it2++);
            }
        
        
       
            std::vector<string> ans4 = {"a", "b", "d", "e", "c", "f"};
            auto it4 = ans4.begin();
            for (auto node = tree1.begin_dfs_scan(); node != tree1.end_dfs_scan(); ++node){
                CHECK((*node)->getValue() == *it4++);
            }
        
  
            tree1.run_heap();
             std::vector<string> ans5 = {"a", "b", "c", "d", "e", "f"};
             auto it5 = ans5.begin();
             auto node = tree1.begin_heap();
            for (node = tree1.begin_heap(); node != tree1.end_heap(); ++node){
                 CHECK((*node)->getValue() == *it5++);
             }
        
}

TEST_CASE("Tree with 3- children"){
    
        Node<string> node_string("a"); 
        Tree<string, 3> tree1;        
        tree1.add_root(node_string);
        Node<string> n1("b");
        Node<string> n2("c");
        Node<string> n3("d");
        Node<string> n4("e");
        Node<string> n5("f");

        tree1.add_sub_node(node_string, n1);
        tree1.add_sub_node(node_string, n2);
        tree1.add_sub_node(node_string, n3);
        tree1.add_sub_node(n1, n4);
        tree1.add_sub_node(n2, n5);
        CHECK(tree1.get_root()->get_children().at(0)->getValue() == n1.getValue());
        CHECK(n1.get_children().at(0)->getValue() == n4.getValue());
        CHECK(n2.get_children().at(0)->getValue() == n5.getValue());

            std::vector<string> ans = {"a", "b", "e", "c", "f", "d"};
            auto it = ans.begin();
            for (auto node = tree1.begin_pre_order(); node != tree1.end_pre_order(); ++node)
            {
                CHECK((*node)->getValue() == *it++);
            }

            std::vector<string> ans1 = {"a", "b", "e", "c", "f", "d"};
            auto it1 = ans1.begin();
            for (auto node = tree1.begin_post_order(); node != tree1.end_post_order(); ++node)
            {
                CHECK((*node)->getValue() == *it1++);
            } 
        

  
            std::vector<string> ans4 = {"a", "b", "c", "d", "e", "f"};
            auto it4 = ans4.begin();
            for (auto node = tree1.begin_bfs_scan(); node != tree1.end_bfs_scan(); ++node)
            {
                CHECK((*node)->getValue() == *it4++);
            }
        

      
            std::vector<string> ans5 = {"a", "b", "e", "c", "f", "d"};
            auto it5 = ans5.begin();
            for (auto node = tree1.begin_dfs_scan(); node != tree1.end_dfs_scan(); ++node)
            {
                CHECK((*node)->getValue() == *it5++);
            }
            
         
        
        
        
        
        
}


