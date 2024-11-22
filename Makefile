# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O3

# Tools
FLEX = flex
BISON = bison

PROGRAM = main

PROGRAM_PATH = parser/$(PROGRAM)

# Directories
AST_DIR = ast
EXPR_DIR = $(AST_DIR)/expr
ARITH_DIR = $(EXPR_DIR)/arithmatic
VALUE_DIR = $(EXPR_DIR)/value
STMT_DIR = $(AST_DIR)/stmt
OBJ_DIR = obj
EXPR_OBJ_DIR = $(OBJ_DIR)/expr

# Source files
SRC = $(VALUE_DIR)/Id.cc $(VALUE_DIR)/String.cc $(VALUE_DIR)/Int.cc $(VALUE_DIR)/Float.cc $(ARITH_DIR)/AddExpr.cc \
      $(ARITH_DIR)/SubtExpr.cc $(ARITH_DIR)/DivExpr.cc $(ARITH_DIR)/ModExpr.cc $(ARITH_DIR)/MulExpr.cc \
      $(STMT_DIR)/DefVar.cc $(STMT_DIR)/DefFunc.cc $(EXPR_DIR)/CallFunc.cc \
      $(STMT_DIR)/PrintExpr.cc $(STMT_DIR)/ReturnStmt.cc \
      $(AST_DIR)/ExecContext.cc $(AST_DIR)/Interpreter.cc \
      $(PROGRAM_PATH).lex.cc $(PROGRAM_PATH).parse.cc

# Object files
OBJ = $(SRC:%.cc=$(OBJ_DIR)/%.o)

# Flex and Bison files
LEX_FILE = $(PROGRAM_PATH).ll
BISON_FILE = $(PROGRAM_PATH).yy
LEX_OUTPUT = $(PROGRAM_PATH).lex.cc
BISON_OUTPUT = $(PROGRAM_PATH).parse.cc
BISON_HEADER = $(PROGRAM_PATH).parse.hh

# Target
main: $(BISON_OUTPUT) $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

# Rule for generating the parser (runs first)
$(BISON_OUTPUT) $(BISON_HEADER): $(BISON_FILE)
	$(BISON) --report=all --defines=$(BISON_HEADER) -o $(BISON_OUTPUT) $<

# Rule for generating the lexer
$(LEX_OUTPUT): $(LEX_FILE) $(BISON_OUTPUT)
	$(FLEX) -o $@ $<

# Rule for compiling .cc files into .o files
$(OBJ_DIR)/%.o: %.cc
	@mkdir -p $(dir $@)  # Create necessary directories
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Dependencies for lexer and parser object files
$(OBJ_DIR)/$(PROGRAM).lex.o: $(LEX_OUTPUT)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)/$(PROGRAM).parse.o: $(BISON_OUTPUT)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean object files, binary, and generated files
clean:
	rm -rf $(OBJ_DIR) $(PROGRAM) $(LEX_OUTPUT) $(BISON_OUTPUT) $(BISON_HEADER) *.output
