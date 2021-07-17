#include "YandexParse.h"
#include <string>


YandexParse::YandexParse(string path) {
	ifstream page(path);
	int usdPos;
	int euroPos;
	string find_str = "inline-stocks__value_inner\">";

	if (!page) {
		cerr << "File didn't open" << endl;
		exit(1);
	}

	while (getline(page, pageInner))
	{
		if (pageInner.find(find_str) != string::npos)
		{
			usdPos = pageInner.find(find_str);
			cout << "USD: "  << pageInner.substr(usdPos + find_str.size(), 5) << endl;
			euroPos = pageInner.find(find_str, usdPos + find_str.size());
			cout << "EURO: " << pageInner.substr(euroPos + find_str.size() , 5) << endl;
		}
	}
};
