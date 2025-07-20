#include <string>
#include <iostream>

class bigint {
private:
    std::string value;

public:
    // Essential constructors
    bigint() : value("0") {}
    bigint(unsigned int n) : value(std::to_string(n)) {}
    bigint(const std::string& str) : value(str) {}
    bigint(const bigint& other) : value(other.value) {}
    bigint& operator=(const bigint& other) {
        if (this != &other) value = other.value;
        return *this;
    }

    // Core operators (only the most important ones)
    bigint operator+(const bigint& other) const;
    bigint& operator+=(const bigint& other);
    bigint& operator++() { *this += bigint(1); return *this; }
    bigint operator++(int) { bigint temp = *this; ++(*this); return temp; }
    
    // Bit shifts (digit shifts)
    bigint operator<<(unsigned int shift) const;
    bigint& operator<<=(unsigned int shift);
    bigint& operator>>=(unsigned int shift);
    
    // Comparison (only < and ==, others derived)
    bool operator<(const bigint& other) const;
    bool operator==(const bigint& other) const { return value == other.value; }
    bool operator!=(const bigint& other) const { return !(*this == other); }
    bool operator>(const bigint& other) const { return other < *this; }
    bool operator<=(const bigint& other) const { return *this < other || *this == other; }
    bool operator>=(const bigint& other) const { return *this > other || *this == other; }

    // Output
    friend std::ostream& operator<<(std::ostream& out, const bigint& num);
};
