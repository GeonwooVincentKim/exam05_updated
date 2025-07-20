#pragma once
#include "bag.hpp"
class tree_bag : virtual public bag {
protected:
    struct node {
        node *l, *r;
        int value;
        node(int v) : l(nullptr), r(nullptr), value(v) {}
    };
    node* tree;
public:
    tree_bag();
    tree_bag(const tree_bag&);
    tree_bag& operator=(const tree_bag&);
    ~tree_bag();
    void insert(int);
    void insert(int*, int);
    void print() const;
    void clear();
private:
    static void destroy_tree(node*);
    static void print_node(node*);
    static node* copy_node(node*);
}; 