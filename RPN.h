#include <iostream>  
#include <cctype>  
#include <cstdlib>  
#include <stack>  
#include <sstream>  
using namespace std;

void convert2RPN(string &s) {
	stringstream ss;
	stack<char> stk;
	for (size_t i = 0; i < s.length(); i++) {
		if (isdigit(s.at(i))) {
			ss << s.at(i);
			if ((i < s.length() - 1 && !isdigit(s.at(i + 1)))
				|| i == s.length() - 1) {
				ss << ' ';
			}
		}
		else {
			if (stk.empty()) {
				stk.push(s.at(i));
			}
			else {
				switch (s.at(i)) {
				case '(':
					stk.push(s.at(i));
					break;
				case ')':
					while (stk.top() != '(') {
						ss << stk.top();
						stk.pop();
					}
					stk.pop();
					break;
				case '+':
				case '-':
					while (!stk.empty() && stk.top() != '(') {
						ss << stk.top();
						stk.pop();
					}
					stk.push(s.at(i));
					break;
				case '*':
				case '/':
					while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
						ss << stk.top();
						stk.pop();
					}
					stk.push(s.at(i));
					break;
				}
			}
		}
	}
	while (!stk.empty()) {
		ss << stk.top();
		stk.pop();
	}
	s = ss.str();
}

float calculateRPN(const string &s) {
	stack<float> stk;
	for (size_t i = 0; i < s.length(); i++) {
		if (isdigit(s.at(i))) {
			int e = atoi(&s.at(i));
			int t = e / 10;
			while (t > 0) {
				i++;
				t /= 10;
			}
			i++;
			stk.push(e);
		}
		else {
			float r = stk.top();
			stk.pop();
			float l = stk.top();
			stk.pop();
			float result;
			switch (s.at(i)) {
			case '+':
				result = l + r;
				break;
			case '-':
				result = l - r;
				break;
			case '*':
				result = l * r;
				break;
			case '/':
				result = l / r;
				break;
			}
			stk.push(result);
		}
	}
	return stk.top();
}
