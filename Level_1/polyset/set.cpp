#include "set.hpp"

set::set(searchable_bag& b) : bag(b) {}

set::set(const set& other) : bag(other.bag) {}

set& set::operator=(const set& other) {
    if (this != &other) {
        bag.clear();
    }
    return *this;
}

set::~set() = default;

void set::insert(int item) {
    if (!bag.has(item)) {
        bag.insert(item);
    }
}

void set::insert(int* items, int count) {
    for (int i = 0; i < count; i++) {
        insert(items[i]);
    }
} 