#include <string>
#include <iostream>
#include <ostream>
#include <sstream>// memorise this for exam**

class	bigint
{
	private:
		std::string	_string;

	public:
		bigint();
		bigint(unsigned int n);
		bigint(const bigint& original);
		bigint& operator=(const bigint& other);
		~bigint();

	//getValue
		std::string		getvalue() const;

	//operators
		bigint	operator+(const bigint& other) const;
		bigint	operator+=(const bigint& other);
		bigint	operator++(int);
		bigint	operator++(void);
		bigint	operator<<(unsigned int value) const;
		bigint	operator<<=(unsigned int value);
		bigint	operator>>=(const bigint& other);
		bool	operator>(const bigint& other);
		bool	operator<(const bigint& other);
		bool	operator==(const bigint& other);
		bool	operator!=(const bigint& other);
		bool	operator<=(const bigint& other);
		bool	operator>=(const bigint& other);
};

std::ostream&	operator<<(std::ostream& out, const bigint& other); 