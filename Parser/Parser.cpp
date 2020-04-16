#include "Parser.h"
#include <stack>

list<Phrase> Parser::ToPostfix(list<Phrase> listPhrase)
{
	stack<Phrase> stackPhrase;
	list<Phrase> postfix;

	if (!BalanceParentheses(listPhrase))
		throw "uncorrect";
	bool F = true;
	for (auto it = listPhrase.begin(); it != listPhrase.end(); ++it)
	{
		//cout << (*it).str << endl;
		if (it->str == "integral")
		{
			postfix.emplace_back(*it);
		}
		else if ((IsOperator(it->str)) || (it->str == "("))
		{
			if(F)
			{
				F = false;
			}
			if((stackPhrase.empty()) || (it->str == "("))
			{
				stackPhrase.push(*it);
			}
			else
			{
				if (Parser::PriorityOperator(it->str) > Parser::PriorityOperator(stackPhrase.top().str))
				{
					stackPhrase.push(*it);
				}
				else
				{
					while ((!stackPhrase.empty()) && (Parser::PriorityOperator(stackPhrase.top().str)) >= Parser::PriorityOperator(it->str))
					{
						postfix.emplace_back(stackPhrase.top());
						stackPhrase.pop();
					}
					stackPhrase.push(*it);
				}
			}
		}
		else if (it->str == ")")
		{
			if (F)
			{
				F = false;
			}
			while (stackPhrase.top().str != "(")
			{
				postfix.emplace_back(stackPhrase.top());
				stackPhrase.pop();
			}
			stackPhrase.pop();
		}
		else
		{
			postfix.emplace_back(*it);
			F = true;
		}
	}

	while (!stackPhrase.empty())
	{
		postfix.emplace_back(stackPhrase.top());
		stackPhrase.pop();
	}
	return postfix;
}

bool Parser::BalanceParentheses(list<Phrase> listPhrase)
{
	if (listPhrase.empty())
		throw "list is empty";
	stack<char> check;
	auto it = listPhrase.begin();
	//����� 1-�� ������, ���� ��� �������������, �� ����������� �� ���������
	while((it != listPhrase.end()) && (check.empty()))
	{
		if ((*it).str == "(")
		{
			check.push('(');
		}
		else if ((*it).str == ")")
		{
			return false;
		}
		++it;
	}
	//���������� ���� ������ � ����
	while((it != listPhrase.end()))
	{
		if ((*it).str == "(")
		{
			check.push('(');
		}
		else if ((*it).str == ")")
		{
			check.push(')');
		}
		++it;
	}

	//���� ������� ������ �������������, �� ����������� �����������
	if ((!check.empty()) && (check.top() == '('))
		return false;
	int count = 0;
	//�������� ������� ������
	while (!check.empty())
	{
		char c = check.top();
		if (c == ')')
		{
			count--;
		}
		else
		{
			count++;
		}
		check.pop();
	}
	return (count == 0) ? true : false;
}

void Parser::Parse(string str, TableManager manager)
{
	Formula formula(str);
	list<Phrase> listPhrases = formula.Parse();
	list<Phrase> postfixPhrase = Parser::ToPostfix(listPhrases);
}

int Parser::PriorityOperator(string s)
{
	if (s == "(")
	{
		return 0;
	}
	else if (s == ")")
	{
		return 1;
	}
	else if ((s == "+") || (s == "-"))
	{
		return 2;
	}
	else if ((s == "/") || (s == "*"))
	{
		return 3;
	}
	else
		throw "uncorrect symbol";
}

bool Parser::IsOperator(string s)
{
	string oper = "+-*/";
	return (oper.find(s) == -1) ? false : true;
}

void Parser::Calculate(list<Phrase> postfixPhrases)
{
	
}

