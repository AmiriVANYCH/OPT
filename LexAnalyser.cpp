#include "LexAnalyser.h"

char Lexem::get_char() {

	colum++;
	return fgetc(file);
}

int Lexem::handle_dig(int key) {
	std::vector<int> v2;
	if (data->getSymbulType(key) == single) {
		buf.push_back((const char)key);
		key = (int)get_char();
		if (data->getSymbulType(key) != dig) {
			data->add_item_to_arrey(v2 = { data->add_sing(buf), lex_colum, lex_row });
			return key;
		}
	}
	while (data->getSymbulType(key) == dig) {
		buf.push_back((const char)key);
		key = (int)get_char();
	}
	if ((char)key == '#') {
		buf.push_back((const char)key);
		key = (int)get_char();
		if (data->getSymbulType(key) == single) {
			buf.push_back((const char)key);
			key = (int)get_char();
			
			
		}
		if (data->getSymbulType(key) == dig) {
			while (data->getSymbulType(key) == dig) {
				buf.push_back((const char)key);
				key = (int)get_char();
			}
		}
		else {
			print->add_item_to_arrey(v2 = { print->errConstError, lex_colum, lex_row });
			return key;
		}
	}
	if (data->getSymbulType(key) != ws && (const char)key != ';') {
		print->add_item_to_arrey(v2 = { print->warDelimExpected, colum, row });
		}
	data->add_item_to_arrey(v2 = { data->add_const(buf), lex_colum, lex_row });
	return key;

}

int Lexem::handle_ws(int key) {
	colum;
	row;
	if ((char)key == '\n') {
		colum = 0;
		row++;

	}
	if ((char)key == '\t') {
		colum = colum + tabSize-1;
	}
	return get_char();
}

int Lexem::handle_dm(int key) {
	buf.push_back((const char)key);
	std::vector<int> v2;
	data->add_item_to_arrey(v2 = { data->add_sing(buf), lex_colum, lex_row });
	return get_char();
}

int Lexem::handle_let(int key) {
	std::vector<int> v2;
	while (data->getSymbulType(key) == let || data->getSymbulType(key) == dig) {
		buf.push_back((const char)key);
		key = (int)get_char();
	}
	if (data->getSymbulType(key) != ws && data->getSymbulType(key) != dm) {
		print->add_item_to_arrey(v2 = { print->warDelimExpected, colum, row });
	}
	data->add_item_to_arrey(v2 = { data->add_ident(buf), lex_colum, lex_row });
	return key;
}

int Lexem::handle_com(int key) {
	buf.push_back((const char)key);
	key = (int)get_char();
	if ((char)key != '*') {
		std::vector<int> v2;
		data->add_item_to_arrey(v2 = { data->add_sing(buf), lex_colum, lex_row });
		return get_char();
	}

	while (true) {
		key = (int)get_char();
		if ((char)key == '*') {
			key = (int)get_char();
			if ((char)key == ')') {
				return get_char();
			}
		}
		
	}

	
}


int Lexem::handle_iligal(int key) {

	key = (int)get_char();
	std::vector<int> v2;
	print->add_item_to_arrey(v2 = { print->errIligalSymbol, colum, row });
	return get_char();



}

void Lexem::analises() {
	int key= (int)get_char();
	int key_type;
	bool not_eof=true;
	while (not_eof)
	{
		if (key == EOF) {
			break;
		}
		key_type = data->getSymbulType(key);
		lex_colum = colum;
		lex_row = row;
		switch (key_type)
		{
		case let:
			key = handle_let(key);
			break;

		case single:
			key = handle_dig(key);
			break;
		case dig:
			key=handle_dig(key);
			break;
		case ws:
			key = handle_ws(key);
			break;
		case dm:
			key = handle_dm(key);
			break;
		case com:
			key = handle_com(key);
			break;
		case iligal:
			key = handle_iligal(key);
			break;
		default:
			break;
		}
		buf.clear();
	}
}






