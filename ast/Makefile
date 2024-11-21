# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O3

# Directories
EXPR_DIR = expr
STMT_DIR = stmt
OBJ_DIR = obj
EXPR_OBJ_DIR = $(OBJ_DIR)/expr

# Source files
SRC = $(STMT_DIR)/Id.cc $(EXPR_DIR)/Int.cc $(EXPR_DIR)/Float.cc $(EXPR_DIR)/Expr.cc $(EXPR_DIR)/AddExpr.cc \
      $(EXPR_DIR)/DivExpr.cc $(EXPR_DIR)/ModExpr.cc $(EXPR_DIR)/MulExpr.cc \
      $(STMT_DIR)/DefVar.cc $(STMT_DIR)/DefFunc.cc $(EXPR_DIR)/CallFunc.cc \
	  $(STMT_DIR)/PrintExpr.cc $(STMT_DIR)/ReturnStmt.cc \
      $(EXPR_DIR)/SubtExpr.cc ExecContext.cc Interpreter.cc main.cpp

# Object files
OBJ = $(SRC:%.cc=$(OBJ_DIR)/%.o)

# Target
main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

# Rule for compiling .cc files into .o files
$(OBJ_DIR)/%.o: %.cc
	@mkdir -p $(dir $@)  # Create necessary directories
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean object files and binary
clean:
	rm -rf $(OBJ_DIR) main
