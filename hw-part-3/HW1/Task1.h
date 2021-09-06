#pragma once
#include <iostream>
#include <optional>

using namespace std;

struct Person {
	string Family;
	string Name;
	optional<string> Patronymic;
};

ostream& operator<< (ostream& output, Person& person)
{
    if (person.Patronymic == nullopt)
        return output << person.Family << " " << person.Name;
    else
        return output << person.Family << " " << person.Name << " " << *person.Patronymic;
}

const bool& operator== (const Person& person1, const Person& person2)
{
    return tie(person1.Name, person1.Name, person1.Patronymic) == tie(person2.Name, person2.Name, person2.Patronymic);
}
