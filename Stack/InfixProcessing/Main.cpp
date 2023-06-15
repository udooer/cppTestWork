#include <iostream>
#include <stack>
#include <cstring>
#include <cmath>

bool IsNumber(const char& c) 
{
	return c >= '0' && c <= '9';
}

bool IsOperand(const char& c) 
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'
		|| c == '(' || c == ')'
		|| c == '[' || c == ']'
		|| c == '{' || c == '}') 
	{
		return true;
	}
	
	return false;
}

bool IsLegal(const char& c) 
{
	return IsNumber(c) || IsOperand(c) || c == ' ';
}

bool CheckExpression(const char* expression, const int length)
{
	std::stack<char> bracketStack;
	for (int i = 0; i < length; i++) 
	{
		if (IsLegal(expression[i]) == false) 
		{
			return false;
		}

		if (IsOperand(expression[i])) 
		{
			if (expression[i] == '('
				|| expression[i] == '['
				|| expression[i] == '{') 
			{
				bracketStack.push(expression[i]);
			}
			else if (expression[i] == ')') 
			{
				if (bracketStack.top() == '(') 
				{
					bracketStack.pop();
				}
				else 
				{
					return false;
				}
			}
			else if (expression[i] == ']')
			{
				if (bracketStack.top() == '[')
				{
					bracketStack.pop();
				}
				else
				{
					return false;
				}
			}
			else if (expression[i] == '}')
			{
				if (bracketStack.top() == '{')
				{
					bracketStack.pop();
				}
				else
				{
					return false;
				}
			}
		}
	}

	if (bracketStack.empty()) 
	{
		return true;
	}

	return false;
}

bool IsC1HigherThanC2(const char& c1, const char& c2) 
{
	if ((c1 == '*' || c1 == '/') 
		&& (c2 == '+' || c2 == '-')) 
	{
		return true;
	}
	else if (c1 == '^' && c2 != '^') 
	{
		return true;
	}

	return false;
}

std::string ConvertInfixToPostfix(const std::string& infixString) 
{
	char* result = (char*)malloc(infixString.length()*2 + 1);
	int index = 0;
	std::stack<char> operandStack;

	for (int i = 0; i < infixString.length(); i++) 
	{
		if (infixString[i] == ' ')
		{
			continue;
		}
		else if (IsNumber(infixString[i]))
		{
			result[index++] = infixString[i];
		}
		else 
		{
			if (infixString[i] == ')'
				|| infixString[i] == ']'
				|| infixString[i] == '}') 
			{
				while (operandStack.top() != '(') 
				{
					result[index++] = operandStack.top();
					operandStack.pop();
				}
				operandStack.pop();
			}
			else if (infixString[i] == '('
				|| infixString[i] == '['
				|| infixString[i] == '{') 
			{
				operandStack.push('(');
			}
			else 
			{
				result[index++] = ',';
				while (operandStack.empty() == false
					&& operandStack.top() != '('
					&& IsC1HigherThanC2(operandStack.top(), infixString[i])) 
				{
					result[index++] = operandStack.top();
					operandStack.pop();
				}
				operandStack.push(infixString[i]);
			}
		}
	}

	while (operandStack.empty() == false) 
	{
		result[index++] = operandStack.top();
		operandStack.pop();
	}

	result[index] = '\0';
	std::string resultString(result);
	free(result);

	return resultString;
}

double ProcessingPostfix(const std::string& postfix) 
{
	std::stack<double> numberStack;
	bool notPush = false;
	for (int i = 0; i < postfix.length(); i++) 
	{
		if (postfix[i] == ',')
		{
			notPush = false;
			continue;
		}

		if (IsNumber(postfix[i])) 
		{
			if (notPush == false) 
			{
				numberStack.push(atoi(&postfix[i]));
				notPush = true;
			}
		}
		else 
		{
			notPush = false;
			int c2 = numberStack.top();
			numberStack.pop();
			int c1 = numberStack.top();
			numberStack.pop();

			std::cout << "c1: " << c1 << ", c2: " << c2 << ", operator: " << postfix[i] << std::endl;

			switch (postfix[i]) 
			{
			case '+':
			{
				numberStack.push(c1 + c2);
			}
			break;
			case '-':
			{
				numberStack.push(c1 - c2);
			}
			break;
			case '*':
			{
				numberStack.push(c1 * c2);
			}
			break;
			case '/':
			{
				numberStack.push((double)c1 / c2);
			}
			break;
			case '^':
			{
				numberStack.push(std::pow(c1, c2));
			}
			break;
			}
		}
	}

	return numberStack.top();
}

int main() 
{
	while (true) 
	{
		std::string userInput;
		std::getline(std::cin, userInput);

		if (userInput.length() == 0) 
		{
			std::cout << "Need to input something!" << std::endl;
			continue;
		}
		std::cout << "Your input: " << userInput.c_str() << ", IsLegalExpression: " << (CheckExpression(userInput.c_str(), userInput.length()) ? "true" : "false") << std::endl;

		if (CheckExpression(userInput.c_str(), userInput.length())) 
		{
			std::string postfix = ConvertInfixToPostfix(userInput);
			std::cout << "postfix: " << postfix << std::endl;
			double calculate = ProcessingPostfix(postfix);
			std::cout << "result: " << calculate << std::endl;
		}
	}
}