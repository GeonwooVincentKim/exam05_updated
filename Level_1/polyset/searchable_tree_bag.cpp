#include "searchable_tree_bag.hpp"

bool searchable_tree_bag::has(int item) const {
    node* current = tree;
    while (current) {
        if (item == current->value) return true;
        current = (item > current->value) ? current->r : current->l;
    }
    return false;
} 