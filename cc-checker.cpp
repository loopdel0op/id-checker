// id-checker cc-checker.cpp

#include "cc-checker.h"

#include <vector>
#include <iostream>

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

	allArgs.assign (argv + 1, argv + argc ); 				// pour char array to string vector

	for ( int i = 0; i != argc - 1; i++){ 					// cli arguaments 			
		if (allArgs[i] == "-f" && allArgs.size() == i + 2) inputFileName = allArgs[++i]; 		
		if (allArgs[i] == "-o") {if (allArgs.size() == i + 2) outputFileName = allArgs[++i]; fileOutput = true;}
		if (allArgs[i] == "-l") luhnCheck = true; 			
		if (allArgs[i] == "-m") industryIdentification = true; 		
		if (allArgs[i] == "-i") issuerIdentification = true; 		
		if (allArgs[i] == "-p") personalAccountNumber	= true; 	
		if (allArgs[i] == "-a") checkAll = true;			
		if (allArgs[i] == "-h") helpCalled = true;
		if (allArgs[i] == "-n")	for (int n = ++i; n != argc -1; ++n) cardNumbers.push_back(allArgs[n]);	
	}
	if (helpCalled == true || argc == 1) help();				// show help if it is called or there are no arguaments
	if (!inputFileName.empty()) readFile();					// if input file is specified read it and store it in a string vector
	output();
}
