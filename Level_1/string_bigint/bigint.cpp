#include "bigint.hpp"

bigint::bigint()
{
	this->_string = "0";
}

bigint::bigint(unsigned int n)
{
	std::ostringstream oss;
	oss << n;

	this->_string = oss.str();
}

bigint::bigint(const bigint& original)
{
	*this = original;
}

bigint& bigint::operator=(const bigint& other)
{
	if (this != &other) {
		this->_string = other._string;
	}
	return *this;
}

bigint::~bigint() {}


//getter
std::string		bigint::getvalue() const
{
	return (this->_string);
}


//operator time
bigint	bigint::operator+(const bigint& other) const
{
	bigint	copy(*this);
	std::string	ss1 = this->_string;
	std::string	ss2 = other._string;

	//check which is longer
	if (ss2.size() > ss1.size())
		std::swap(ss1, ss2);

	std::string	result = "";
	int	i = ss1.length() - 1;// to prevent hitting the .end() part
	int	j = ss2.length() - 1;
	int	carry = 0;

	while (i >= 0 || j >= 0 || carry)
	{
		int	digit1 = i >= 0 ? ss1[i] - '0' : 0;
		int	digit2 = j >= 0 ? ss2[j] - '0' : 0;
		int	sum = digit1 + digit2 + carry;

		i--;
		j--;
		result.insert(result.begin(), (sum % 10) + '0');
		carry = (sum / 10);
	}
	copy._string = result;
	return(copy);
}

bigint	bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return (*this);
}

bigint	bigint::operator++(int)
{
	bigint	copy(*this);
	bigint	copy2(1);

	*this += copy2;
	return (copy);
}

bigint	bigint::operator++(void)
{
	bigint	copy(1);

	*this += copy;
	return (*this);
}

bigint	bigint::operator<<(unsigned int shift) const
{
	bigint	copy(*this);

	if (copy._string == "0")
		return (copy);
	
	copy._string.append(shift, '0');
	return(copy);
}

bigint	bigint::operator<<=(unsigned int shift)
{
	if (this->_string == "0")
		return (*this);
	
	this->_string.append(shift, '0');
	return(*this);
}

bigint	bigint::operator>>=(const bigint& other)
{
	if (this->_string == "0")
		return (*this);

	std::stringstream oss;
	oss << other;
	size_t shift = 0;
	oss >> shift;

	if (this->_string.size() > shift)
		this->_string.erase(this->_string.begin() + (this->_string.size() - shift), this->_string.end());
	else
	{
		this->_string.clear();
		this->_string.push_back('0');
	}
	return(*this);
}

bool	bigint::operator>(const bigint& other)
{
	if (this->_string.size() > other._string.size())
		return (true);
	if (this->_string.size() < other._string.size())
		return (false);

	std::string		x1 = this->_string;
	std::string		x2 = other._string;

	for (size_t i = 0; i < x1.size(); i++)
	{
		if (x1[i] != x2[i])
		{
			if (x1[i] > x2[i])
				return (true);
			else
				return (false);
		}
	}
	return (false);
}

bool	bigint::operator<(const bigint& other)
{
	if (this->_string.size() < other._string.size())
		return (true);
	if (this->_string.size() > other._string.size())
		return (false);

	std::string		x1 = this->_string;
	std::string		x2 = other._string;

	for (size_t i = 0; i < x1.size(); i++)
	{
		if (x1[i] != x2[i])
		{
			if (x1[i] < x2[i])
				return (true);
			else
				return (false);
		}
	}
	return (false);
}

bool	bigint::operator==(const bigint& other)
{
	if (this->_string == other._string)
		return (true);
	return (false);
}

bool	bigint::operator!=(const bigint& other)
{
	if (this->_string != other._string)
		return (true);
	return (false);
}

bool	bigint::operator<=(const bigint& other)
{
	if (this->_string == other._string)
		return (true);
	if (*this < other)
		return (true);
	return (false);
}

bool	bigint::operator>=(const bigint& other)
{
	if (this->_string == other._string)
		return (true);
	if (*this > other)
		return (true);
	return (false);
}

//outside class
std::ostream&	operator<<(std::ostream& out, const bigint& other)
{
	out << other.getvalue();
	return (out);
} 