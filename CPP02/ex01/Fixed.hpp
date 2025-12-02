#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();                              // Default constructor
	Fixed(const int value);               // Int constructor
	Fixed(const float value);             // Float constructor
	Fixed(const Fixed &other);            // Copy constructor
	Fixed &operator=(const Fixed &other); // Copy assignment
	~Fixed();                             // Destructor

	int   getRawBits(void) const;
	void  setRawBits(int const raw);

	float toFloat(void) const;
	int   toInt(void) const;

private:
	int                  _rawBits;
	static const int     _fractionalBits;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif
