// id-checker cc-checker.h

#include <vector>
#include <string>

extern std::vector<std::string> cardNumbers;
extern std::vector<std::string> allArgs;
extern std::string inputFileName;
extern std::string outputFileName;
extern bool luhnCheck;
extern bool industryIdentification;
extern bool issuerIdentification;
extern bool personalAccountNumberIdentification;
extern bool checkAll;
extern bool helpCalled;

void help();
void readFile();
void writeFile();
bool luhnAlg(const std::string& input);
void output();
bool isNumber(const std::string& input);
bool isParameter(const std::string& input);