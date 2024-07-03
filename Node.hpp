/** noam sayada
 *  noamsayada1@gmail.com
 */
#ifndef NODE_HPP
#define NODE_HPP
#include <vector>
#include <iostream>

template <typename T>
class Node
{
private:
//value of the node
    T value;
    //childrens of the node
    std::vector<Node<T> *> children;

public:
//constractor
    Node(T val) : value(val) {}
    //destractor
    ~Node() {}
   //add child
    void add_child(Node<T> *child){
        children.push_back(child);
    }

    //get size (number of children)
    int get_size() const{
        return children.size();
    }
    //get value of the node
    T getValue() const{
        return value;
    }
    //get the vector of childrens
    const std::vector<Node<T> *> &get_children(){
        return children;
    }
    //clear the vector of childrens
    void modif_vec(){
        children.clear();
    }

};

#endif // NODE_HPP
