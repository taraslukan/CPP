#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	float toFloat(void) const;
	int   toInt(void) const;

	// comparison operators
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	// arithmetic operators
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	// increment / decrement
	Fixed &operator++();     // pre-increment
	Fixed operator++(int);   // post-increment
	Fixed &operator--();     // pre-decrement
	Fixed operator--(int);   // post-decrement

	// min / max
	static Fixed       &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed       &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

private:
	int                 _rawBits;
	static const int    _fractionalBits;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif
