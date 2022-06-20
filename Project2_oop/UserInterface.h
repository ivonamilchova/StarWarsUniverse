#ifndef __USER_INTERFACE
#define __USER_INTERFACE
#include "StarWarsUniverse.h"
void reverseStr(std::string& s);
size_t strToSizeT(std::string& s);
double strToDouble(std::string& s);
RANK strToRank(const std::string& s);
std::string rankTostr(const RANK r);


void toCapitalLetters(std::string& s);



class UserInterface {
private:
	StarWarsUniverse starWarsUniverse;
	void sliptString(const std::string& command, std::vector<std::string>& args, const char delimiter) const;
public:

	void help() const;
	void run();
};

#endif // !__USER_INTERFACE
