#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>
#include <vector>

class vect2 {
private:
    std::vector<int> _container;

public:
    // Constructors
    vect2() : _container(2, 0) {}
    vect2(int v1, int v2) : _container{v1, v2} {}
    vect2(const vect2& original) : _container(original._container) {}
    ~vect2() = default;
    
    // Assignment operator
    vect2& operator=(const vect2& other) {
        if (this != &other) {
            _container = other._container;
        }
        return *this;
    }
    
    // Accessor
    int getContainer_elements(int index) const { return _container[index]; }
    
    // Arithmetic operators
    vect2 operator+(int add) const;
    vect2 operator+(const vect2& addon) const;
    vect2 operator-(int minus) const;
    vect2 operator-(const vect2& minuson) const;
    vect2 operator*(int multi) const;
    vect2 operator*(const vect2& multion) const;
    
    // Increment/Decrement operators
    vect2& operator++() { ++_container[0]; ++_container[1]; return *this; }
    vect2 operator++(int);
    vect2& operator--() { --_container[0]; --_container[1]; return *this; }
    vect2 operator--(int);
    
    // Compound assignment operators
    vect2& operator+=(int add) { _container[0] += add; _container[1] += add; return *this; }
    vect2& operator+=(const vect2& addon);
    vect2& operator-=(int minus) { _container[0] -= minus; _container[1] -= minus; return *this; }
    vect2& operator-=(const vect2& minuson);
    vect2& operator*=(int multi) { _container[0] *= multi; _container[1] *= multi; return *this; }
    vect2& operator*=(const vect2& multion);
    
    // Comparison operators
    bool operator==(const vect2& other) const {
        return _container[0] == other._container[0] && _container[1] == other._container[1];
    }
    bool operator!=(const vect2& other) const { return !(*this == other); }
    
    // Friend function for scalar multiplication
    friend vect2 operator*(int number, const vect2& vector) { return vector * number; }
    friend std::ostream& operator<<(std::ostream& out, const vect2& v) {
        out << "{" << v._container[0] << ", " << v._container[1] << "}";
        return out;
    }
};

#endif // VECT2_HPP 