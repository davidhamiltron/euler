


#include "String.h"
#include <sstream>

using namespace std;

string ToString(int i)
{
	stringstream ssInt;
	ssInt << i;
	return ssInt.str();
}

string ToString(__int64 i)
{
	stringstream ssInt;
	ssInt << i;
	return ssInt.str();
}


int ToInt(string s)
{
	return atoi(s.c_str());
}