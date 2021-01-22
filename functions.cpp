// id-checker functions.cpp

#include "cc-checker.h"

#include <iostream>
#include <vector>
#include <fstream>

void help(){
	printf("id-checker	(https://github.com/loopdel0op/id-checker)\n"
		"Usage: cc-checker [Options] {cc numbers}\n"
		"OPTIONS:\n"
		"	-f	input file name\n"
		"	-o	output file name\n"
		"	-l	luhn algorithm check\n"
		"	-m	major industry identification\n"
		"	-i	issuer identification\n"
		"	-p	personal account number\n"
		"	-a	check/identifiy all\n"
		"	-n	card number(s)\n");
}
void readFile(){
	std::string line;
	std::ifstream inputFile (inputFileName);
	while ( getline (inputFile, line) ) cardNumbers.push_back(line);
	inputFile.close();
}
void writeFile(){
	std::ofstream outputFile;
	outputFile.open (outputFileName);
	for(int i = 0; i != cardNumbers.size(); ++i){
	outputFile << cardNumbers[i] << std::endl;
	if(luhnAlg(cardNumbers[i]))
		outputFile << "\t> Passed luhn algorithm check\n";
	else	outputFile << "\t> Failed luhn algorithm check\n";
	}
	outputFile.close();
}
bool luhnAlg(const std::string& input){
	int sum = 0;
	for(int i = 0; i != input.size(); ++i){
		int digit = input[i] - '0';
		if (i % 2 == 0)
			if ((digit = 2*digit) >= 10) 
				digit -= 9;
		sum += digit;
	}
	if ( sum % 10 == 0) return true;
	return false;
}
void output(){			// if there is no output file specified output to cli, else output to the file specified
	if (outputFileName.empty()){	
		for (int i = 0; i != cardNumbers.size(); ++i){
			std::cout << cardNumbers[i] << std::endl;
			if(luhnAlg(cardNumbers[i]))
				std::cout << "\t> Passed luhn algorithm check\n";
			else	std::cout << "\t> Failed luhn algorithm check\n";
		}
	} else writeFile();
}
bool isNumber(const std::string& input){
	std::string::const_iterator it = input.begin();
	while(it != input.end() && std::isdigit(*it)) ++it;
	return !input.empty() && it == input.end();
}
bool isParameter(const std::string& input){
	std::string::const_iterator it = input.begin();
	return *it == '-' && !input.empty();
}
