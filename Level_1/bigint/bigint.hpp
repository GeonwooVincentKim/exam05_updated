#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint {
private:
    std::string value;
    
    void remove_leading_zeros();

public:
    // Constructors
    bigint() : value("0") {}
    bigint(unsigned long long num) : value(std::to_string(num)) {}
    bigint(const bigint& other) : value(other.value) {}
    
    // Assignment operator
    bigint& operator=(const bigint& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }
    
    // Arithmetic operators
    bigint operator+(const bigint& other) const;
    bigint& operator+=(const bigint& other) {
        *this = *this + other;
        return *this;
    }
    
    // Digit shift operators (base 10)
    bigint operator<<(size_t shift) const;
    bigint& operator<<=(size_t shift) {
        value.append(shift, '0');
        return *this;
    }
    bigint operator>>(size_t shift) const;
    bigint& operator>>=(size_t shift) {
        if (shift >= value.length()) {
            value = "0";
        } else {
            value = value.substr(0, value.length() - shift);
        }
        return *this;
    }
    
    // Comparison operators
    bool operator<(const bigint& other) const {
        if (value.length() != other.value.length()) {
            return value.length() < other.value.length();
        }
        return value < other.value;
    }
    bool operator>(const bigint& other) const { return other < *this; }
    bool operator<=(const bigint& other) const { return !(other < *this); }
    bool operator>=(const bigint& other) const { return !(*this < other); }
    bool operator==(const bigint& other) const { return value == other.value; }
    bool operator!=(const bigint& other) const { return !(*this == other); }
    
    // Increment operators
    bigint& operator++() {
        *this += bigint(1);
        return *this;
    }
    bigint operator++(int) {
        bigint temp = *this;
        ++(*this);
        return temp;
    }
    
    // Output operator (no leading zeros)
    friend std::ostream& operator<<(std::ostream& os, const bigint& num) {
        os << num.value;
        return os;
    }
};

#endif // BIGINT_HPP 