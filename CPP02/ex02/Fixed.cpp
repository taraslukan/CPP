#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

// ==== Orthodox Canonical Form ====

Fixed::Fixed()
    : _rawValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_rawValue = other._rawValue;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// ==== Costruttori numerici ====

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_rawValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_rawValue = static_cast<int>(
        std::roundf(value * (1 << _fractionalBits))
    );
}

// ==== Conversioni ====

float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->_rawValue) / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->_rawValue >> _fractionalBits);
}

// ==== Getter/Setter raw ====

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

// ==== Operatore << ====

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return (os);
}

// ==== Operatori di confronto ====
// Confrontiamo direttamente i raw value: hanno stessa scala (2^8)

bool Fixed::operator>(const Fixed &other) const
{
    return (this->_rawValue > other._rawValue);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->_rawValue < other._rawValue);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->_rawValue >= other._rawValue);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->_rawValue <= other._rawValue);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->_rawValue == other._rawValue);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->_rawValue != other._rawValue);
}

// ==== Operatori aritmetici ====
// Usiamo la rappresentazione raw, facendo attenzione ai bit frazionari.

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result._rawValue = this->_rawValue + other._rawValue;
    return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result._rawValue = this->_rawValue - other._rawValue;
    return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    // Moltiplicazione: (rawA * rawB) / 2^fractionalBits
    long tmp = static_cast<long>(this->_rawValue)
             * static_cast<long>(other._rawValue);
    result._rawValue = static_cast<int>(tmp >> _fractionalBits);
    return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    // Divisione: (rawA * 2^fractionalBits) / rawB
    long numerator = (static_cast<long>(this->_rawValue) << _fractionalBits);
    // Nota: nessun controllo division by zero (il subject non lo richiede esplicitamente)
    result._rawValue = static_cast<int>(numerator / other._rawValue);
    return (result);
}

// ==== Incremento / Decremento ====
// Incrementiamo/decrementiamo di 1 unità di rawValue = 1 / 2^fractionalBits

// pre-incremento: modifica e ritorna *this
Fixed &Fixed::operator++()
{
    ++this->_rawValue;
    return (*this);
}

// post-incremento: salva copia, incrementa, ritorna copia
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++this->_rawValue;
    return (tmp);
}

// pre-decremento
Fixed &Fixed::operator--()
{
    --this->_rawValue;
    return (*this);
}

// post-decremento
Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --this->_rawValue;
    return (tmp);
}

// ==== Funzioni statiche min / max ====

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
    return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
    return (a > b ? a : b);
}
