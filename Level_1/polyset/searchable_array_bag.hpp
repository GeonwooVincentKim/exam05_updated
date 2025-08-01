#pragma once
#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag {
public:
    searchable_array_bag() : array_bag() {}
    searchable_array_bag(const searchable_array_bag& other) : array_bag(other) {}
    searchable_array_bag& operator=(const searchable_array_bag& other) {
        if (this != &other) {
            array_bag::operator=(other);
        }
        return *this;
    }
    ~searchable_array_bag() = default;
    
    void insert(int item) override { array_bag::insert(item); }
    void insert(int* items, int count) { array_bag::insert(items, count); }
    void print() const override { array_bag::print(); }
    void clear() override { array_bag::clear(); }
    bool has(int item) const override;
}; 