/** noam sayada
 *  noamsayada1@gmail.com
 */

#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <iostream>
#include "Node.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <sstream>

template <typename T, int K = 2>
class Tree
{
private:
//root of the tree
    Node<T> *root;
//function that draw the tree

  void draw(sf::RenderWindow &window, Node<T> *tem, sf::Font &font, float x, float y, float space, int depth, int result){
        if (!tem)
            return;

        // Draw the tem (circle)
        sf::CircleShape circle(20);
        //put poistion of the circle
         circle.setPosition(x, y);
         //put the color of the circle
        circle.setFillColor(sf::Color::Green);
      //put the value of the node
        std::stringstream ss;
        ss << std::fixed << tem->getValue();
        std::string st_text = ss.str();

        sf::Text t;
        //put font 
        t.setFont(font);
        //put text
        t.setString(st_text);
        //put size of the text of the value
        t.setCharacterSize(15);
        //put color of the text 
        t.setFillColor(sf::Color::Black);
        //declare bounds
        sf::FloatRect fl = t.getLocalBounds();
        t.setOrigin(fl.left + fl.width / 2.0f,
                       fl.top + fl.height / 2.0f);
        //put poistion 
        t.setPosition(x + circle.getRadius(), y + circle.getRadius());
//draw circle
        window.draw(circle);
        //draw text of the node
        window.draw(t);
//pass to the childrens of the node
        const std::vector<Node<T> *> &c = tem->get_children();
        for (size_t i = 0; i < c.size(); ++i){
            float right = x + (i - (c.size() - 1) / 2.0) * space;
            float left = y + 600.0 / (result + 1);
//position of the lines for the childrens of the node
            sf::Vertex line[] =
                {
                    sf::Vertex(sf::Vector2f(x + 20, y + 20), sf::Color::Green),
                    sf::Vertex(sf::Vector2f(right + 20, left), sf::Color::Green)};
//draw the line of the childrens
            window.draw(line, 2, sf::Lines);
            
            draw(window, c[i], font, right, left,  space / 2, depth + 1, result);
        }
    }

//compute the depth of the tree
    int depth_of_tree(Node<T> *tem){
        if (!tem)
            return 0;
        int result = 0;
        for (Node<T> *c : tem->get_children()){
            int depth = depth_of_tree(c);
            if (depth > result)
                result = depth;
        }
        return result + 1;
    }

public:
//constractor
    Tree() : root(nullptr) {}
    //destractor
    ~Tree() {}
    //add root
    void add_root(Node<T> &tem){
        root = &tem;
    }
    //add sub node
    void add_sub_node(Node<T> &parent, Node<T> &c){
        if (parent.get_size() < K) {
            parent.add_child(&c); 
        }
        else{
            throw std::invalid_argument("Error in number of children.");
        }
    }
    //get root of the tree
    Node<T> *get_root() const{
        return root;
    }
  
//class preorder
    class PreOrderIterator
    {
    private:
        std::stack<Node<T> *> stack;

    public:
        PreOrderIterator(Node<T> *root){
            if (root)
                stack.push(root);
        }
const PreOrderIterator &operator++(){
            if (stack.empty()){
                return *this;
            }

            Node<T> *tem = stack.top();
            stack.pop();
            for (auto it = tem->get_children().rbegin(); it != tem->get_children().rend(); ++it){
                stack.push(*it);
            }
            return *this;
        }
        
        
        bool operator!=(const PreOrderIterator &other) const{
            return !(*this == other);
        }



        bool operator==(const PreOrderIterator &other) const{
            return stack == other.stack;
        }

      

        Node<T> *operator*() const{
            if (stack.empty()){
                throw std::invalid_argument("empty");
            }
            return stack.top();
        }
    };
    //begin
    auto begin_pre_order() const{
        if constexpr (K == 2) {
            return PreOrderIterator(root);
        }
        else{
            return DFSIterator(root); 
        }
    }
//end
    auto end_pre_order() const{
        if constexpr (K == 2) {
            return PreOrderIterator(nullptr);
        }
        else{
            return DFSIterator(nullptr); 
        }
    }

  
//class bfs iterator
    class BFSIterator
    {
    private:
        std::queue<Node<T> *> que;

