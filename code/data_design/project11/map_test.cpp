#include <map>
#include "string"
#include "iostream"

using namespace std;
int main()
{
	typedef map<int, string> UDT_MAP_INT_CSTRING;

	UDT_MAP_INT_CSTRING enumMap;

	for (int i = 0; i < 3; i++)
	{
		enumMap.insert(map<int, string>::value_type(i, "test"));
	}

	UDT_MAP_INT_CSTRING::iterator it;
	int i = 0;
	for (it = enumMap.begin(); it != enumMap.end(); it++)
	{
		cout << enumMap << endl;
	}


	//string s = enumMap[2];


	cin.get();



}