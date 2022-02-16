#pragma once
#include <unordered_map>
#include <iostream>
#include "Data.h"
class Print
{
public:
	void add_item_to_arrey(std::vector<int>);
	void print_lex_table(std::vector<std::vector<int>>, Data*);
	void print_erors();
	void print_tables(std::unordered_map<std::string , size_t> table);
	const int warDelimExpected = 1;
	const int errConstError = 2;
	const int errIligalSymbol = 3;
	const int messageLexTable = 4;
	const int messageKW = 5;
	const int messageSing = 6;
	const int messageConst = 7;
	const int messageIdent = 8;
	std::string get_errors(int);
private:
	
	std::vector<std::string> error;

	std::unordered_map< int, std::string> errors = {
		{warDelimExpected,"Увага пропущено пробіл між лексемами"},
		{errConstError,"Не правильне визначення константи"},
		{errIligalSymbol,"Знайдено недозволений символ"},
		{messageLexTable,"Таблиця лексем"},
		{messageKW,"Таблиця кодових слів"},
		{messageSing,"Таблиця символів"},
		{messageConst,"Таблиця констант"},
		{messageIdent,"Таблиця ідентифікаторів"},

	};

	
	
};

