#include "Planet.h"
#include <iostream>


Planet::Planet(const std::string& PlanetName) :name(PlanetName)
{
}

const std::string Planet::getName() const
{
	return name;
}

size_t Planet::getSize() const
{
	return jedis.size();
}

bool Planet::addJedi(const Jedi& j)
{
	size_t jedisSize = jedis.size();
	for (size_t i = 0; i < jedisSize; i++)
	{
		if (jedis[i].getName() == j.getName()) {
			std::cout << "There is already a jedi with this name on this planet.\n";
			return false;
		}
	}
	jedis.push_back(j);
	std::cout << "You successfully add this jedi.\n";
	return true;
}

bool Planet::removeJedi(const std::string& jediName)
{
	size_t jedisSize = jedis.size();
	for (size_t i = 0; i < jedisSize; i++)
	{
		if (jedis[i].getName() == jediName) {
			jedis.erase(jedis.begin() + i);
			std::cout << "You successfully remove this jedi.\n";
			return true;
		}
	}

	std::cout << "There is not a jedi with this name on this planet.\n";
	return false;
}
bool Planet::promoteJedi(const std::string& jediName, const double& multiplier)
{
	size_t jedisSize = jedis.size();
	for (size_t i = 0; i < jedisSize; i++)
	{
		if (jedis[i].getName() == jediName) {
			jedis[i].promote(multiplier);
			return true;
		}
	}
	return false;
}

bool Planet::demoteJedi(const std::string& jediName, const double& multiplier)
{
	size_t jedisSize = jedis.size();
	for (size_t i = 0; i < jedisSize; i++)
	{
		if (jedis[i].getName() == jediName) {
			jedis[i].demote(multiplier);
			return true;
		}
	}
	return false;
}

Jedi Planet::getStrongestJedi() const
{

	Jedi strongestJedi(jedis[0]);
	size_t jedisSize = jedis.size();

	for (size_t i = 1; i < jedisSize; i++)
	{
		if (jedis[i].getStrength() > strongestJedi.getStrength()) {
			strongestJedi = jedis[i];
		}
	}
	return strongestJedi;
}

void Planet::getYoungestJedi(const RANK r) const
{
	size_t jedisSize = jedis.size();
	Jedi youngestJedi;


	for (size_t i = 0; i < jedisSize; i++)
	{
		if (r == jedis[i].getRank() && (youngestJedi.getAge() > jedis[i].getAge())) {
			youngestJedi = jedis[i];
		}
		if (i == jedisSize - 1 && youngestJedi.getName() == "") {
			std::cout << "There is not a jedi from this rank on this planet.\n";
			return;
		}
	}
	youngestJedi.print();
}

void Planet::getMostUsedSaborColor(const RANK r) const
{

	size_t jedisSize = jedis.size();
	std::vector<std::string> containerOfColors;

	for (size_t i = 0; i < jedisSize; i++)
	{
		if (jedis[i].getRank() == r) {
			containerOfColors.push_back(jedis[i].getSaborColor());
		}
	}

	size_t containerSize = containerOfColors.size();
	if (containerSize == 0) {
		std::cout << "There is not a jedi from this rank on this planet.\n";
		return;
	}

	size_t countOfThisColor = 0;
	size_t countOfMostUsedColor = 0;
	int indexOfMostUsedColor = 0;

	for (size_t i = 0; i < containerSize; i++)
	{
		for (size_t j = i + 1; j < containerSize; j++) {
			if (containerOfColors[i] == containerOfColors[j]) {
				countOfThisColor++;
			}
		}
		if (countOfMostUsedColor < countOfThisColor) {
			indexOfMostUsedColor = i;
			countOfMostUsedColor = countOfThisColor;
		}

	}

	std::cout << "Most used color of sabor is " << containerOfColors[indexOfMostUsedColor] << "\n";

}

int Planet::isFromThisPlanet(const std::string& jediName) const
{
	size_t jedisSize = jedis.size();
	for (size_t i = 0; i < jedisSize; i++)
	{
		if (jedis[i].getName() == jediName) {
			return i;
		}
	}
	return -1;
}

void Planet::printJediFromThisPlanet(const std::string& jediName) const
{
	jedis[isFromThisPlanet(jediName)].print();
	std::cout << "Planet: " << name << "\n";

}



void Planet::print() const
{
	std::cout << "Planet: " << name << "\n";
	size_t size = jedis.size();

	size_t* sortedIndexes = new size_t[size];
	for (size_t i = 0; i < size; i++)
	{
		sortedIndexes[i] = i;
	}

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i + 1; j < size; j++) {
			if (!(jedis[i] < jedis[j])) {
				std::swap(sortedIndexes[i], sortedIndexes[j]);
			}
		}
	}


	for (size_t i = 0; i < size; i++)
	{
		jedis[sortedIndexes[i]].print();
	}
	delete[] sortedIndexes;

}

void Planet::sort()
{
	size_t jedisSize = jedis.size();
	for (size_t i = 0; i < jedisSize; i++)
	{
		for (size_t j = i + 1; j < jedisSize; j++)
		{
			if (jedis[i].getName() < jedis[j].getName()) {
				std::swap(jedis[i], jedis[j]);
			}
		}
	}


}

void Planet::operator+=(const Planet& p2)
{
	size_t p2Size = p2.jedis.size();
	for (size_t i = 0; i < p2Size; i++)
	{
		jedis.push_back(p2.jedis[i]);
	}
}



std::ostream& operator<<(std::ostream& out, const Planet& p)
{
	out << p.name << " " << p.jedis.size() << "\n";
	for (const Jedi& j : p.jedis) {
		out << j;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Planet& p)
{
	size_t size = 0;
	in >> p.name >> size;

	for (size_t i = 0; i < size; i++) {
		Jedi j;
		in >> j;
		p.jedis.push_back(j);
	}
	return in;
}

