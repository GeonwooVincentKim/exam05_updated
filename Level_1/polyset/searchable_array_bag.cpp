#include "searchable_array_bag.hpp"

bool searchable_array_bag::has(int item) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == item) {
            return true;
        }
    }
    return false;
}