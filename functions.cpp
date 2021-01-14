// id-checker functions.cpp

#include "cc-checker.h"

#include <iostream>
#include <vector>
#include <fstream>

void help(){
	printf("id-checker	(https://github.com/loopdel0op/cc-checker)\n"
		"Usage: cc-checker [Options] {cc numbers}\n"
		"OPTIONS:\n"
		"	-f	input file name\n"
		"	-o	output file name\n"
		"	-l	luhn algorithm check\n"
		"	-m	major industry identification\n"
		"	-i	issuer identification\n"
		"	-p	personal account number\n"
		"	-a	check/identifiy all\n");
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
	outputFile.close();
}
bool luhnAlg(std::string input){
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
