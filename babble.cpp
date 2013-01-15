#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int countTabs(string a, int pos)
{
	if (a[pos] == '\t')
		return 1+countTabs(a, 1+pos);
	else
		return 0;
}

int main()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.good())
		return 1;

	while (!fin.eof())
	{
		string buf;
		getline(fin, buf);

		cout << buf << "\n";

	}

	return 0;
}