    public:
        BFSIterator(Node<T> *root){
            if (root){
                que.push(root);
            }
        }

    
        const BFSIterator &operator++() {
            if (!que.empty()){
                Node<T> *tem = que.front();
                que.pop();
                for (Node<T> *c : tem->get_children()){
                    que.push(c);
                }
            }
            return *this;
        }

  bool operator!=(const BFSIterator &other) const{
            return !que.empty();
        }
        
        Node<T> *operator*() const{
            if (que.empty()) {
                throw std::invalid_argument("error");
            }
            return que.front();
        }
    };
//begim
    BFSIterator begin() const{
        return begin_bfs_scan();
    }
//end
    BFSIterator end() const{
        return end_bfs_scan();
    }
    //begin bfs scan
    BFSIterator begin_bfs_scan() const{
        return BFSIterator(root);
    }
//end bfs scan
    BFSIterator end_bfs_scan() const{
        return BFSIterator(nullptr); 
    }


//class postorder
    class PostOrderIterator
    {
    private:
        std::stack<Node<T> *> stack1; 
        std::stack<Node<T> *> stack2;  

    public:
        PostOrderIterator(Node<T> *root){
            if (root){
                stack1.push(root);
                while (!stack1.empty()) {
                    Node<T> *tem = stack1.top();
                    stack1.pop();
                    stack2.push(tem);
                    const auto &c = tem->get_children();
                    for (Node<T> *c : c){
                        stack1.push(c);
                    }
                }
            }
        }


   const PostOrderIterator &operator++(){
            if (!stack2.empty()){
                stack2.pop();
            }
            return *this;
        }
        
        
        bool operator!=(const PostOrderIterator &other) const {
            return !stack2.empty();
        }

     

        Node<T> *operator*() const{
            if (stack2.empty()){
                throw std::invalid_argument("error");
            }
            return stack2.top();
        }
    };

//begin
    auto begin_post_order() const {
        if constexpr (K == 2) {
            return PostOrderIterator(root);
        }
        else{
            return DFSIterator(root);
        }
    }
//end
    auto end_post_order() const{
        if constexpr (K == 2){
            return PostOrderIterator(nullptr);
        }
        else{
            return DFSIterator(nullptr);
        }
    }
   
   
 //class dfs  
    class DFSIterator
    {
    private:
        std::stack<Node<T> *> stack; 

    public:

        DFSIterator(Node<T> *root){
            if (root){
                stack.push(root);
            }
        }

      const DFSIterator &operator++(){
            if (!stack.empty()){
                Node<T> *tem = stack.top();
                stack.pop();
                for (auto it = tem->get_children().rbegin(); it != tem->get_children().rend(); ++it)
                {
                    stack.push(*it);
                }
            }
            return *this;
        }
        bool operator!=(const DFSIterator &other) const{
            return !stack.empty();
        }



        Node<T> *operator*() const{
            if (stack.empty()){
                throw std::invalid_argument("error");
            }
            return stack.top();
        }
    };
//begin
    DFSIterator begin_dfs_scan() const{
        return DFSIterator(root);
    }
//end
    DFSIterator end_dfs_scan() const{
         return DFSIterator(nullptr); 
    }
    
      


  //inorder
     class InOrderIterator
    {
    private:
        std::stack<Node<T> *> stack; 
        Node<T> *curr;           

        void pushLeftmost(Node<T> *tem){
            while (tem) {
                stack.push(tem);
                if (!tem->get_children().empty()){
                    tem = tem->get_children().front(); 
                }
                else{
                    break;
                }
            }
        }

