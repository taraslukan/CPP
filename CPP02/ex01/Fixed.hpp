#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream> // per std::ostream nell'operator<<
#include <string>   // non strettamente necessario, ma comodo se servi in futuro

class Fixed
{
private:
    int                 _rawValue;
    static const int    _fractionalBits;

public:
    // Orthodox Canonical Form
    Fixed();                              // default
    Fixed(const Fixed &other);            // copy ctor
    Fixed &operator=(const Fixed &other); // copy assignment
    ~Fixed();                             // dtor

    // Nuovi costruttori per ex01
    Fixed(const int value);               // da int
    Fixed(const float value);             // da float

    // Conversioni
    float toFloat(void) const;            // fixed -> float
    int   toInt(void) const;              // fixed -> int

    // Metodi di ex00
    int  getRawBits(void) const;
    void setRawBits(int const raw);
};

// Overload dell'operatore di inserzione (ostream << Fixed)
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
