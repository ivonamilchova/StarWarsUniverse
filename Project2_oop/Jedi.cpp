#include "Jedi.h"
#include "UserInterface.h"


#include <iostream>

RANK Jedi::ranks[] = { YOUNGLING,
   INITIATE,
   PADAWAN,
   KNIGHT_ASPIRANT,
   KNIGHT,
   MASTER,
   BATTLE_MASTER,
   GRAND_MASTER };

Jedi::Jedi(const std::string& nameParam, const RANK& rankParam, const size_t& ageParam, const std::string& saberColorParam, const double& powerParam)
	:name(nameParam), rank(rankParam), age(ageParam), saberColor(saberColorParam), strength(powerParam)
{
}

const std::string Jedi::getName() const
{
	return name;
}

void Jedi::print() const
{
	std::cout << "------------------------------------------------------------\n";
	std::cout << "Name: " << name << "\n";
	printRank();
	std::cout << "Age: " << age << "\n";
	std::cout << "Saber's color: " << saberColor << "\n";
	std::cout << "Power: " << strength << "\n";
	std::cout << "------------------------------------------------------------\n";

}

void Jedi::printRank() const
{
	std::cout << "Rank: ";
	switch (rank)
	{
	case YOUNGLING:
		std::cout << "YOUNGLING\n";
		break;
	case INITIATE:
		std::cout << "INITIATE\n";
		break;
	case PADAWAN:
		std::cout << "PADAWAN\n";
		break;
	case KNIGHT_ASPIRANT:
		std::cout << "KNIGHT_ASPIRANT\n";
		break;
	case KNIGHT:
		std::cout << "KNIGHT\n";
		break;
	case MASTER:
		std::cout << "MASTER\n";
		break;
	case BATTLE_MASTER:
		std::cout << "BATTLE_MASTER\n";
		break;
	case GRAND_MASTER:
		std::cout << "GRAND_MASTER\n";
		break;
	default:
		break;
	}
}

void Jedi::promote(const double multiplier)
{
	strength *= (1 + multiplier);
	int currentRank = Jedi::getRank(rank);
	if (currentRank == -1) {
		std::cout << "Could not find this rank.\n";
		return;
	}
	if (currentRank == NUM_RANKS - 1)
	{
		std::cout << "This is the last rank.\n";
		return;
	}
	rank = Jedi::ranks[currentRank + 1];



}

void Jedi::demote(double multiplier)
{
	strength *= (1 - multiplier);
	int currentRank = Jedi::getRank(rank);

	if (currentRank == -1) {
		std::cout << "Could not find this rank.\n";
		return;
	}
	if (currentRank == 0)
	{
		std::cout << "This is the first rank.\n";
		return;
	}
	rank = Jedi::ranks[currentRank - 1];


	/*switch (rank)
	{
	case YOUNGLING:
		std::cout << "This is the first rank.\n";
		break;
	case INITIATE:
		rank = YOUNGLING;
		break;
	case PADAWAN:
		rank = INITIATE;
		break;
	case KNIGHT_ASPIRANT:
		rank = PADAWAN;
		break;
	case KNIGHT:
		rank = KNIGHT_ASPIRANT;
		break;
	case MASTER:
		rank = KNIGHT;
		break;
	case BATTLE_MASTER:
		rank = MASTER;
		break;
	case GRAND_MASTER:
		rank = BATTLE_MASTER;
		break;
	default:
		break;
	}*/
}

int Jedi::getRank(const RANK r)
{
	for (int i = 0; i < NUM_RANKS; i++)
	{
		if (Jedi::ranks[i] == r) {
			return i;
		}
	}
	return -1;
}

RANK Jedi::getRank() const
{
	return rank;
}

double Jedi::getStrength() const
{
	return strength;
}

size_t Jedi::getAge() const
{
	return age;
}

const std::string Jedi::getSaborColor() const
{
	return saberColor;
}

bool Jedi::operator<(const Jedi& j2) const
{
	int r1 = Jedi::getRank(rank);
	int r2 = Jedi::getRank(j2.rank);

	return r1 < r2 || r1 == r2 && name < j2.name;
}

bool Jedi::operator>(const Jedi& j2) const
{
	return strength > j2.strength;
}

std::ostream& operator<<(std::ostream& out, const Jedi& j)
{
	out << j.name << " " << rankTostr(j.rank) << " " << j.age << " " << j.saberColor << " " << j.strength << "\n";
	return out;
}

std::istream& operator>>(std::istream& in, Jedi& j)
{
	std::string s;

	in >> j.name >> s >> j.age >> j.saberColor >> j.strength;
	j.rank = strToRank(s);
	return in;
}