    public:
        InOrderIterator(Node<T> *root) : curr(root){
            pushLeftmost(root);
        }

       
        bool operator!=(const InOrderIterator &other) const{
            return !stack.empty();
        }

    
        const InOrderIterator &operator++() {
            if (!stack.empty()){
                Node<T> *t = stack.top();
                stack.pop();
                const auto &c = t->get_children();
                if (c.size() > 1){
                    pushLeftmost(c[1]);
                }
            }
            return *this;
        }

        Node<T> *operator*() const{
            if (stack.empty()){
                throw std::invalid_argument("error");
            }
            return stack.top();
        }
    };

 //begin
    auto begin_in_order() const{
        if constexpr (K == 2){
            return InOrderIterator(root);
        }
        else{
            return DFSIterator(root);
        }
    }

  //end
    auto end_in_order() const{
        if constexpr (K == 2){
            return InOrderIterator(nullptr); 
        }
        else{
            return DFSIterator(nullptr);
        }
    }
  //class heap   
    class HeapIterator
{
private:
    std::vector<Node<T> *> heap;
    size_t in;

public:
    HeapIterator(Node<T> *root) : in(0){
        if (root){
            help_heap(root);
        }
    }
    void help_heap(Node<T> *root){
        std::queue<Node<T> *> que;
        if (root){
            que.push(root);
        }
        while (!que.empty())
        {
            Node<T> *tem = que.front();
            que.pop();
            heap.push_back(tem);
            for (Node<T> *c : tem->get_children())
            {
                que.push(c);
            }
        }
        std::make_heap(heap.begin(), heap.end(), [](Node<T> *a, Node<T> *b) {
            return a->getValue() > b->getValue();
        });
    }

   bool operator!=(const HeapIterator &other) const{
    return in != other.in;
}

    int get_size(){
        return heap.size();
    }

    void change(int index){
        in = index;
    }

    const HeapIterator &operator++(){
        if (in < heap.size()){
            ++in;
        }
    return *this;
    }

Node<T> *operator*() const{
    if (heap.empty() || in >= heap.size()){
        throw std::invalid_argument("error");
    }
    return heap[in];
}
};



HeapIterator run_heap(){
    if (K == 2){
        if (!root) {
            throw std::logic_error("error");
        }
        std::vector<Node<T> *> vec;
        std::queue<Node<T> *> q;
        q.push(root);

        while (!q.empty()){
            Node<T> *tem = q.front();
            q.pop();
            vec.push_back(tem);
            for (Node<T> *c : tem->get_children()){q.push(c);}
        }
        std::make_heap(vec.begin(), vec.end(), [](Node<T> *a, Node<T> *b) {
            return a->getValue() > b->getValue();
        });
        for (size_t i = 0; i < vec.size(); ++i){
            size_t index1 = 2 * i + 1;
            size_t index2 = 2 * i + 2;

            vec[i]->modif_vec();
            if (index1 < vec.size()){
                vec[i]->add_child(vec[index1]);
            }
            if (index2 < vec.size()){
                vec[i]->add_child(vec[index2]);
            }
        }

        root = vec.empty() ? nullptr : vec.front();
    }
    else{
        throw std::logic_error("k!=2 error");
    }
    return HeapIterator(root);
}

    HeapIterator begin_heap(){
        return HeapIterator(root);
    }

HeapIterator end_heap(){
    HeapIterator it(root);
    it.change(it.get_size()); 
    return it;
}
//visualize the tree
    void visualize()
    {
        sf::RenderWindow window(sf::VideoMode(1400, 900), "Tree draw ");
        sf::Font font;
        if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")){
            std::cerr << "Error load font" << std::endl;
            return;
        }

        while (window.isOpen()){
            sf::Event event;
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear(sf::Color::White);
            int result = depth_of_tree(root);
            draw(window, root, font, window.getSize().x / 2, 20, window.getSize().x / 4, 0, result);
            window.display();
        }
    }
};

#endif
