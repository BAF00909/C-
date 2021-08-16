#pragma once
#include <iostream>
#include <fstream>
#include <optional>
#include <tuple>
#include <vector>
#include <algorithm>
#include <iomanip>


using namespace std;

struct Person {
	string Family;
	string Name;
	optional<string> Patronymic;
};

struct PhoneNumber
{
	int CountryCode;
	int PostCode;
	string Number;
	optional<int> AdditionalNumber;
};

class PhoneBook
{
private:
	vector<pair<Person, PhoneNumber>> RecordBook;
	void GetRecords(string& str, string& str2);
public:
	PhoneBook(ifstream& file);
	void SortByName();
	void SortByPhone();
	void GetPhoneNumber();
	void ChangePhoneNumber(Person person, PhoneNumber number);

	friend ostream& operator<< (ostream& output, const PhoneBook& book);
	friend ostream& operator<< (ostream& output, const PhoneNumber& Phone);
	friend ostream& operator<< (ostream& output, Person& person);
	friend const bool& operator== (const Person& person1, const Person& person2);
};
