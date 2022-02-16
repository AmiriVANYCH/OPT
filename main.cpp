#include"LexAnalyser.h"
#include"Data.h"
#include <Windows.h>

void print_all(Data* data,Print* print) {

	std::cout << print->get_errors(print->messageConst) << std::endl;
	print->print_tables(data->getConst());
	std::cout << std::endl;
	std::cout << print->get_errors(print->messageIdent) << std::endl;
	print->print_tables(data->getIdent());
	std::cout << std::endl;
	std::cout << print->get_errors(print->messageKW) << std::endl;
	print->print_tables(data->getKW());
	std::cout << std::endl;
	std::cout << print->get_errors(print->messageSing) << std::endl;
	print->print_tables(data->getSing());
	std::cout << std::endl;
	std::cout << print->get_errors(print->messageLexTable) << std::endl;
	print->print_lex_table(data->getLexTable(),data);
	std::cout << std::endl;
	print->print_erors();
	std::cout << std::endl;
}

int main(int argc, char* argv[])
{



	setlocale(LC_ALL, "uk_UA");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	if (argc > 1) {
		Data* data = new Data;
		Print* print = new Print;
		Lexem* lexem = new Lexem(argv[1], data, print);
		lexem->analises();
		print_all(data, print);
		delete data;
		delete print;
		delete lexem;
		system("pause");
	}

	else {
		std::cout << "Ви не ввели назву файлу як параметр запуску запуск testTrue.txt" << std::endl;
		Data* data = new Data;
		Print* print = new Print;
		Lexem* lexem = new Lexem("testTrue.txt", data, print);
		lexem->analises();
		print_all(data, print);
		delete data;
		delete print;
		delete lexem;
		system("pause");
		system("pause");
	}
	return 0;

}