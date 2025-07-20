#ifndef STRING_BIGINT_HPP
#define STRING_BIGINT_HPP

#include <string>
#include <iostream>
#include <sstream>

class bigint {
private:
    std::string value;
    
    // Helper methods
    static std::string add_strings(const std::string& a, const std::string& b);
    static std::string remove_leading_zeros(const std::string& str);

public:
    // Constructors
    bigint() : value("0") {}
    bigint(unsigned int n);
    bigint(const std::string& str) : value(str) {}
    bigint(const bigint& other) : value(other.value) {}
    ~bigint() = default;

    // Getter
    std::string getvalue() const { return value; }

    // Arithmetic operators
    bigint operator+(const bigint& other) const;
    bigint& operator+=(const bigint& other);
    
    // Increment operators
    bigint& operator++();
    bigint operator++(int);
    
    // Bit shift operators (digit shift)
    bigint operator<<(unsigned int shift) const;
    bigint& operator<<=(unsigned int shift);
    bigint& operator>>=(const bigint& other);
    
    // Comparison operators
    bool operator>(const bigint& other) const;
    bool operator<(const bigint& other) const;
    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;
    bool operator<=(const bigint& other) const;
    bool operator>=(const bigint& other) const;
    
    // Output operator
    friend std::ostream& operator<<(std::ostream& out, const bigint& num);
};

#endif // STRING_BIGINT_HPP 