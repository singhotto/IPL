#ifndef LOGGING_MACROS_HH
#define LOGGING_MACROS_HH

#include <iostream>

extern bool g_logOperations;

#define LOG_OPERATION_START(func_name)  if (g_logOperations) { std::cout << "Begin: " << func_name << "\n"; }
#define LOG_OPERATION_END(func_name)  if (g_logOperations) { std::cout << "  End: " << func_name << "\n"; }

#endif // LOGGING_MACROS_HH
