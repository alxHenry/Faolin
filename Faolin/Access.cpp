//Implementation for the accessory class

#include "Access.h"
using namespace std;

Access::Access(string name_in, vector<string> modifiers_in)
{
	name = name_in;
	modifiers = modifiers_in;
}
Access::~Access()
{}

string Access::get_name() const
{
	return name;
}
vector<string> Access::get_modifiers() const
{
	return modifiers;
}
