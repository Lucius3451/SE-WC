/*
#include <iostream>
#include <string>
//#include <ifstream>
//#include <ofstream>
#include <cctype>
#include <vector>
#include <fstream>
*/ 
#include "Thistime.h"
using namespace std; 
/* 
bool Blank_Cheack(string s);
int Count_ch(vector<string> s);
int Count_word(vector<string> s);
void Count_Special(vector<string> s);
*/ 
int main(int argc, char* argv[])
{
	//检查输入情况
	if (argc == 2)
	{
		if (argv[1] == "-x")
			system("E:\\桌面\\课程\\2018学年\\秋季-大三上\\软件工程\\ShowTxt.exe");	
	}
	else if (argc == 3)
	{
		ifstream infile;
		infile.open(argv[2]);
		string aline;
		vector<string> copy;
		int lines;
		int characters;
		int words;
		if (!infile.is_open())
		{
			cout << "Could't open" << argv[2] << endl;
			cout << "Program terminating" << endl;
		}
		for (lines = characters = words = 0; getline(infile, aline); lines++)
			copy.push_back(aline);
			
		string choose = argv[1];
		if (choose == "-c")
		{
			cout << argv[2] << "has" << Count_ch(copy) << "characters." << endl;
		}
		else if (choose == "-w")
		{
			cout << argv[2] << "has" << Count_word(copy) << "words." << endl;
		}
		else if (choose == "-l")
		{
			cout << argv[2] << "has" << copy.size() << "lines." << endl;
		}
		else if (choose == "-s")
		{
			cout << "Sry, This feature has not been developed." << endl;
		}
		else if (choose == "-a")
		{
			Count_Special(copy);
		}
		else
		{
		cout  << "The number of parameter is wrong." << endl;
		cout  << "Please re-enter" << endl;
		}
		infile.close();		
	}
	else
	{
		cout << argc << "~" << endl;
		cout << "The number of parameter is wrong." << endl;
		cout << "Please re-enter" << endl;
	}
	cout << "Done" << endl; 
    return 0;
}

/* 
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
*/ 
