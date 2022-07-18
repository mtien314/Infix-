#include <iostream>
#include"Stack.h"
#include"Infix.h"
using namespace std;


int main()
{
	string x;
	cout << "Input: ";
	getline(cin, x);
	vector<string> A;
	Infix p;
	p.SplitSTring(x, A);
	p.Infix1(A);
	return 0;
}