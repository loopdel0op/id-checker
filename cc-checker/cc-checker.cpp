// id-checker cc-checker.cpp

#include "cc-checker.h"

#include <vector>
#include <iostream>
#include <iterator>

std::vector<std::string> cardNumbers;
std::vector<std::string> allArgs;
std::string inputFileName;
std::string outputFileName;
bool luhnCheck = NULL;
bool industryIdentification = NULL;
bool issuerIdentification = NULL;
bool personalAccountNumberIdentification = NULL;
bool issuingBankIdentification;
bool checkAll = NULL;
bool helpCalled = NULL;


int main(int argc, char **argv){
	if (argc == 1) help();							// show help if there are no arguaments
	allArgs.assign (argv + 1, argv + argc ); 				// pour char array to string vector
	for ( int i = 0; i != argc - 1; i++){ 					// cli arguaments 			
		if (allArgs[i] == "-f") if (!allArgs[++i].empty() && !isParameter(allArgs[i])) inputFileName = allArgs[i]; else {help(); return 0;}
		if (allArgs[i] == "-o") if (!allArgs[++i].empty() && !isParameter(allArgs[i])) outputFileName = allArgs[i]; else {help(); return 0;}
		if (allArgs[i] == "-l") luhnCheck = true; 			
		if (allArgs[i] == "-m") industryIdentification = true; 		
		if (allArgs[i] == "-i") issuerIdentification = true; 		
		if (allArgs[i] == "-p") personalAccountNumberIdentification = true;
		if (allArgs[i] == "-b") issuingBankIdentification = true;	
		if (allArgs[i] == "-a") checkAll = true;			
		if (allArgs[i] == "-h") {help(); return 0;}
		if (allArgs[i] == "-n"){	
			for (int n = ++i; n != argc -1; ++n){			//pour all the numbers to string vector until a non-digit string
				if(!isNumber(allArgs[n]) && !isParameter(allArgs[n])){help(); return 0;}
				if(!isNumber(allArgs[n]) && isParameter(allArgs[n])) break;
				cardNumbers.push_back(allArgs[n]);
			}
		}
	}
	if(checkAll){
		luhnCheck = true;
		industryIdentification = true;
		issuerIdentification = true;
		personalAccountNumberIdentification = true;
		issuingBankIdentification = true;
	}
	if (!inputFileName.empty()) readFile();					// if input file is specified read it and store the contents in a string vector
	output();
}
