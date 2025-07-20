#include "array_bag.hpp"
#include <iostream>

array_bag::array_bag() : data(nullptr), size(0) {}
array_bag::array_bag(const array_bag& src) : size(src.size) {
    data = new int[size];
    for (int i = 0; i < size; i++) data[i] = src.data[i];
}
array_bag& array_bag::operator=(const array_bag& src) {
    if (this != &src) {
        delete[] data;
        size = src.size;
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = src.data[i];
    }
    return *this;
}
array_bag::~array_bag() { delete[] data; }

void array_bag::insert(int item) {
    int* new_data = new int[size + 1];
    for (int i = 0; i < size; i++) new_data[i] = data[i];
    new_data[size] = item;
    delete[] data;
    data = new_data;
    size++;
}

void array_bag::insert(int* items, int count) {
    for (int i = 0; i < count; i++) insert(items[i]);
}

void array_bag::print() const {
    for (int i = 0; i < size; i++) std::cout << data[i] << " ";
    std::cout << std::endl;
}

void array_bag::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
} 