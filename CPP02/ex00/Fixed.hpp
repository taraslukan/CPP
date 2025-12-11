#ifndef FIXED_HPP
#define FIXED_HPP

// La classe Fixed rappresenta un numero in virgola fissa (fixed-point)
// con 8 bit di parte frazionaria.

class Fixed
{
private:
    int                 _rawValue;                 // valore "grezzo" memorizzato
    static const int    _fractionalBits;          // numero di bit frazionari (8)

public:
    // Orthodox Canonical Form
    Fixed();                                      // default constructor
    Fixed(const Fixed &other);                    // copy constructor
    Fixed &operator=(const Fixed &other);         // copy assignment operator
    ~Fixed();                                     // destructor

    // Getter/Setter per il valore grezzo
    int  getRawBits(void) const;                  // ritorna _rawValue
    void setRawBits(int const raw);              // setta _rawValue
};

#endif
