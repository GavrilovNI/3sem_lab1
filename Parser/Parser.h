#pragma once

#include "Formula.h"
#include "../TableManager.h"

//TableManager = Table*
static class Parser
{
private:
	static list<Phrase> ToPostfix(list<Phrase> listPhrase);
	static bool BalanceParentheses(list<Phrase> listPhrase);
	static int PriorityOperator(string s);
	static bool IsOperator(string s);
	static string Calculate(list<Phrase> postfixPhrases, Table* manager);
	static void CreateRecord(list<Phrase> listPhrases, Table* manager);
public:
	
	static void Parse(string str, Table* manager);
};

 


 
