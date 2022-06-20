#include "StarWarsUniverse.h"
#include <iostream>


void StarWarsUniverse::addPlanet(const std::string& planetName)
{
	Planet p(planetName);
	planets.push_back(p);
	std::cout << "You successfully add this planet.\n";
}

bool StarWarsUniverse::createJedi(const std::string& planetName, const Jedi& jedi)
{
	size_t planetsSize = planets.size();
	size_t jedisSize = 0;
	for (size_t i = 0; i < planetsSize; i++)
	{
		if (planets[i].getName() == planetName) {
			jedisSize = planets[i].getSize();
			return planets[i].addJedi(jedi);
		}
	}
	return false;
}

bool StarWarsUniverse::removeJedi(const std::string& planetName, const std::string& jediName)
{
	size_t planetsSize = planets.size();
	for (size_t i = 0; i < planetsSize; i++)
	{
		if (planets[i].getName() == planetName) {
			return planets[i].removeJedi(jediName);
		}
	}
	std::cout << "There is not planet with this name.\n";
	return false;
}

void StarWarsUniverse::promoteJedi(const std::string& jediName, const double& multiplierParam)
{
	size_t planetsSize = planets.size();
	for (size_t i = 0; i < planetsSize; i++)
	{
		if (planets[i].promoteJedi(jediName, multiplierParam)) {
			std::cout << "You successfully promote " << jediName << ".\n";
			return;
		}
	}
	std::cout << "Unsuccessful promoting.\n";
}

void StarWarsUniverse::demoteJedi(const std::string& jediName, const double& multiplierParam)
{
	size_t planetsSize = planets.size();
	for (size_t i = 0; i < planetsSize; i++)
	{
		if (planets[i].demoteJedi(jediName, multiplierParam)) {
			std::cout << "You successfully demote " << jediName << ".\n";
			return;
		}
	}
	std::cout << "Unsuccessful promoting.\n";
}

void StarWarsUniverse::getStrongestJedi(const std::string& planetName) const
{
	size_t planetsSize = planets.size();
	for (size_t i = 0; i < planetsSize; i++)
	{
		if (planets[i].getName() == planetName) {
			Jedi j = planets[i].getStrongestJedi();
			j.print();
			return;
		}
	}
}

void StarWarsUniverse::getYoungestJedi(const std::string& planetName, const RANK r) const
{
	size_t planetsSize = planets.size();
	for (size_t i = 0; i < planetsSize; i++)
	{
		if (planets[i].getName() == planetName) {
			planets[i].getYoungestJedi(r);
			return;
		}
	}
}

void StarWarsUniverse::getMostUsedSaberColor(const std::string& planetName, const RANK r) const
{
	for (size_t i = 0; i < planets.size(); i++)
	{
		if (planets[i].getName() == planetName) {
			planets[i].getMostUsedSaborColor(r);
		}
	}
}

void StarWarsUniverse::getMostUsedSaberColorOfGrandMaster(const std::string& planetName) const
{

	for (size_t i = 0; i < planets.size(); i++)
	{
		if (planets[i].getName() == planetName) {
			planets[i].getMostUsedSaborColor(GRAND_MASTER);
		}
	}
}


bool StarWarsUniverse::isPlanet(const std::string planetName) const
{
	size_t planetSize = planets.size();
	for (size_t i = 0; i < planetSize; i++)
	{
		if (planets[i].getName() == planetName) {
			return true;
		}
	}

	return false;
}

bool StarWarsUniverse::isJedi(const std::string jediName) const
{
	size_t planetsSize = planets.size();
	for (size_t i = 0; i < planetsSize; i++)
	{
		if (planets[i].isFromThisPlanet(jediName) >= 0) {
			return true;
		}
	}
	return false;
}

void StarWarsUniverse::printJedi(const std::string& jediName) const
{
	size_t planetsSize = planets.size();
	size_t jedisSize = 0;
	for (size_t i = 0; i < planetsSize; i++)
	{
		jedisSize = planets[i].getSize();
		if (planets[i].isFromThisPlanet(jediName) >= 0) {
			planets[i].printJediFromThisPlanet(jediName);
			return;
		}
	}
	std::cout << "There is not a jedi with this name.\n";
}

void StarWarsUniverse::printPlanet(const std::string& planetName) const
{
	size_t planetsSize = planets.size();
	for (size_t i = 0; i < planetsSize; i++)
	{
		if (planets[i].getName() == planetName) {
			planets[i].print();
			return;
		}
	}
	std::cout << "There is not a planet with this name.\n";
}

bool StarWarsUniverse::open(const std::string& currentFile)
{
	planets.clear();

	std::ifstream fin(currentFile);

	if (!fin) {
		std::ofstream fout(currentFile);
		bool successful = fout.is_open();
		fout.close();
		return successful;
	}

	size_t planetsSize = 0;
	fin >> planetsSize;


	for (size_t i = 0; i < planetsSize; i++)
	{
		Planet p;
		fin >> p;
		planets.push_back(p);
	}
	fin.close();
	return true;
}

bool StarWarsUniverse::save(const std::string& currentFile) const
{
	std::ofstream fout(currentFile);
	if (!fout) {
		std::cout << "File is not opened!\n";
		return false;
	}

	fout << planets.size() << "\n";

	for (const Planet& p : planets)
	{
		fout << p;
	}
	return true;
}
bool StarWarsUniverse::saveAs(const std::string& currentFile) const
{
	std::ofstream fout(currentFile);
	if (!fout) {
		return false;
	}

	fout << planets.size() << "\n";

	for (const Planet& p : planets)
	{
		fout << p;
	}
	return true;
}


void StarWarsUniverse::mergePlanets(const std::string& planet1Name, const std::string& planet2Name)
{
	size_t indexOfFirstPlanet = 0;
	size_t indexOfSecondPlanet = 0;

	size_t planetsSize = planets.size();

	for (size_t i = 0; i < planetsSize; i++)
	{
		if (planets[i].getName() == planet1Name) {
			indexOfFirstPlanet = i;
		}
		if (planets[i].getName() == planet2Name) {
			indexOfSecondPlanet = i;
			break;
		}
	}

	planets[indexOfFirstPlanet] += planets[indexOfSecondPlanet];

	planets[indexOfFirstPlanet].sort();
	planets[indexOfFirstPlanet].print();

}





std::ostream& operator<<(std::ostream& out, const StarWarsUniverse& swu)
{
	size_t planetsSize = swu.planets.size();
	for (size_t i = 0; i < planetsSize; i++)
	{
		out << swu.planets[i] << "\n";
	}
	return out;

}

std::istream& operator>>(std::istream& in, StarWarsUniverse& swu)
{
	size_t planetsSize = swu.planets.size();
	for (size_t i = 0; i < planetsSize; i++)
	{
		in >> swu.planets[i];
	}
	return in;
}
