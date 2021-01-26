// id-checker functions.cpp

#include "cc-checker.h"

#include <iostream>
#include <vector>
#include <fstream>

std::string checkMII(const std::string& input);
std::string luhnAlg(const std::string& input);
std::string issuerId(const std::string& input);
std::string accNumber(const std::string& input);

void help(){
	printf("id-checker	(https://github.com/loopdel0op/id-checker)\n"
		"Usage: cc-checker [Options]\n"
		"OPTIONS:\n"
		"	-f	input file name\n"
		"	-o	output file name\n"
		"	-l	luhn algorithm check\n"
		"	-m	major industry identification\n"
		"	-i	issuer identification\n"
		"	-p	personal account number\n"
		"	-a	check/identify all\n"
		"	-n	card number(s)\n");
}
void readFile(){
	std::string line;
	std::ifstream inputFile (inputFileName);
	if(!inputFile.is_open())
		help();
	while ( getline (inputFile, line) ) cardNumbers.push_back(line);
	inputFile.close();
}
void writeFile(){
	std::ofstream outputFile;
	outputFile.open (outputFileName);
	for(int i = 0; i != cardNumbers.size(); ++i){
		outputFile << cardNumbers[i] << std::endl;
		if(luhnCheck)
			outputFile << "\t> " << luhnAlg(cardNumbers[i]) << std::endl;
		if(issuerIdentification)
			outputFile << "\t> " << issuerId(cardNumbers[i]) << std::endl;
		if(industryIdentification)
			outputFile << "\t> " << checkMII(cardNumbers[i]) << std::endl;
	}
	outputFile.close();
}
void output(){			// if there is no output file specified output to cli, else output to the file specified
	if (outputFileName.empty()){	
		for (int i = 0; i != cardNumbers.size(); ++i){
			std::cout << cardNumbers[i] << std::endl;
			if(luhnCheck)
				std::cout << "\t> " << luhnAlg(cardNumbers[i]) << std::endl;
			if(issuerIdentification)
				std::cout << "\t> " << issuerId(cardNumbers[i]) << std::endl;
			if(industryIdentification)
				std::cout << "\t> " << checkMII(cardNumbers[i]) << std::endl;
			if(personalAccountNumberIdentification)
				std::cout << "\t> Personal account number is " << accNumber(cardNumbers[i]) << std::endl;
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
std::string luhnAlg(const std::string& input){
	int sum = 0;
	for(int i = 0; i != input.size(); ++i){
		int digit = input[i] - '0';
		if (i % 2 == 0)
			if ((digit = 2*digit) >= 10) 
				digit -= 9;
		sum += digit;
	}
	if ( sum % 10 == 0)
		return "Passed luhn algorithm check";
	else
		return "Failed luhn algorithm check";
}
std::string checkMII(const std::string& input){
	std::string::const_iterator it = input.begin();
	switch(*it){
	case '0':
			return "ISO/TC 68 and other industry assignments";
	case '1':
			return "Airlines";
	case '2':
			return "Airlines and other future industry assignments";
	case '3':
			return "Travel and entertainment and banking/financial";
	case '4':
			return "Banking and financial";
	case '5':
			return "Banking and financial";
	case '6':
			return "Merchandising and banking/financial";
	case '7':
			return "Petroleum and other future industry assignments";
	case '8':
			return "Healthcare, telecommunications and other future industry assignments";
	case '9':
			return "National assignment";
	} 
	return "";
}
std::string issuerId(const std::string& input){
	std::string::const_iterator it = input.begin();
	std::string digits;

	for(int i = 0; i != 4; ++i){
		digits.push_back(*it);
		++it;
	}	
	if(digits[0] == '4')
		return "Visa";
	if(digits[0] == '3' && digits[1] == '1')
		return "China T-Union";
       	if(digits[0] == '6' && digits[1] == '2')
	   return "China UnionPay";	
	if(digits[0] == '3' && digits[1] == '4' || digits[0] == '3' && digits[1] == '7')
	   return "American Express";
	if(digits[0] == '3' && digits[1] == '6')
	   return "Diners Club International";
	if(digits[0] == '5' && (digits[1] == '1' || digits[1] == '2' || digits[1] == '3' || digits[1] == '4' || digits[1] == '5' ))
		return "Mastercard";
	if(digits == "6011" || (digits[0] == '6' && digits[1] == '5'))
		return "Discover";
	if(digits[0] == '3' && digits[1] == '5')
		return "JCB";
	return "Couldn't identify issuer";
}
std::string accNumber(const std::string& input){
	std::string result;
	for(auto it=input.begin()+6; it != input.end() -1; ++it)
		result.push_back(*it);
	return result;
}
