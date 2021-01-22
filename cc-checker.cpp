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
bool personalAccountNumber = NULL;
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
		if (allArgs[i] == "-p") personalAccountNumber	= true; 	
		if (allArgs[i] == "-a") checkAll = true;			
		if (allArgs[i] == "-h") {help(); return 0;}
		if (allArgs[i] == "-n"){	
			for (int n = ++i; n != argc -1; ++n){			//pour all the numbers to string vector until a non-digit string
				if(isNumber(allArgs[n]) == false) break;
					cardNumbers.push_back(allArgs[n]);
			}
		}
	}
	if (!inputFileName.empty()) readFile();					// if input file is specified read it and store the contents in a string vector
	output();
}
