#ifndef __JEDI
#define __JEDI
#include <string>
#include <iostream>

const size_t NUM_RANKS = 8;
enum RANK {
	YOUNGLING = 0,
	INITIATE,
	PADAWAN,
	KNIGHT_ASPIRANT,
	KNIGHT,
	MASTER,
	BATTLE_MASTER,
	GRAND_MASTER

};




class Jedi {
	
private:
	std::string name;
	RANK rank;
	size_t age;
	std::string saberColor;
	double strength;
	
	static RANK ranks[NUM_RANKS];

	
public:
	Jedi() = default;
	Jedi(const std::string& nameParam, const RANK &rankParam, const size_t & ageParam, 
		const std::string &saberColorParam, const double& strengthParam );
	Jedi& operator= (const Jedi& other) = default;

	void print() const;
	void printRank() const;
	void promote(double multiplier);
	void demote(double multiplier);

	const std::string getName()const;
	static int getRank(const RANK r);
	RANK getRank()const;
	double getStrength()const;
	
	size_t getAge()const;
	const std::string getSaborColor() const;

	bool operator< (const Jedi& j2) const;
	bool operator>	(const Jedi& j2) const ;

	friend std::ostream& operator<<(std::ostream& out, const Jedi & j);
	friend std::istream& operator>>(std::istream& in, Jedi& j);

};


	

#endif // !__JEDI
