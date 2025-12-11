#include "Fixed.hpp"
#include <iostream>
#include <cmath>   // per roundf

const int Fixed::_fractionalBits = 8;

// Default constructor
Fixed::Fixed()
    : _rawValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_rawValue = other._rawValue;
    return (*this);
}

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// Costruttore da int
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    // Shiftiamo di 8 bit a sinistra: value * 2^8
    this->_rawValue = value << _fractionalBits;
}

// Costruttore da float
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    // Moltiplichiamo per 2^8 e arrotondiamo al più vicino intero
    this->_rawValue = static_cast<int>(
        std::roundf(value * (1 << _fractionalBits))
    );
}

// Conversione a float
float Fixed::toFloat(void) const
{
    // dividiamo per 2^8 per tornare al valore reale
    return (static_cast<float>(this->_rawValue) / (1 << _fractionalBits));
}

// Conversione a int (tronca la parte frazionaria)
int Fixed::toInt(void) const
{
    // shift a destra di 8 bit: raw / 2^8
    return (this->_rawValue >> _fractionalBits);
}

// Metodi ex00
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_rawValue);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_rawValue = raw;
}

// Overload << : stampa il valore come float
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return (os);
}
