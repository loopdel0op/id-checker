// cc-checker functions.cpp

#include "functions.h"

#include <iostream>
#include <vector>

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

