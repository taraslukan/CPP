#include "Fixed.hpp"
#include <iostream>

// Inizializzazione della costante statica (8 bit di parte frazionaria)
const int Fixed::_fractionalBits = 8;

// Default constructor: imposta il valore a 0
Fixed::Fixed()
    : _rawValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    // riutilizziamo l'operator= per non duplicare la logica
    *this = other;
}

// Copy assignment operator
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

// Restituisce il valore "grezzo" interno
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_rawValue);
}

// Imposta direttamente il valore "grezzo" interno
void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_rawValue = raw;
}
