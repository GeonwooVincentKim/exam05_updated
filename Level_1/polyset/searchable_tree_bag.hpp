#pragma once
#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag {
public:
    searchable_tree_bag() : tree_bag() {}
    searchable_tree_bag(const searchable_tree_bag& other) : tree_bag(other) {}
    searchable_tree_bag& operator=(const searchable_tree_bag& other) {
        if (this != &other) {
            tree_bag::operator=(other);
        }
        return *this;
    }
    ~searchable_tree_bag() = default;
    
    void insert(int item) override { tree_bag::insert(item); }
    void insert(int* items, int count) { tree_bag::insert(items, count); }
    void print() const override { tree_bag::print(); }
    void clear() override { tree_bag::clear(); }
    bool has(int item) const override;
}; 