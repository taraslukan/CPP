#include "replacer.hpp"

#include <iostream>
#include <fstream>
#include <string>

static std::string buildOutputFilename(const std::string &filename)
{
	return filename + ".replace";
}

bool replaceInFile(const std::string &filename,
                   const std::string &s1,
                   const std::string &s2)
{
	if (s1.empty())
	{
		std::cerr << "Error: s1 must not be empty." << std::endl;
		return false;
	}

	std::ifstream in(filename.c_str());
	if (!in.is_open())
	{
		std::cerr << "Error: cannot open input file '" << filename << "'." << std::endl;
		return false;
	}

	std::string outFilename = buildOutputFilename(filename);
	std::ofstream out(outFilename.c_str());
	if (!out.is_open())
	{
		std::cerr << "Error: cannot create output file '" << outFilename << "'." << std::endl;
		in.close();
		return false;
	}

	// Leggo tutto il contenuto del file in una stringa
	std::string content;
	std::string line;
	while (std::getline(in, line))
	{
		content += line;
		if (!in.eof())
			content += "\n";
	}
	in.close();

	std::string::size_type pos = 0;
	std::string::size_type found;

	while (true)
	{
		found = content.find(s1, pos);
		if (found == std::string::npos)
		{
			// Nessuna altra occorrenza: scrivo il resto e finisco
			out << content.substr(pos);
			break;
		}
		// Scrivo tutto quello che sta prima dell'occorrenza
		out << content.substr(pos, found - pos);
		// Scrivo s2 al posto di s1
		out << s2;
		// Avanzo dopo l'occorrenza trovata
		pos = found + s1.length();
	}

	out.close();
	return true;
}
