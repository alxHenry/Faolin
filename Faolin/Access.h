//Header for the Accessory class

#ifndef ACCESS_H_INCLUDED
#define ACCESS_H_INCLUDED

#include <string>
#include <vector>
using namespace std;

class Access
{
public:
	Access(string name_in, vector<string> modifiers_in);
	~Access();

	string get_name() const;
	vector<string> get_modifiers() const;

private:
	//String of modifiers, i.e.: First element is "hp", second is "20", inreases HP of player by 20.
	vector<string> modifiers;
	string name;
	
};

#endif