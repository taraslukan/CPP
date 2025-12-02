#include "Harl.hpp"
#include <iostream>

// Costruttore/Distruttore (non fanno nulla di speciale, ma sono puliti da avere)
Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< std::endl;
	std::cout << "I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout
		<< "I cannot believe adding extra bacon costs more money."
		<< std::endl;
	std::cout
		<< "You didn’t put enough bacon in my burger!"
		<< std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout
		<< "I think I deserve to have some extra bacon for free."
		<< std::endl;
	std::cout
		<< "I’ve been coming for years, whereas you started working here just last month."
		<< std::endl;
}

void Harl::error(void)
{
	std::cout
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

void Harl::complain(const std::string &level)
{
	// Tipo del puntatore a funzione membro
	typedef void (Harl::*HarlMemberFn)(void);

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	HarlMemberFn actions[4] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; ++i)
	{
		if (level == levels[i])
		{
			// Chiamata a puntatore a funzione membro
			(this->*actions[i])();
			return;
		}
	}

	// Se nessun livello combacia, Harl non si lamenta (il subject non impone comportamento)
}
