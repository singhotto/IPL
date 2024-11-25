cmake_minimum_required(VERSION 3.16)

project(ipl LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O3")

# Directories
set(LOG_DIR ${CMAKE_SOURCE_DIR}/logger)
set(INTERPRETER_DIR ${CMAKE_SOURCE_DIR}/interpreter)
set(AST_DIR ${CMAKE_SOURCE_DIR}/ast)
set(EXPR_DIR ${AST_DIR}/expr)
set(ARITH_DIR ${EXPR_DIR}/arithmatic)
set(VALUE_DIR ${EXPR_DIR}/value)
set(BOOL_DIR ${EXPR_DIR}/boolean)
set(STMT_DIR ${AST_DIR}/stmt)
set(STMT_ASSIGN_DIR ${STMT_DIR}/assignment)
set(PARSER_DIR ${CMAKE_SOURCE_DIR}/parser)

# Source files
file(GLOB VALUE_SRC ${VALUE_DIR}/*.cc)
file(GLOB ARITH_SRC ${ARITH_DIR}/*.cc)
file(GLOB BOOL_SRC ${BOOL_DIR}/*.cc)
file(GLOB EXPR_SRC ${EXPR_DIR}/*.cc)
file(GLOB STMT_SRC ${STMT_DIR}/*.cc)
file(GLOB STMT_ASSIGN_SRC ${STMT_ASSIGN_DIR}/*.cc)
file(GLOB AST_SRC ${AST_DIR}/*.cc)
file(GLOB LOG_SRC ${LOG_DIR}/*.cc)
file(GLOB INTERPRETER_SRC ${INTERPRETER_DIR}/*.cc)
set(PARSER_SRC ${PARSER_DIR}/ipl.cc ${PARSER_DIR}/ipl.lex.cc ${PARSER_DIR}/ipl.parse.cc)

set(SOURCE_FILES
    ${VALUE_SRC}
    ${ARITH_SRC}
    ${BOOL_SRC}
    ${EXPR_SRC}
    ${STMT_SRC}
    ${STMT_ASSIGN_SRC}
    ${AST_SRC}
    ${LOG_SRC}
    ${INTERPRETER_SRC}
    ${PARSER_SRC}
)

# Include directories
include_directories(${CMAKE_SOURCE_DIR} ${AST_DIR} ${INTERPRETER_SRC} ${LOG_DIR} ${EXPR_DIR} ${PARSER_DIR})

# Find Flex and Bison
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

# Generate parser and lexer
BISON_TARGET(Parser ${PARSER_DIR}/ipl.yy ${PARSER_DIR}/ipl.parse.cc COMPILE_FLAGS "--report=all -Wcounterexamples")
FLEX_TARGET(Lexer ${PARSER_DIR}/ipl.ll ${PARSER_DIR}/ipl.lex.cc)
ADD_FLEX_BISON_DEPENDENCY(Lexer Parser)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Explicitly set FLEX_LIBRARIES to empty if libfl is not required
if(NOT FLEX_LIBRARIES)
    set(FLEX_LIBRARIES "")
endif()

# Link Flex and Bison libraries
target_link_libraries(${PROJECT_NAME} PRIVATE ${FLEX_LIBRARIES} ${BISON_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_SOURCE_DIR}/ast 
    ${CMAKE_SOURCE_DIR}/interpreter
    ${CMAKE_SOURCE_DIR}/logger
)
