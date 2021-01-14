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
extern bool personalAccountNumber;
extern bool checkAll;
extern bool helpCalled;
extern bool fileOutput;

void help();
void readFile();
void writeFile();
bool luhnAlg(std::string input);
void output();
