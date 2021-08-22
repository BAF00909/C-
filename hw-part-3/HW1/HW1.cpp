#include <iostream>
#include <fstream>
#include <optional>
#include "Task3.h"

using namespace std;

//ostream& operator<< (ostream& output, const PhoneNumber& Phone)
//{
//    if (Phone.AdditionalNumber == nullopt)
//        return output << "+" << Phone.CountryCode << " (" << Phone.PostCode << ") " << Phone.Number;
//    else
//        return output << "+" << Phone.CountryCode << " (" << Phone.PostCode << ") " << Phone.Number << " " << *Phone.AdditionalNumber << endl;
//}
//ostream& operator<< (ostream& output, Person& person)
//{
//    if (person.Patronymic == nullopt)
//        return output << person.Family << " " << person.Name;
//    else
//        return output << person.Family << " " << person.Name << " " << *person.Patronymic;
//}
//
//const bool& operator== (const Person& person1, const Person& person2)
//{
//    return tie(person1.Name, person1.Name, person1.Patronymic) == tie(person2.Name, person2.Name, person2.Patronymic);
//}


int main()
{
    ///*Task 1*/
    //Person me;
    //me.Family = "Breus";
    //me.Name = "Alexandr";
    //me.Patronymic = "Fedorovich";
    //cout<< me << endl;

    //Person he;
    //he.Family = "Breus";
    //he.Name = "Alexandr";
    //cout << he << endl;

    //bool eq = me == he;
    //cout << eq << endl;

    ///*Task 2*/
    //PhoneNumber myPhoneNumber;
    //myPhoneNumber.CountryCode = 7;
    //myPhoneNumber.PostCode = 960;
    //myPhoneNumber.Number = "893-25-66";
    //myPhoneNumber.AdditionalNumber = 12;
    //cout << myPhoneNumber << endl;

    /*Task 3*/
    ifstream file("phoneBook.txt");
    PhoneBook pB(file);
    cout << pB << endl;
    //pB.SortByName();
    //pB.SortByPhone();
    //cout << pB << endl;
   // pB.GetPhoneNumber();
    pB.ChangePhoneNumber(Person{ "Ilin", "Petr", "Artemovich" }, PhoneNumber{ 16, 465, "9155448", 13 });
    cout << pB << endl;

    return 0;
}

