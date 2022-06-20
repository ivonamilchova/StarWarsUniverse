#ifndef __PLANET
#define __PLANET
#include <string>
#include "Jedi.h"
#include <vector>
struct SaborColor {
	std::string saberColor;
	size_t num;

};

class Planet {
private:
	std::string name;
	std::vector<Jedi> jedis;

	
public:
	Planet() = default;
	Planet(const std::string &PlanetName);
	

	const std::string getName()const;
	size_t getSize() const;
	Jedi getStrongestJedi()const;
	void getYoungestJedi(const RANK r)const;
	void getMostUsedSaborColor(const RANK r)const;

	bool addJedi(const Jedi& j);
	bool removeJedi(const std::string& jediName);
	bool promoteJedi(const std::string& jediName, const double& multiplier);
	bool demoteJedi(const std::string& jediName, const double& multiplier);
	
	int isFromThisPlanet(const std::string& jediName) const;
	void printJediFromThisPlanet(const std::string& jediName) const;

	void print() const; 
	void sort();

	void operator+= (const Planet& p2);

	friend std::ostream& operator<< (std::ostream& out, const Planet& p);
	friend std::istream& operator>> (std::istream& in, Planet& p);
	
};



#endif // !__PLANET
