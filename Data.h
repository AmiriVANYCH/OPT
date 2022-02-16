#pragma once
#include <unordered_map>
#include <string >
#include <string>
#include <iostream>
const int KW_Start = 601;
const int Ident_Start = 1001;
const int Const_Start = 1000001;
const int Sing_Start = 50;
const int KW_Max = 1000;
const int Ident_Max = 1000000;
const int Const_Max = 2000000;
const int Sing_Max = 60;
const int ws = 0;
const int dig = 1;
const int single = 2;
const int let = 3;
const int dm = 4;
const int com = 5;
const int iligal = 6;


class Data
{
public:
	Data()
	{
		add_KW();
		init_ascii();
	}
	using Code = size_t;
	int getKWid(std::string  key);
	int getIdentid(std::string  key);
	int getConstid(std::string  key);
	int getSingid(std::string  key);
	int add_ident(std::string  key);
	int add_const(std::string  key);
	int add_sing(std::string  key);
	std::string get_Lexem_by_id(int);
	void add_item_to_arrey(std::vector<int>);
	int getSymbulType(int key);
	std::unordered_map<std::string , Code> getKW() {return keyWords;}
	std::unordered_map<std::string , Code> getIdent() {return ident;}
	std::unordered_map<std::string , Code> getConst() {return constant;}
	std::unordered_map<std::string , Code> getSing() {return sing;}
	std::vector<std::vector<int>> getLexTable() {return lexTable;}

	

private:
	void add_KW();
	void init_ascii();
	size_t num_KW = KW_Start;
	size_t num_Ident = Ident_Start;
	size_t num_Const = Const_Start;
	size_t num_Sing = Sing_Start;
	//Повертає код ключового слова або -1 якщо воно не існує
	int getLEXid(std::string  key, std::unordered_map<std::string , size_t> keyWords);
	int ASCII[256];
	std::unordered_map<std::string, Code> constant;
	std::unordered_map<std::string , Code> keyWords;
	std::unordered_map<std::string , Code> ident;
	std::unordered_map<std::string , Code> sing;
	std::vector<std::vector<int>> lexTable;
};



