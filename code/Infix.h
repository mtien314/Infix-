#pragma once
#include<iostream>
#include<vector>
using namespace std;




class Infix {
public:
	Infix() {};
	int Precedence(string x);
	int Check(string x);
	string calculate(string x1, string x, string x2);
	string calculate2(string x, string y);
	void Infix1(vector<string> A);
	void SplitSTring(string k, vector<string>& A);
	~Infix() {};
};

