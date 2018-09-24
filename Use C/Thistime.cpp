#include <iostream>
#include <string>
//#include <ifstream>
//#include <ofstream>
#include <cctype>
#include <vector>
#include <fstream>
//#include "Thistime.h"
using namespace std; 


bool Blank_Cheack(string s)
{
	if (!s.empty())
	{
		int i, len, prv;
		for (i = prv = 0, len = s.size(); i < len; i++)
		{
			if (s[i] != ' ' && (s[i] < 0 || s[i] > 31) && s[i] != 127)
			{
				if (prv)
					return false;
				else
					prv = 1;
			}
		}
	}
	return true;
}
int Count_ch(vector<string> s)
{
	if (s.empty())
		return 0;
	int len, i, j, lines, count;
	for (i = count = 0, lines = s.size(); i < lines; i++)
		for (len = s[i].size(), j = 0; j < len; j++)
		{
			if (isalnum(s[i][j]))
				count++;
		}
		
	return count;
}
int Count_word(vector<string> s)
{
	if (s.empty())
		return 0;
	int len, i, count, lines, j;
	for (i = count = 0, lines = s.size(); i < lines; i++)
	{
		for (len = s[i].size(), j = 0; j < len; j++)
		{
			if (isalnum(s[i][j]) && !isalnum(s[i][j + 1]))
				count++;
		}
		if (isalnum(s[i][j]) && isalnum(s[i][j - 1]))
			count++;
	}
	
	return count;
}
void Count_Special(vector<string> s)
{
	if (!s.empty())
	{
		int lines, i, blank, remark, sp;
		for (i = blank = remark = sp = 0, lines = s.size(); i < lines; i++)
		{
			if (Blank_Cheack(s[i]))
			{
				blank++;
			} 
			else
			{
				sp++;
				if (s[i].find("//") != string::npos)
					remark++;
			}
			 
				
		}
		cout << "Blank lines:" << blank << endl;
		cout << "remark lines:" << remark << endl;
		cout << "code lines:" << sp << endl;
	}
	else
	{
		cout << "This file is empty." << endl;
	}
}














