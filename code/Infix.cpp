#include"Infix.h"
#include"Stack.h"






//_do uu tien toan tu 
int Infix::Precedence(string x)
{
	if (x == "sqrt" || x == "sin" || x == "cos" || x == "tan" || x == "exp" || x == "log")
		return 3;
	if (x == "*" || x == "/" || x == "%" || x == "^")
		return 2;
	else if (x == "+" || x == "-")
		return 1;
	else if (x == "(")
		return 0;

	return -1;
}


//kiem tra toan hang hay toan tu
int Infix::Check(string x)
{
	if (x == "sqrt" || x == "sin" || x == "cos" || x == "tan" || x == "exp" || x == "log") {
		return 3;
	}
	if (x == "*" || x == "/" || x == "%" || x == "+" || x == "-" || x == "^") {
		return 2;
	}
	else {
		return 1;
	}

}

//-----------Tinh bieu thuc--------------
string Infix::calculate(string x2, string x, string x1)
{
	float s = 0;
	float num1 = atof(x1.c_str());
	float num2 = atof(x2.c_str());
	if (x == "^")
	{
		s = 1;
		for (int i = 1; i <= int(num1); i++)
			s = s * num2;
	}
	else if (x == "%")
		s = int(num2) % int(num1);
	else if (x == "*")
		s = num2 * num1;
	else if (x == "/")
		s = num2 / num1;
	else if (x == "+")
		s = num2 + num1;
	else if (x == "-")
		s = num2 - num1;
	string result = to_string(s);
	return result;
}

string Infix::calculate2(string x, string y) {
	float result = 0;
	float num = atof(x.c_str());
	if (y == "sqrt") {
		if (num < 0) {
			result =0;
		}
		else {
			result = sqrt(num);
		}
	}
	else if (y == "sin") {
		result = sin(num);
	}
	else if (y == "cos") {
		result = cos(num);
	}
	else if (y == "tan") {
		result = tan(num);
	}
	else if (y == "log") {
		result = log(num);
	}
	else if (y == "exp") {
		result = exp(num);
	}
	string s = to_string(result);
	return s;
}

//--------------Tinh bieu thuc trung to--------------------
void Infix::Infix1(vector<string>A)
{
	Stack* X = new Stack();
	Stack* Y = new Stack();
	Stack* Z = new Stack();
	int k = 0;
	int n = A.size();
	for (int i = 0; i < n; i++) {
		switch (Check(A[i])) {
		case 1:

			if (A[i] != "(" && A[i] != ")") {
				X->Push(A[i]);
			}
			else if (A[i] == "(") {
				Y->Push(A[i]);
			}
			else if (A[i] == ")") {
				if (k == 1 ) {
					if (!Y->IsEmpty()&& Y->GetHead()->Data!="(") {
						string a = X->Pop();
						string b = Y->Pop();
						string c = X->Pop();
						X->Push(calculate(c, b, a));
						Y->Pop();
					}
					while (!Z->IsEmpty()){
						string a = X->Pop();
						string c = Z->Pop();
						X->Push(calculate2(a,c));
						k = 0;
						
					}
					Y->Pop();
					
				}
				 else {
					 while (Y->GetHead()->Data != "(")
					 {
						 string a = X->Pop();
						 string x = Y->Pop();
						 string b = X->Pop();
						 X->Push(calculate(b, x, a));
					 }
					 Y->Pop();
				 }
				
			}
			break;
		case 2:
			while (!Y->IsEmpty() && (Precedence(A[i]) <= Precedence(Y->GetHead()->Data))) {
				string a = X->Pop();
				string x = Y->Pop();
				string b = X->Pop();
				X->Push(calculate(b, x, a));
			}
			Y->Push(A[i]);
			break;
		case 3:
			k = 1;
			Z->Push(A[i]);
			break;
		}
	}
	while (!Y->IsEmpty()) {
		string a = X->Pop();
		string x = Y->Pop();
		string b = X->Pop();
		X->Push(calculate(b, x, a));
	}
	string s = X->Pop();
	cout << "Answer: " << s << endl;
}

//Phan tach phan tu trong chuoi vao mang 
void Infix::SplitSTring(string k, vector<string>& A)
{
	int x2 = 0;
	int n = k.length();
	int count = 0;
	int x1 = 0;
	int y = 0;
	int error = 0;
	for (int i = 0; i < n; i++)
	{
		if ((k[i] >= '0' && k[i] <= '9') || (k[i] >= 'a' && k[i] <= 'z'))
		{

			if (i < n - 1)
			{
				for (int j = i + 1; j < n; j++) {
					if (k[i] >= 'a' && k[i] <= 'z') {
						x2 = 1;
					}
					if (
						k[j] == ')' || k[j] == '*' || k[j] == '/' ||
						k[j] == '+' || k[j] <= '-' || k[j] == '%' ||
						k[j] == '^') {
						y = j + 1;
						x1 = j + 1;
						if (k[y] == '+' or k[y] == '-') {
							if (k[y] == '+' && k[j] == '+') {
								error = 1;
							}
							else if ((k[y] == '+' && k[j] == '-') or (k[y] == '-' && k[j] == '+')) {
								
								A.push_back(k.substr(i, y - i-1));
								i = y - 1;
								count = 0;
							}
							else{
								k[j] = '+';
								k[y] = ' ';
								A.push_back(k.substr(i, j - i));
								i = j - 1;
								count = 0;
							}
							
						}
						else {
							A.push_back(k.substr(i, j - i));
							i = j - 1;
							count = 0;
						}
						break;
					}
					else {
						if ((k[i] >= '0' && k[i] <= '9') && (k[j] >= '0' && k[j] <= '9')) {
							count++;
						}
					}
				}
			}
			else {
				if (count >= 1) {
					if (x2 == 1) {
						A.push_back(k.substr(x1 + 1, n - 1));
					}
					else {
						A.push_back(k.substr(x1, n - 1));
					}
				}
				else {
					A.push_back(k.substr(i, n - 1));

				}
			}

		}
		if (error == 1) {
			cout << "error" << endl;
			break;
		}
		else {
			if (
				k[i] == '(' || k[i] == ')' || k[i] == '*' || k[i] == '/' ||
				k[i] == '+' || k[i] == '-' || k[i] == '%' || k[i] == '^') {
				string temp(1, k[i]);
				A.push_back(temp);

			}
		}
	}
}