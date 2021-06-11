#include <iostream>
#include <vector>
#include <string>

const std::string quit_command   = "q";
const std::string help_command   = "help";
const std::string add_command    = "add";
const std::string remove_command = "remove";
const std::string list_command   = "list";


struct Contacts{
	std::string name;
	std::string address;
	std::string phone;
};

void parse(std::string query, std::vector<Contacts>& vc){
	if (query == quit_command){
		std::cout << "Quit(Ok)" << std::endl;
	}

	else if (query == help_command){
		std::cout << std::endl;
		std::cout << "add -> add contact"       << std::endl;
		std::cout << "remove -> remove contact" << std::endl;
		std::cout << "list -> show list" 		<< std::endl;
		std::cout << "q -> quit" 				<< std::endl;
		std::cout << std::endl;
	}

	else if(query == add_command){
		std::string name;
		std::string address;
		std::string phone;
		
		Contacts mard;
		
		std::cout << "Enter name: ";
		std::cin >> name;
		mard.name = name;
		
		std::cout << "Enter address: ";
		std::cin >> address;
		mard.address = address;
		
		std::cout << "Enter phone: ";
		std::cin >> phone;
		mard.phone = phone;
	
		vc.push_back(mard);
		std::cout << "add(Ok)" << std::endl;
	}

	else if (query == remove_command){
			
		std::string delete_data;
		std::cout << "Enter name: ";
		std::cin >> delete_data;

		for (int i = 0; i < vc.size(); ++i){
			if (vc[i].name == delete_data){
					vc.erase(std::next(vc.begin()+i-1));
			}
		}
		std::cout << "remove(Ok)" << std::endl;		
	}

	else if (query == list_command){
		for(int i = 0; i < vc.size(); ++i){
			std::cout << vc[i].name << "\t";
			std::cout << vc[i].address << "\t";
			std::cout << vc[i].phone << std::endl;
		}
	}
	
	else {
		std::cout << "invalid command, please check spelling" << std::endl;
	}
}

int main(){

	std::string query;
	std::vector<Contacts> vc;
	
	while (query != quit_command){
		std::cout << "Enter query (help for help): ";
		std::cin  >> query;
		parse(query,vc);
	}
}
