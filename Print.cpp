#include "Print.h"

void Print::add_item_to_arrey(std::vector<int> vec) {
	char colum[10] = "";
	char row[10]= "";
	_itoa_s(vec[1], colum, 10);

	_itoa_s(vec[2], row, 10);
	error.push_back(errors[vec[0]] + " в рядку " + row + " в колонці " + colum);
}


void Print::print_lex_table(std::vector<std::vector<int>> table ,Data* data) {
    
    std::cout << "  row    " << "Colum       " << "Code   " <<"Lexem" << std::endl;
    for (int i = 0; i < table.size(); i++) {
        printf("%5d %8d %10d ", table[i][2], table[i][1], table[i][0]);
        std::cout <<"  " << data->get_Lexem_by_id(table[i][0]) << std::endl;
        
    }

    
}

std::string Print::get_errors(int key) {
    return errors[key];
}

void Print::print_erors()
{
    
    auto iter = error.begin();  
    while (iter != error.end())    
    {
        std::cout << *iter << std::endl;
        ++iter;             
    }

}

void Print::print_tables(std::unordered_map<std::string , size_t> table)
{
    // Iterate over an unordered_map using range based for loop
    for (std::pair<std::string , size_t> element : table)
    {
        std::cout << element.second << " :: " << element.first << std::endl;
    }
}
