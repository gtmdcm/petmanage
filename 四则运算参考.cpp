#include"RPN.h"
#include<string>
int main()
{
	string s;
	cin >> s;
	convert2RPN(s);
	cout << calculateRPN(s) << endl;
	system("pause");
	return 0;
}