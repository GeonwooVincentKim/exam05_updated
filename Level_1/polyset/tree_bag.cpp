#include "tree_bag.hpp"
#include <iostream>

tree_bag::tree_bag() : tree(nullptr) {}
tree_bag::tree_bag(const tree_bag& src) { tree = copy_node(src.tree); }
tree_bag& tree_bag::operator=(const tree_bag& src) {
    if (this != &src) { destroy_tree(tree); tree = copy_node(src.tree); }
    return *this;
}
tree_bag::~tree_bag() { destroy_tree(tree); }

void tree_bag::insert(int item) {
    node* new_node = new node(item);
    if (!tree) { tree = new_node; return; }
    
    node* current = tree;
    while (true) {
        if (item < current->value) {
            if (!current->l) { current->l = new_node; break; }
            current = current->l;
        } else if (item > current->value) {
            if (!current->r) { current->r = new_node; break; }
            current = current->r;
        } else { delete new_node; break; }
    }
}

void tree_bag::insert(int* items, int count) {
    for (int i = 0; i < count; i++) insert(items[i]);
}

void tree_bag::print() const { print_node(tree); std::cout << std::endl; }
void tree_bag::clear() { destroy_tree(tree); tree = nullptr; }

void tree_bag::destroy_tree(node* current) {
    if (current) { destroy_tree(current->l); destroy_tree(current->r); delete current; }
}
void tree_bag::print_node(node* current) {
    if (current) { print_node(current->l); std::cout << current->value << " "; print_node(current->r); }
}
tree_bag::node* tree_bag::copy_node(node* current) {
    if (!current) return nullptr;
    node* new_node = new node(current->value);
    new_node->l = copy_node(current->l);
    new_node->r = copy_node(current->r);
    return new_node;
} 