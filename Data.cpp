#include "Data.h"




int Data::getKWid(std::string  key) {

	return getLEXid(key, keyWords);

}

int Data::getIdentid(std::string  key) {

	return getLEXid(key, ident);

}

int Data::getConstid(std::string  key) {

	return getLEXid(key, constant);

}

int Data::getSingid(std::string  key) {

	return getLEXid(key, sing);

}

void Data::init_ascii() {

	for (int i = 0; i <= 7; i++) {
		ASCII[i] = iligal;
	}
	for (int i = 14; i <= 31; i++) {
		ASCII[i] = iligal;
	}
	for (int i = 48; i <= 57; i++) {
		ASCII[i] = dig;
	}
	for (int i = 65; i <= 90; i++) {
		ASCII[i] = let;
	}
	for (int i = 91; i <= 255; i++) {
		ASCII[i] = iligal;
	}

	ASCII[8] = ws;
	ASCII[9] = ws;
	ASCII[10] = ws;
	ASCII[11] = ws;
	ASCII[12] = ws;
	ASCII[13] = ws;
	ASCII[32] = ws;
	ASCII[33] = iligal;
	ASCII[34] = iligal;
	ASCII[35] = dm;
	ASCII[36] = iligal;
	ASCII[37] = iligal;
	ASCII[38] = iligal;
	ASCII[39] = iligal;
	ASCII[40] = com;
	ASCII[41] = dm;
	ASCII[42] = dm;
	ASCII[43] = single;
	ASCII[44] = iligal;
	ASCII[45] = single;
	ASCII[46] = dm;
	ASCII[47] = iligal;
	ASCII[58] = iligal;
	ASCII[59] = dm;
	ASCII[60] = iligal;
	ASCII[61] = dm;
	ASCII[62] = iligal;
	ASCII[63] = iligal;
	ASCII[64] = iligal;



}
int Data::getSymbulType(int key) {
	if (key == -1) {
		return ws;
	}
	return ASCII[key];
}

//Повертає код ключового слова або -1 якщо воно не існує
int Data::getLEXid(std::string  key, std::unordered_map<std::string , Code> keyWords) {
	if (keyWords.contains(key)) {
		return keyWords[key];
	}
	else {
		return -1;
	}
}



int Data::add_ident(std::string  key) {
	Code id = getIdentid(key);
	if (id != -1) {
		return id;
	}
	id = getKWid(key);
	if (id != -1) {
		return id;
	}
	if (num_Ident <= Ident_Max) {
		ident[key] = num_Ident;
		num_Ident++;
		return num_Ident - 1;
	}
	else {
		std::cout << "За бакато ідентифікаторів";
		return -1;
	}
	
}

void Data::add_item_to_arrey(std::vector<int> vec) {
	lexTable.push_back(vec);
}

int Data::add_sing(std::string  key) {
	Code id = getSingid(key);
	if (id != -1) {
		return id;
	}
	if (num_Sing <= Sing_Max) {
		sing[key] = num_Sing;
		num_Sing++;
		return num_Sing - 1;
	}
	else {
		std::cout << "За бакато символів";
		return -1;
	}

}

std::string Data::get_Lexem_by_id(int key)
{
	if (key >= Ident_Start && key <= Ident_Max) {
		for (std::pair<std::string, size_t> element : ident)
		{
			if (element.second == key) {
				return element.first;
			}
		}
		return "No value";
	}

	if (key >= Const_Start && key <= Const_Max) {
		for (std::pair<std::string, size_t> element : constant)
		{
			if (element.second == key) {
				return element.first;
			}
		}
		return "No value";
	}

	if (key >= KW_Start && key <= KW_Max) {
		for (std::pair<std::string, size_t> element : keyWords)
		{
			if (element.second == key) {
				return element.first;
			}
		}
		return "No value";
	}
	if (key >= Sing_Start && key <= Sing_Max) {
		for (std::pair<std::string, size_t> element : sing)
		{
			if (element.second == key) {
				return element.first;
			}
		}
		return "No value";
	}
	return "No value";
}

int Data::add_const(std::string  key) {
	Code id = getConstid(key);
	if (id != -1) {
		return id;
	}
	if (num_Const <= Const_Max) {
		constant[key] = num_Const;
		num_Const++;
		return num_Const - 1;
	}
	else {
		std::cout << "За бакато констант";
		return -1;
	}

}

void Data::add_KW() {
	std::string  KW[]{ "PROGRAM" ,"BEGIN","END", "CONST" };
	int size = sizeof(KW) / sizeof(std::string );
	if (size < KW_Max-KW_Start) {
		for (int i = 0; i < size; i++)
		{
			keyWords[KW[i]] = num_KW;
			num_KW++;
		}
	}
	else
	{
		std::cout << "За багато ключлвих слів";
	}
}


