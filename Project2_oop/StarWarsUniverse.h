#ifndef __STAR_WARS_UNIVERSE
#define __STAR_WARS_UNIVERSE
#include "Planet.h"
#include "fstream"
#include<iostream>
#include <vector>


class StarWarsUniverse {
private:
	std::vector<Planet> planets;
public:

	void addPlanet(const std::string& planetName);
	bool createJedi(const std::string& planetName, const Jedi& jedi);
	bool removeJedi(const std::string& planetName, const std::string& jediName);
	void promoteJedi(const std::string& jediName, const double& multiplierParam);
	void demoteJedi(const std::string& jediName, const double& multiplierParam);
	void getStrongestJedi(const std::string& planetName) const;
	void getYoungestJedi(const std::string& planetName, const RANK r) const;
	void getMostUsedSaberColor(const std::string& planetName, const RANK r) const;
	void getMostUsedSaberColorOfGrandMaster(const std::string& planetName) const;


	bool isPlanet(const std::string planetName) const;
	bool isJedi(const std::string jediName) const;

	void printJedi(const std::string& jediName)const;
	void printPlanet(const std::string& PlanetName) const;

	bool open(const std::string& currentFile);
	bool save(const std::string& currentFile) const;
	bool saveAs(const std::string& currentFile) const;



	void mergePlanets(const std::string& planet1Name, const std::string& planet2Name);

	friend std::ostream& operator<<(std::ostream& out, const StarWarsUniverse& swu);
	friend std::istream& operator>>(std::istream& in, StarWarsUniverse& swu);



};
#endif // !__STAR_WARS_UNIVERSE

