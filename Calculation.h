#pragma once
#include<string>
#include<stack>

std::string calculate(std::string str);
int precedence(char op);
long double apply(long double a, long double b, char op);
void applyTop(std::stack<long double>& values, std::stack<char>& ops);