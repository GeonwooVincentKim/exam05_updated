#pragma once
#include "searchable_bag.hpp"

class set {
private:
    searchable_bag& bag;

public:
    set(searchable_bag& b);
    set(const set& other);
    set& operator=(const set& other);
    ~set();
    
    void insert(int item);
    void insert(int* items, int count);
    bool has(int item) const;
    void print() const;
    void clear();
    searchable_bag& get_bag();
    const searchable_bag& get_bag() const;
}; 