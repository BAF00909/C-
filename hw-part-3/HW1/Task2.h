#pragma once
#include <iostream>
#include <optional>

using namespace std;

struct PhoneNumber
{
	int CountryCode;
	int PostCode;
	string Number;
	optional<int> AdditionalNumber;
};

ostream& operator<< (ostream& output ,const PhoneNumber& Phone)
{
	if (Phone.AdditionalNumber == nullopt)
		return output << "+" << Phone.CountryCode << " (" << Phone.PostCode << ") " << Phone.Number;
	else
		return output << "+" << Phone.CountryCode << " (" << Phone.PostCode << ") " << Phone.Number << " " << *Phone.AdditionalNumber << endl;
}