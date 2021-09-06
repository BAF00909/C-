#include <string>


#include "Task3.h"


using namespace std;

ostream& operator<< (ostream& output, const PhoneNumber& Phone)
{
	if (Phone.AdditionalNumber == nullopt)
		return output << "+" << Phone.CountryCode << " (" << Phone.PostCode << ") " << Phone.Number << endl;
	else
		return output << "+" << Phone.CountryCode << " (" << Phone.PostCode << ") " << Phone.Number << " " << *Phone.AdditionalNumber << endl;
}

ostream& operator<< (ostream& output, const Person& person)
{
	if (person.Patronymic == nullopt)
		return output << left << setw(15) << person.Family << setw(15) << person.Name << setw(26) << " ";
	else
		return output << left << setw(15) << person.Family << setw(15) << person.Name << " " << setw(25) << *person.Patronymic;
}

const bool& operator== (const Person& person1, const Person& person2)
{
	return tie(person1.Name, person1.Name, person1.Patronymic) == tie(person2.Name, person2.Name, person2.Patronymic);
}

ostream& operator<< (ostream& output, const PhoneBook& book)
{
	for (size_t i = 0; i < book.RecordBook.size(); i++)
	{
		output << book.RecordBook[i].first << book.RecordBook[i].second << endl;
	}
	return output;

}

string GenerateStringPhone(PhoneNumber& phone) {
	if (phone.AdditionalNumber != nullopt)
	{
		return to_string(phone.CountryCode) + to_string(phone.PostCode) + phone.Number + to_string(phone.AdditionalNumber.value());
	}
	else
	{
		return to_string(phone.CountryCode) + to_string(phone.PostCode) + phone.Number;
	}
}


void PhoneBook::GetRecords(string& str, string& str2)
{

	string substring;
	string::size_type prev_pos = 0, pos = 0;
	vector<string> strTmpl;
	Person PersonTmpl;
	PhoneNumber PhoneNumberTmpl;

	string CountryCode;
	string PostCode;
	string Number;
	string AdditionalNumber;

	while ((pos = str.find(' ', pos)) != string::npos)
	{
		substring = str.substr(prev_pos, pos - prev_pos);
		strTmpl.push_back(substring);
		prev_pos = ++pos;
	}
	if (strTmpl.size() < 3) {
		PersonTmpl = { strTmpl[0] ,strTmpl[1] };
	}
	else
	{
		PersonTmpl = { strTmpl[0] ,strTmpl[1] ,strTmpl[2] };
	}

	CountryCode = str2.substr( 1, str2.find('(')-1 );
	PostCode = str2.substr(	str2.find('(')+1, (str2.find(')')-1) - str2.find('('));
	Number = str2.substr( str2.find(')') + 1, str2.find(' ') - str2.find(')') );

	PhoneNumberTmpl.CountryCode = stoi(CountryCode);
	PhoneNumberTmpl.PostCode = stoi(PostCode);
	PhoneNumberTmpl.Number = Number;

	if (str2.find(' ') != -1)
	{
		AdditionalNumber = str2.substr(str2.find(' ') +1);
		PhoneNumberTmpl.AdditionalNumber = stoi(AdditionalNumber);
	}
	RecordBook.push_back(make_pair(PersonTmpl, PhoneNumberTmpl));
}

PhoneBook::PhoneBook(ifstream& file)
{
	string Line;
	int PlusPosition;

	if (file.is_open())
	{
		while (getline(file, Line)) {
			PlusPosition = Line.find("+");
			string FioPart = Line.substr(0, PlusPosition);
			string PhonePart = Line.substr(PlusPosition);
			GetRecords(FioPart, PhonePart);
		}
	}
}

void PhoneBook::SortByName()
{
	sort(RecordBook.begin(), RecordBook.end(), [](auto& p1, auto& p2) {
		if (p1.first.Family != p2.first.Family)
		{
			return p1.first.Family < p2.first.Family;
		}
		else if (p1.first.Name != p2.first.Name)
		{
			return p1.first.Name < p2.first.Name;
		}
		else if ((p1.first.Patronymic != p2.first.Patronymic) && (p1.first.Patronymic && p2.first.Patronymic))
		{
			return p1.first.Patronymic < p2.first.Patronymic;
		}
	});
}

void PhoneBook::SortByPhone()
{
	sort(RecordBook.begin(), RecordBook.end(), [](auto& p1, auto& p2) {
		return GenerateStringPhone(p1.second) < GenerateStringPhone(p2.second);
		});
		
}

void PhoneBook::GetPhoneNumber()
{
	string Search;
	int NumbersCount = 0;
	cout << "Input Family: ";
	getline(cin, Search);

	for_each(RecordBook.begin(), RecordBook.end(), [Search, &NumbersCount](auto& pair) mutable {
			if (pair.first.Family == Search)
			{
				NumbersCount++;
				cout << pair.second << endl;
			}
		});
	if (NumbersCount == 0) cout << "not founded!";
	else if (NumbersCount > 1) cout << "found more than 1";
}

void PhoneBook::ChangePhoneNumber(Person person, PhoneNumber number)
{
	auto result = find_if(RecordBook.begin(), RecordBook.end(), [&person, &number](auto &pair){
		if (pair.first == person)
		{
			pair.second = number;
		}
		return pair.first == person;
		});

}
