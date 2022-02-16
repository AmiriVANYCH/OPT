#pragma once
#ifndef __Lex_Analyser_H__
#define __Lex_Analyser_H__
#include "fstream"
#include "Data.h"
#include "Print.h"

class Lexem {

public:
	Lexem(const char* fileName,Data* dataInp,Print* printInp ) {
		 fopen_s(&file,fileName, "r");
		 data = dataInp;
		 print = printInp;
	}
	void analises();
private:
	
	
	char get_char();
	int handle_dig(int key);
	int handle_ws(int key);
	int handle_dm(int key);
	int handle_let(int key);
	int handle_com(int key);
	int handle_iligal(int key);
	FILE* file;
	Data* data;
	Print* print;
	std::string buf;
	int row = 1;
	int colum = 0;
	int lex_row;
	int lex_colum;
	int tabSize = 4;
};

#endif