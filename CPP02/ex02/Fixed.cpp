#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _rawBits(0)
{
}

Fixed::Fixed(const int value)
{
	this->_rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	this->_rawBits = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_rawBits = other._rawBits;
	return *this;
}

Fixed::~Fixed()
{
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_rawBits) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->_rawBits >> _fractionalBits;
}

// comparison operators

bool Fixed::operator>(const Fixed &other) const
{
	return this->_rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->_rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->_rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->_rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->_rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->_rawBits != other._rawBits;
}

// arithmetic operators

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

// increment / decrement

Fixed &Fixed::operator++()
{
	this->_rawBits++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_rawBits++;
	return tmp;
}

Fixed &Fixed::operator--()
{
	this->_rawBits--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_rawBits--;
	return tmp;
}

// min / max

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return os;
}
