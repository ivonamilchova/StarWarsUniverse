#include "UserInterface.h"
#include <iostream>
void UserInterface::sliptString(const std::string& command, std::vector<std::string>& args, const char delimiter) const
{
	std::string currWord;
	for (const char c : command)
	{
		if (c == delimiter) {
			args.push_back(currWord);
			currWord = "";
		}
		else {
			currWord += c;
		}
	}
	args.push_back(currWord);
}
void UserInterface::help() const
{
	std::cout << "List of commands: \n";
	std::cout << "help\n";
	std::cout << "quit\n";
	std::cout << "open <file>\n";
	std::cout << "save\n";
	std::cout << "exit\n";
	std::cout << "saveas <new_file>\n";

	std::cout << "add_planet <planet_name>\n";
	std::cout << "create_jedi <planet_name> <jedi_name> <jedi_rank> <jedi_age> <saber_color> <jedi_strength>\n";
	std::cout << "removeJedi <jedi_name> <planet_name > \n";
	std::cout << "promote_jedi <jedi_name> <multiplier>\n";
	std::cout << "demote_jedi <jedi_name> <multiplier> \n";
	std::cout << "get_strongest_jedi <planet_name> \n";
	std::cout << "get_youngest_jedi <planet_name> <jedi_rank>\n";
	std::cout << "get_most_used_saber_color <planet_name> <jedi_rank>\n";
	std::cout << "get_most_used_saber_color <planet_name>\n";
	std::cout << "print <planet_name>\n";
	std::cout << "print <jedi_name> \n";
	std::cout << "<planet_name> + <planet_name> \n";
}
void UserInterface::run()
{
	std::string currentFile;
	std::string command;
	std::vector<std::string> args;

	while (true) {
		std::cout << "> ";


		std::getline(std::cin, command);
		//std::cout << command << "\n";
		args.clear();
		sliptString(command, args, ' ');


		if (args[0] == "add_planet")
		{
			std::string planetName = args[1];

			starWarsUniverse.addPlanet(planetName);
		}
		else if (args[0] == "create_jedi") {
			std::string planetName = args[1];
			std::string jediName = args[2];
			toCapitalLetters(args[3]);
			RANK jediRank = strToRank(args[3]);  
			size_t jediAge = strToSizeT(args[4]);
			std::string jediSaberColor = args[5];
			double strength = strToDouble(args[6]);

			Jedi j(jediName, jediRank, jediAge, jediSaberColor, strength);
			starWarsUniverse.createJedi(planetName, j);
		}
		else if (args[0] == "removeJedi")
		{
			std::string jediName = args[1];
			std::string planetName = args[2];

			starWarsUniverse.removeJedi(planetName, jediName);
		}
		else if (args[0] == "promote_jedi")
		{
			std::string jediName = args[1];
			size_t multiplier = strToSizeT(args[2]);
			if (multiplier < 0) {
				std::cout << "Incorrect input!\n";
				return;
			}

			starWarsUniverse.promoteJedi(jediName, multiplier);
		}
		else if (args[0] == "demote_jedi")
		{
			std::string jediName = args[1];
			size_t multiplier = strToSizeT(args[2]);
			if (multiplier < 0) {
				std::cout << "Incorrect input!\n";
				return;
			}

			starWarsUniverse.demoteJedi(jediName, multiplier);
		}
		else if (args[0] == "get_strongest_jedi")
		{
			std::string planetName = args[1];

			starWarsUniverse.getStrongestJedi(planetName);
		}
		else if (args[0] == "get_youngest_jedi")
		{
			std::string planetName = args[1];
			RANK r = strToRank(args[2]);
			starWarsUniverse.getYoungestJedi(planetName, r);

		}
		else if (args[0] == "get_most_used_sabor_color")
		{
			std::string planetName = args[1];

			if (args.size() == 2) {
				starWarsUniverse.getMostUsedSaberColorOfGrandMaster(planetName);

			}
			if (args.size() == 3)
			{
				RANK r = strToRank(args[2]);
				starWarsUniverse.getMostUsedSaberColor(planetName, r);
			}

		}
		else if (args[0] == "print") {
			std::string name = args[1];
			if (starWarsUniverse.isPlanet(name)) {
				starWarsUniverse.printPlanet(name);
			}
			if (starWarsUniverse.isJedi(name)) {
				starWarsUniverse.printJedi(name);
			}
		}

		else if (args[0] == "quit") {
			break;
		}
		else if (args[0] == "help") {
			help();
		}
		else if (args[0] == "open") {
			currentFile = args[1];
			sliptString(currentFile, args, '\\');
			bool successful = starWarsUniverse.open(args[args.size() - 1]);

			if (successful) {
				std::cout << "Successfully opened " << args[args.size() - 1] << ".\n";
			}
			else {
				std::cout << "Unsuccessful opening of the file.\n";
			}
		}
		else if (args[0] == "save") {

			bool successful = starWarsUniverse.save(currentFile);
			sliptString(currentFile, args, '\\');
			if (successful) {
				std::cout << "Successfully saved " << args[args.size() - 1] << ".\n";
			}
			else {
				std::cout << "Unsuccessful saving of the file.\n";
			}

		}
		else if (args[0] == "saveas") {
			currentFile = args[1];
			sliptString(currentFile, args, '\\');
			bool successful = starWarsUniverse.saveAs(args[args.size() - 1]);

			if (successful) {
				std::cout << "Successfully saved another " << args[args.size() - 1] << ".\n";
			}
			else {
				std::cout << "Unsuccessful saving of the file.\n";
			}
		}

		else if (args[0] == "exit") {
			std::cout << "You have to input one of this commands: \n";
			std::cout << "save\n";
			std::cout << "saveas <new_file> \n";

		}
		else if (args[1] == "+") {

			starWarsUniverse.mergePlanets(args[0], args[2]);

		}
		else {
			std::cout << "Unknown  command: " << args[0] << '\n';
		}


	}
}

