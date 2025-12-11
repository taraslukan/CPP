#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int                 _rawValue;
    static const int    _fractionalBits;

public:
    // Orthodox Canonical Form
    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    // Costruttori numerici
    Fixed(const int value);
    Fixed(const float value);

    // Conversioni
    float toFloat(void) const;
    int   toInt(void) const;

    // Getter/Setter raw
    int  getRawBits(void) const;
    void setRawBits(int const raw);

    // --- Operatori di confronto ---
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // --- Operatori aritmetici ---
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // --- Incremento / Decremento ---
    // pre-incremento / pre-decremento
    Fixed &operator++();    // ++a
    Fixed &operator--();    // --a
    // post-incremento / post-decremento
    Fixed operator++(int);  // a++
    Fixed operator--(int);  // a--

    // --- Funzioni statiche min/max ---
    static Fixed      &min(Fixed &a, Fixed &b);
    static Fixed const&min(Fixed const &a, Fixed const &b);
    static Fixed      &max(Fixed &a, Fixed &b);
    static Fixed const&max(Fixed const &a, Fixed const &b);
};

// Overload << già come in ex01
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
