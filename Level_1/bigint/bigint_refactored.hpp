#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

class bigint {
private:
    std::string value;
    
    // Helper methods
    void remove_leading_zeros();
    static std::string add_strings(const std::string& a, const std::string& b);

public:
    // Constructors
    bigint() : value("0") {}
    bigint(const std::string& str);
    bigint(unsigned long long num);
    bigint(const bigint& other) : value(other.value) {}

    // Arithmetic operators
    bigint operator+(const bigint& other) const;
    bigint& operator+=(const bigint& other);
    bigint operator-(const bigint& other) const;

    // Bit shift operators (digit shift)
    bigint operator<<(size_t shift) const;
    bigint& operator<<=(size_t shift);
    bigint operator>>(size_t shift) const;
    bigint& operator>>=(size_t shift);

    // Comparison operators
    bool operator<(const bigint& other) const;
    bool operator>(const bigint& other) const;
    bool operator<=(const bigint& other) const;
    bool operator>=(const bigint& other) const;
    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;

    // Increment operators
    bigint& operator++();
    bigint operator++(int);

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const bigint& num);
};

#endif // BIGINT_HPP 