void reverseStr(std::string& s)
{
	size_t sLength = s.size();
	for (size_t i = 0; i < sLength / 2; i++)
	{
		std::swap(s[i], s[sLength - 1 - i]);
	}
}

size_t strToSizeT(std::string& s)
{
	size_t sLen = s.size();
	reverseStr(s);
	size_t multipliår = 1;
	size_t result = 0;

	for (size_t i = 0; i < sLen; i++)
	{
		result += (s[i] - '0') * multipliår;
		multipliår *= 10;
	}
	return result;
}

double strToDouble(std::string& s)
{
	size_t sLen = s.size();
	reverseStr(s);
	size_t multipliår = 1;
	double divisor = 1;
	size_t result = 0;

	for (size_t i = 0; i < sLen; i++)
	{
		if (s[i] == '.') {
			divisor = pow(10, (sLen - 1 - i));
			continue;

		}
		result += (s[i] - '0') * multipliår;
		multipliår *= 10;
	}
	return result / divisor;
}

RANK strToRank(const std::string& s)
{
	RANK r = YOUNGLING;
	if (s == "YOUNGLING") {
		r = YOUNGLING;
	}
	else if (s == "INITIATE") {
		r = INITIATE;
	}
	else if (s == "PADAWAN")
	{
		r = PADAWAN;
	}
	else if (s == "KNIGHT_ASPIRANT")
	{
		r = KNIGHT_ASPIRANT;
	}
	else if (s == "KNIGHT")
	{
		r = KNIGHT;
	}
	else if (s == "MASTER")
	{
		r = MASTER;
	}
	else if (s == "BATTLE_MASTER")
	{
		r = BATTLE_MASTER;
	}
	else if (s == "GRAND_MASTER")
	{
		r = GRAND_MASTER;
	}

	return r;

}

std::string rankTostr(const RANK r)
{
	std::string s;
	if (r == YOUNGLING) {
		s = "YOUNGLING";
	}
	else if (r == INITIATE) {
		s = "INITIATE";
	}
	else if (r == PADAWAN)
	{
		s = "PADAWAN";
	}
	else if (r == KNIGHT_ASPIRANT)
	{
		s = "KNIGHT_ASPIRANT";
	}
	else if (r == KNIGHT)
	{
		s = "KNIGHT";
	}
	else if (r == MASTER)
	{
		s = "MASTER";
	}
	else if (r == BATTLE_MASTER)
	{
		s = "BATTLE_MASTER";
	}
	else if (r == GRAND_MASTER)
	{
		s = "GRAND_MASTER";
	}

	return s;
}



void toCapitalLetters(std::string& s)
{
	size_t sLen = s.size();
	for (size_t i = 0; i < sLen; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] = s[i] - 'a' + 'A';
		}
	}
}
