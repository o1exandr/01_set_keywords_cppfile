/*
Завдання  1.
Створити програму, яка створює множину(set) службових слів С++(if, switch, …), 
що зустрілися у текстовому файлі з програмою С++.
*/

//#include "stdafx.h"
#include "pch.h"
#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>




using namespace std;

int main()
{
	set<string> template_set { "auto", "break", "case", "cin", "cout", "catch", "char", "copy", "class", "const", "continue", "default", "delete", "do",
		"double", "else", "endl", "enum", "extern", "float", "for", "friend", "goto", "if", "inline", "int", "long", "main", "new", "operator", "private", 
		"protected", "public", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "template", 
		"this", "throw", "try",	"typedef", "union", "unsigned", "virtual", "void", "volatile", "while"	};
	set<string> find_set {};
	
	ifstream file("file.cpp");
	if (!file.is_open())
	{
		cerr << "File not found\n";
		system("pause");
		return 0;
	}

	string str;
	string tmp = "";
	while (!file.eof())
	{
		getline(file, str);
		if (str != "")
		{
			for (int i = 0; i < str.length() - 1; ++i)
			{
				if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90))
				{
					tmp += str[i];
				}
				else
				{
					find_set.insert(tmp);
					tmp = "";
				}

			}
		}
	}

	file.close();
	
	ostream_iterator<string, char> out(cout, "\t");
	cout << "\ttemplate_set:\n";
	copy(template_set.begin(), template_set.end(), out);
	cout << "\n- - - - - - -\n\n\tfind_set:\n";
	copy(find_set.begin(), find_set.end(), out);
	cout << "\n- - - - - - -\n\n";
	cout << "\tWords of C++ from file:\n";
	set_intersection( find_set.begin(), find_set.end(), template_set.begin(), template_set.end(), out, less<string>()); 
	cout << endl;



	system("pause");
	return 0;
}