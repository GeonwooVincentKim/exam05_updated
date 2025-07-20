#include "bigint_simple.hpp"
#include <algorithm>

// Core addition algorithm (the only complex part)
bigint bigint::operator+(const bigint& other) const {
    std::string result;
    int carry = 0;
    
    // Work from right to left
    auto i = value.rbegin(), j = other.value.rbegin();
    
    while (i != value.rend() || j != other.value.rend() || carry) {
        int digit1 = (i != value.rend()) ? *i++ - '0' : 0;
        int digit2 = (j != other.value.rend()) ? *j++ - '0' : 0;
        
        int sum = digit1 + digit2 + carry;
        result.insert(result.begin(), (sum % 10) + '0');
        carry = sum / 10;
    }
    
    return bigint(result);
}

// Simple assignment addition
bigint& bigint::operator+=(const bigint& other) {
    *this = *this + other;
    return *this;
}

// Bit shifts (just add/remove zeros)
bigint bigint::operator<<(unsigned int shift) const {
    if (value == "0") return *this;
    return bigint(value + std::string(shift, '0'));
}

bigint& bigint::operator<<=(unsigned int shift) {
    if (value != "0") value += std::string(shift, '0');
    return *this;
}

bigint& bigint::operator>>=(unsigned int shift) {
    if (shift >= value.size()) {
        value = "0";
    } else {
        value = value.substr(0, value.size() - shift);
    }
    return *this;
}

// Comparison (only need to implement <)
bool bigint::operator<(const bigint& other) const {
    if (value.size() != other.value.size()) {
        return value.size() < other.value.size();
    }
    return value < other.value;
}

// Output
std::ostream& operator<<(std::ostream& out, const bigint& num) {
    return out << num.value;
} 