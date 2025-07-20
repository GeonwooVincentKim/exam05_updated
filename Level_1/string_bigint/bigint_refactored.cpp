#include "bigint_refactored.hpp"
#include <algorithm>

// Constructor from unsigned int
bigint::bigint(unsigned int n) {
    std::ostringstream oss;
    oss << n;
    value = oss.str();
}

// Helper: Add two string numbers
std::string bigint::add_strings(const std::string& a, const std::string& b) {
    std::string result;
    int carry = 0;
    
    // Make sure a is the longer string
    std::string longer = (a.size() >= b.size()) ? a : b;
    std::string shorter = (a.size() >= b.size()) ? b : a;
    
    int i = longer.length() - 1;
    int j = shorter.length() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int digit1 = i >= 0 ? longer[i] - '0' : 0;
        int digit2 = j >= 0 ? shorter[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        
        result.insert(result.begin(), (sum % 10) + '0');
        carry = sum / 10;
        
        i--;
        j--;
    }
    
    return result;
}

// Helper: Remove leading zeros
std::string bigint::remove_leading_zeros(const std::string& str) {
    size_t start = str.find_first_not_of('0');
    if (start == std::string::npos) return "0";
    return str.substr(start);
}

// Arithmetic operators
bigint bigint::operator+(const bigint& other) const {
    return bigint(add_strings(value, other.value));
}

bigint& bigint::operator+=(const bigint& other) {
    value = add_strings(value, other.value);
    return *this;
}

// Increment operators
bigint& bigint::operator++() {
    *this += bigint(1);
    return *this;
}

bigint bigint::operator++(int) {
    bigint temp = *this;
    ++(*this);
    return temp;
}

// Bit shift operators
bigint bigint::operator<<(unsigned int shift) const {
    if (value == "0") return *this;
    
    bigint result = *this;
    result.value.append(shift, '0');
    return result;
}

bigint& bigint::operator<<=(unsigned int shift) {
    if (value == "0") return *this;
    
    value.append(shift, '0');
    return *this;
}

bigint& bigint::operator>>=(const bigint& other) {
    if (value == "0") return *this;
    
    std::stringstream ss(other.value);
    size_t shift;
    ss >> shift;
    
    if (value.size() > shift) {
        value.erase(value.begin() + (value.size() - shift), value.end());
    } else {
        value = "0";
    }
    
    return *this;
}

// Comparison operators
bool bigint::operator>(const bigint& other) const {
    if (value.size() != other.value.size()) {
        return value.size() > other.value.size();
    }
    return value > other.value;
}

bool bigint::operator<(const bigint& other) const {
    if (value.size() != other.value.size()) {
        return value.size() < other.value.size();
    }
    return value < other.value;
}

bool bigint::operator==(const bigint& other) const {
    return value == other.value;
}

bool bigint::operator!=(const bigint& other) const {
    return value != other.value;
}

bool bigint::operator<=(const bigint& other) const {
    return (*this < other) || (*this == other);
}

bool bigint::operator>=(const bigint& other) const {
    return (*this > other) || (*this == other);
}

// Output operator
std::ostream& operator<<(std::ostream& out, const bigint& num) {
    out << num.value;
    return out;
} 