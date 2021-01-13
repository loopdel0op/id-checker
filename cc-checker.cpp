// id-checker cc-checker.cpp

#include "functions.h"

#include <vector>

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
		if (allArgs[i] == "-o") {if (allArgs.size() == i + 2) outputFileName = allArgs[++i];	fileOutput = true;}
		if (allArgs[i] == "-l") luhnCheck = true; 			
		if (allArgs[i] == "-m") industryIdentification = true; 		
		if (allArgs[i] == "-i") issuerIdentification = true; 		
		if (allArgs[i] == "-p") personalAccountNumber	= true; 	
		if (allArgs[i] == "-a") checkAll = true;			
		if (allArgs[i] == "-h") helpCalled = true;			
	}
	if ( helpCalled == true || argc == 1) help();				// show help if it is called or there are no arguaments
	if ( !inputFileName.empty()) readFile();				// if input file is specified read it and store it in a string vector
	// process here
	if (fileOutput) writeFile();						// if output file is specified write output inside of it instead of cli
}
