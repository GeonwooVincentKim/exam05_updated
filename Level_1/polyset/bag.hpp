#pragma once
class bag {
public:
    virtual ~bag() = default;
    virtual void insert(int) = 0;
    virtual void print() const = 0;
    virtual void clear() = 0;
}; 