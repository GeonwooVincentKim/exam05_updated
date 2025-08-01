#include "searchable_tree_bag.hpp"

bool searchable_tree_bag::has(int item) const {
    node* current = tree;
    while (current) {
        if (item < current->value) {
            current = current->l;
        } else if (item > current->value) {
            current = current->r;
        } else {
            return true;
        }
    }
    return false;
} 