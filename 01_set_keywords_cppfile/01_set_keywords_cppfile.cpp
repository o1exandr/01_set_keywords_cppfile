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
	set<string> template_set { "auto", "break", "case", "catch", "char", "class", "const", "continue", "default", "delete", "do",
		"double", "else", "enum", "extern", "float", "for", "friend", "goto", "if", "inline", "int", "long", "new", "operator", "private", 
		"protected", "public", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "template", 
		"this", "throw", "try",	"typedef", "union", "unsigned", "virtual", "void", "volatile", "while"	};
	set<string> find_set {"true", "try", "London" };
	//find_set.insert("rat");
	
	ifstream file("01_fibonacci_generate.cpp", ios::out);
	if (!file.is_open())
	{
		cerr << "File not found/n";
		return 0;
	}
	int count = 0;
	while (!file.eof())
	{
		string str;
		getline(file, str);
		cout << " (" << ++count << ") " << str << endl;
		/*if (str != "")
		{
			string tmp = "";
			for (int i = 0; i < str.length(); ++i)
			{
				if (str[i] != ' ')//  && str[i] != ';' && str[i] != '.' && str[i] != '<' && str[i] != '>', str[i] != ','  && str[i] != '(' && str[i] != ')' && str[i] != '#' && str[i] != '\0')
				{
					tmp += str[i];
					//cout << "str" << str[i];
					//cout << tmp << "-->";
				}
				else
				{
					find_set.insert(tmp);
					cout << "tmp" << tmp << endl;
					tmp = "";
					cout << endl;
				}

			}
		}*/
	}

	file.close();
	


	ostream_iterator<string, char> out(cout, "\t");
	//cout << "\nSet A:\t";
	copy(template_set.begin(), template_set.end(), out);
	cout << "\n- - - - - - -\n";
	copy(find_set.begin(), find_set.end(), out);
	cout << "\n- - - - - - -\n";
	//cout << "\nSet B:\t";
	//copy(B.begin(), B.end(), out);
	//cout << "\nUnion A + B:\t";
	//set_union(A.begin(), A.end(), B.begin(), B.end(), out, greater<int>()); //зливається
	//cout << "\nIntersection A * B:\t";
	//set_intersection(A.begin(), A.end(), B.begin(), B.end(), out, greater<int>()); // виводить спільні елементи
	//cout << "\nDifference( A - B):\t";
	set_intersection(find_set.begin(), find_set.end(), template_set.begin(), template_set.end(), out, less<string>()); //виводить унікальні елементи першого списку
	cout << endl;



	system("pause");
	return 0;
}