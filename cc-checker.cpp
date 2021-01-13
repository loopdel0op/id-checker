// id-checker main.cpp

#include "functions.h"

#include <vector>

std::vector<std::string> allArgs;
std::string inputFileName = "";
std::string outputFileName = "";
bool luhnCheck = NULL;
bool industryIdentification = NULL;
bool issuerIdentification = NULL;
bool personalAccountNumber = NULL;
bool checkAll = NULL;
bool helpCalled = NULL;

int main(int argc, char **argv){

	allArgs.assign (argv + 1, argv + argc ); 				// pour char array to string vector

	for ( int i = 0; i != argc - 1; i++){ 					// cli arguaments
		if (allArgs[i] == "-f") inputFileName = allArgs[++i]; 		// input file name
		if (allArgs[i] == "-o") outputFileName = allArgs[++i]; 		// output file name
		if (allArgs[i] == "-l") luhnCheck = true; 			// luhn algorithm check option
		if (allArgs[i] == "-m") industryIdentification = true; 		// major industry identification option
		if (allArgs[i] == "-i") issuerIdentification = true; 		// issuer identification option
		if (allArgs[i] == "-p") personalAccountNumber	= true; 	// personal account number option
		if (allArgs[i] == "-a") checkAll = true;			// all options other than io file names
		if (allArgs[i] == "-h") helpCalled = true;			// show usage option
	}
	if ( helpCalled == true || argc == 1) help();				// show help if it is called or there are no arguaments
}