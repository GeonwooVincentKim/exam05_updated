#pragma once
#include "searchable_bag.hpp"
#include "tree_bag.hpp"
class searchable_tree_bag : public searchable_bag, public tree_bag {
public:
    searchable_tree_bag() : tree_bag() {}
    searchable_tree_bag(const searchable_tree_bag& other) : tree_bag(other) {}
    searchable_tree_bag& operator=(const searchable_tree_bag& other) {
        if (this != &other) tree_bag::operator=(other);
        return *this;
    }
    bool has(int item) const {
        node* current = tree;
        while (current) {
            if (item == current->value) return true;
            current = (item > current->value) ? current->r : current->l;
        }
        return false;
    }
}; 