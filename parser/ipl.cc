#include <iostream>
#include <fstream>
#include <string>

// External declarations from Flex/Bison
extern FILE* yyin; // Flex input file
extern int yyparse(); // Bison parser function

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file>" << std::endl;
        return 1;
    }

    // Open the file passed as an argument
    FILE* file = fopen(argv[1], "r");
    if (!file) {
        std::cerr << "Error: Could not open file " << argv[1] << std::endl;
        return 1;
    }

    // Set Flex to read from the file
    yyin = file;

    // Parse the input
    int result = yyparse();

    // Close the file
    fclose(file);

    return result;
}
