#include "Calculation.h"


//Dijkstra's two-stack algorithm


int precedence(char op)
{
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	if (op < 0) return 3;
	if (op == '^') return 4;
	return 0;
}

long double apply(long double a, long double b, char op)
{
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
	if (op == '/') return a / b;
	if (op == '^') return pow(a, b);
	return 0;
}
void applyTop(std::stack<long double>& values, std::stack<char>& ops)
{
	char op = ops.top();
	ops.pop();

	if (op < 0)
	{
		auto a = values.top();
		values.pop();

		if (-op == '-')
			values.push(-a);
		else
			values.push(a);
	}
	else
	{
		auto b = values.top(); values.pop();
		auto a = values.top(); values.pop();

		values.push(apply(a, b, op));
	}
}

std::string calculate(std::string str)
{
	if (str.empty()) return "0.0";

	bool isValid = 1;
	char prev = 'a';
	std::stack<char>bracketSequence;
	for (char ch : str) {
		if (ch == '(') bracketSequence.push(ch);
		else if (ch == ')') {
			if (bracketSequence.size()) bracketSequence.pop();
			else {
				isValid = 0;
				break;
			}
		}

		if (prev != 'a' && (ch == '*' || ch == '/' || ch == '^') && !isdigit(prev)) {
			isValid = 0;
			break;
		}
		else if (prev != 'a' && ((ch == '(' && isdigit(prev)) || (prev == ')' && isdigit(ch)))) {
			isValid = 0;
			break;
		}
		else if (prev != 'a' && ((prev == '(' && precedence(ch) > 1) || (ch == ')' && precedence(prev) > 0))) {
			isValid = 0;
			break;
		}
		else if (prev == 'a' && precedence(ch)>1) {
			isValid = 0;
			break;
		}
		prev = ch;
	}
	if (str.back() != ')' && !isdigit(str.back()) || bracketSequence.size())
		isValid = 0;

	if (!isValid) return "0.00";

	std::stack<long double> values;
	std::stack<char> ops;
	bool expectedOperand = true;

	for (long i = 0; i < (long)str.size(); i++)
	{
		char c = str[i];

		if ((c == '+' || c == '-') && expectedOperand) {
			ops.push(-c);
			continue;
		}
		else if (isdigit(c) || c == '.')
		{
			std::string num = "";
			while (i < str.size() && (isdigit(str[i]) || str[i] == '.'))
			{
				num += str[i];
				i++;
			}
			i--;
			long double value = std::stold(num);
			values.push(value);
			expectedOperand = 0;
		}
		else if (c == '(')
			ops.push(c), expectedOperand = 1;
		else if (c == ')') {
			while (ops.top() != '(')
				applyTop(values, ops);

			ops.pop();
			expectedOperand = 0;
		}
		else
		{
			expectedOperand = 1;
			while (!ops.empty() && precedence(ops.top()) >= precedence(c))
				applyTop(values, ops);
			ops.push(c);
		}
	}
	while (!ops.empty())
		applyTop(values, ops);

	std::string ans = std::to_string(values.top());
	while (ans.back() == '0')
	{
		ans.pop_back();
		if (ans.back() == '.') {
			ans.pop_back();
			break;
		}
	}
	return std::to_string(values.top());
}