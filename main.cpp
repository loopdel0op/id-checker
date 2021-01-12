// cc-checker main.cpp

#include <iostream>
#include <vector>

using namespace std;

vector<string> allArgs;
string inputFileName = "";
string outputFileName = "";
bool luhnCheck = NULL;
bool industryIdentification = NULL;
bool issuerIdentification = NULL;
bool personalAccountIdentification = NULL;
bool checkAll = NULL;
bool helpCalled = NULL;

void help();

int main(int argc, char **argv){

	allArgs.assign (argv + 1, argv + argc ); 				// pour char array to string vector

	for ( int i = 0; i != argc - 1; i++){ 					// cli arguaments
		if (allArgs[i] == "-f") inputFileName = allArgs[++i]; 		// input file name
		if (allArgs[i] == "-o") outputFileName = allArgs[++i]; 		// output file name
		if (allArgs[i] == "-l") luhnCheck = true; 			// luhn algorithm check option
		if (allArgs[i] == "-m") industryIdentification = true; 		// major industry identification option
		if (allArgs[i] == "-i") issuerIdentification = true; 		// issuer identification option
		if (allArgs[i] == "-p") personalAccountIdentification = true; 	// personal account identification option
		if (allArgs[i] == "-a") checkAll = true;			// make all the options true other than input and output file
		if (allArgs[i] == "-h") helpCalled = true;			// show usage
	}

	if ( helpCalled == true || argc == 1) help();
}


void help(){
	printf("help");
}
