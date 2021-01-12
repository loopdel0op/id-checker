// cc-checker functions.h

#include <vector>
#include <string>

extern std::vector<std::string> allArgs;
extern std::string inputFileName;
extern std::string outputFileName;
extern bool luhnCheck;
extern bool industryIdentification;
extern bool issuerIdentification;
extern bool personalAccountIdentification;
extern bool checkAll;
extern bool helpCalled;

void help();
