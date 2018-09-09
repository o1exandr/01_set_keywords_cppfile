/*
Завдання  1.
Створити програму, яка створює множину(set) службових слів С++(if, switch, …), 
що зустрілися у текстовому файлі з програмою С++.
*/

//#include "stdafx.h"
#include "pch.h"
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>




using namespace std;


//using Pair = pair<char, int>;

int main()
{
	set<string> template_set { "auto", "break", "case", "catch", "char", "class", "const", "continue", "default", "delete", "do",
		"double", "else", "enum", "extern", "float", "for", "friend", "goto", "if", "inline", "int", "long", "new", "operator", "private", 
		"protected", "public", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "template", 
		"this", "throw", "try",	"typedef", "union", "unsigned", "virtual", "void", "volatile", "while"	};
	set<string> find_set {"true", "try", "London" };
	//find_set.insert("rat");
	string str;
	string tmp = {};
	ifstream file("01_fibonacci_generate.cpp");
	if (!file)		
	{
		cerr << "File not found/n";
		return 0;
	}
	while (getline(file, str))
	{
		for (int i = 0; i < str.length(); ++i)
		{
			if (str[i] != '.')//  && str[i] != ';' && str[i] != '.' && str[i] != '<' && str[i] != '>', str[i] != ','  && str[i] != '(' && str[i] != ')' && str[i] != '#' && str[i] != '\0')
			{
				tmp += str[i];
				cout << str[i];
				//cout << tmp << "-->";
			}
			else
			{
				find_set.insert(tmp);
				cout << tmp << endl;
				tmp = {};
				cout << endl;
			}

		}
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



	//system("pause");
	//return 0;
}