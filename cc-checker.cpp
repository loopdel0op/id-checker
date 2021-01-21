// id-checker cc-checker.cpp

#include "cc-checker.h"

#include <vector>
#include <iostream>
#include <iterator>

std::vector<std::string> cardNumbers;
std::vector<std::string> allArgs;
std::string inputFileName = "";
std::string outputFileName = "out";
bool luhnCheck = NULL;
bool industryIdentification = NULL;
bool issuerIdentification = NULL;
bool personalAccountNumber = NULL;
bool checkAll = NULL;
bool helpCalled = NULL;
bool fileOutput = NULL;

int main(int argc, char **argv){
	if (argc == 1) help();							// show help if there are no arguaments
	allArgs.assign (argv + 1, argv + argc ); 				// pour char array to string vector
	for ( int i = 0; i != argc - 1; i++){ 					// cli arguaments 			
		if (allArgs[i] == "-f" && allArgs.size() == i + 2) inputFileName = allArgs[++i]; 		
		else if (allArgs[i] == "-o") {if (!allArgs[++i].empty() && isParameter(allArgs[i]) == false) outputFileName = allArgs[i]; fileOutput = true;}
		else if (allArgs[i] == "-l") luhnCheck = true; 			
		else if (allArgs[i] == "-m") industryIdentification = true; 		
		else if (allArgs[i] == "-i") issuerIdentification = true; 		
		else if (allArgs[i] == "-p") personalAccountNumber	= true; 	
		else if (allArgs[i] == "-a") checkAll = true;			
		else if (allArgs[i] == "-h") {help(); return 0;}
		else if (allArgs[i] == "-n"){	
			for (int n = ++i; n != argc -1; ++n){			//pour all the numbers to string vector until a non-digit string
				if(isNumber(allArgs[n]) == false) break;
				cardNumbers.push_back(allArgs[n]);
			}
		}
	}
	if (!inputFileName.empty()) readFile();					// if input file is specified read it and store the contents in a string vector
	output();
}
