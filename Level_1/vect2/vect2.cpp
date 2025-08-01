//must support addition, substraction and multiplication!
#include "vect2.hpp"

// Arithmetic operators
vect2 vect2::operator+(int add) const {
    return vect2(_container[0] + add, _container[1] + add);
}

vect2 vect2::operator+(const vect2& addon) const {
    return vect2(_container[0] + addon._container[0], 
                 _container[1] + addon._container[1]);
}

vect2 vect2::operator-(int minus) const {
    return vect2(_container[0] - minus, _container[1] - minus);
}

vect2 vect2::operator-(const vect2& minuson) const {
    return vect2(_container[0] - minuson._container[0], 
                 _container[1] - minuson._container[1]);
}

vect2 vect2::operator*(int multi) const {
    return vect2(_container[0] * multi, _container[1] * multi);
}

vect2 vect2::operator*(const vect2& multion) const {
    return vect2(_container[0] * multion._container[0], 
                 _container[1] * multion._container[1]);
}

// Post-increment/Decrement operators
vect2 vect2::operator++(int) {
    vect2 temp = *this;
    ++(*this);
    return temp;
}

vect2 vect2::operator--(int) {
    vect2 temp = *this;
    --(*this);
    return temp;
}

// Compound assignment operators with vect2
vect2& vect2::operator+=(const vect2& addon) {
    _container[0] += addon._container[0];
    _container[1] += addon._container[1];
    return *this;
}

vect2& vect2::operator-=(const vect2& minuson) {
    _container[0] -= minuson._container[0];
    _container[1] -= minuson._container[1];
    return *this;
}

vect2& vect2::operator*=(const vect2& multion) {
    _container[0] *= multion._container[0];
    _container[1] *= multion._container[1];
    return *this;
} 