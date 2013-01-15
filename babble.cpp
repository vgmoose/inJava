#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

int countTabs(string a, int pos)
{
	if (a[pos] == '\t')
		return 1+countTabs(a, 1+pos);
	else
		return 0;
}

int lineIsEmpty(string a)
{
	int x;
	for (x=0; x<a.length(); x++)
		if (!isspace(a[x]))
			return 0;
	return 1;
}

void fillTabs(int tabs)
{
	int x;
	for (x=0; x<tabs; x++)
		cout << "\t";
}

int main()
{
	ifstream fin;
	fin.open("data.injava");
	if (!fin.good())
		return 1;
	
	int numberOfTabs, previousTabCount=0;

	while (!fin.eof())
	{
		string buf;
		getline(fin, buf);

		if (!lineIsEmpty(buf))
		 {
			numberOfTabs = countTabs(buf, 0);

			if (numberOfTabs < previousTabCount)
			{
				previousTabCount--;
				cout << "\n";
				fillTabs(previousTabCount);
				cout << "}\n" << buf;
			}

			else if (numberOfTabs == previousTabCount)
				cout << "\n" << buf; 

			else
			{
				cout << "\n";
				fillTabs(previousTabCount);
				previousTabCount++;
				cout << "{\n" << buf;
			}
		}
		else
			cout << "\n";

	}
	
	for (; previousTabCount>0; previousTabCount--)
	{
		fillTabs(previousTabCount-1);
		cout << "}\n";
	}

	return 0;
}
