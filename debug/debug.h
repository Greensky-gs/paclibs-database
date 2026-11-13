#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <stdio.h>

// This defines debug symbols
// Add a variable "NODEBUG" to disable all debug symbols (or DISABLE_DEBUG, since it is by default in my makefile)

#if !defined(NODEBUG) && !defined(DISABLE_DEBUG)

#define DBG_RESET "\x1b[0m"

// Fonts
#define DBG_BOLD      "\x1b[1m"
#define DBG_ITALIC    "\x1b[3m"
#define DBG_UNDERLINE "\x1b[4m"
#define DBG_BLINK     "\x1b[5m"

// Colors
#define DBG_BLACK  "\x1b[30m"
#define DBG_GREEN  "\x1b[32m"
#define DBG_YELLOW "\x1b[33m"
#define DBG_RED    "\x1b[31m"
#define DBG_BLUE   "\x1b[34m"
#define DBG_PURPLE "\x1b[35m"
#define DBG_CYAN   "\x1b[36m"

#define DBG_LIGHT_BLACK  "\x1b[90m"
#define DBG_LIGHT_GREEN  "\x1b[92m"
#define DBG_LIGHT_YELLOW "\x1b[93m"
#define DBG_LIGHT_RED    "\x1b[91m"
#define DBG_LIGHT_BLUE   "\x1b[94m"
#define DBG_LIGHT_PURPLE "\x1b[95m"
#define DBG_LIGHT_CYAN   "\x1b[96m"
#define DBG_GRAY DBG_LIGHT_BLACK

// Backgrounds
#define DBG_BG_RED    "\x1b[41m"
#define DBG_BG_GREEN  "\x1b[42m"
#define DBG_BG_YELLOW "\x1b[43m"
#define DBG_BG_BLUE   "\x1b[44m"
#define DBG_BG_PURPLE "\x1b[45m"
#define DBG_BG_CYAN   "\x1b[46m"
#define DBG_BG_WHITE  "\x1b[47m"

#define DBG_BG_LIGHT_RED    "\x1b[101m"
#define DBG_BG_LIGHT_GREEN  "\x1b[102m"
#define DBG_BG_LIGHT_YELLOW "\x1b[103m"
#define DBG_BG_LIGHT_BLUE   "\x1b[104m"
#define DBG_BG_LIGHT_PURPLE "\x1b[105m"
#define DBG_BG_LIGHT_CYAN   "\x1b[106m"
#define DBG_BG_LIGHT_WHITE  "\x1b[107m"
#define DBG_BD_LIGHT_GRAY   "\x1b[100m"

// Debugging macros

#ifdef DBG_NO_DCOL
#define __DEBUG_PREFIX
#else
#define __DEBUG_PREFIX printf(DBG_GREEN);
#endif

#ifdef DBG_CLOCK
#include <time.h>

#define __DEBUG_CLOCK {\
  time_t now = time(NULL);\
  struct tm * t = localtime(&now);\
  printf(DBG_PURPLE "%02d:%02d:%02d | " DBG_RESET, t->tm_hour, t->tm_min, t->tm_sec);\
}
#else
#define __DEBUG_CLOCK
#endif

#ifdef DBG_POSITION
#define __DBG_POS printf(DBG_GRAY __FILE__ ":%d | " DBG_RESET, __LINE__);
#else
#define __DBG_POS
#endif

/*
 * This macro takes an arbitrary number of arguments. It will format it as such :
 * printf(first_argument, ...) everything else
 *
 * By default, it will be preceeded by the DBG_GREEN variable. It can be disabled by defining the DBG_NO_DCOL variable
 *
 * By default, a clock is not enabled. You can enable the default clock by defining the DBG_CLOCK variable
 *
 * By default, the filename is disabled, but it can appear if the macro DBG_POSITION is defined
 *
 * It will always reset the color and print a newline afterwards
 */
#define DEBUG(...) {\
  __DEBUG_CLOCK\
  __DBG_POS\
  __DEBUG_PREFIX\
  printf(__VA_ARGS__);\
  printf(DBG_RESET "\n");\
}

#define DEBUG_INT_VAR(var) DEBUG(#var " : %d ", var)
#define DEBUG_LINT_VAR(var) DEBUG(#var " : %ld ", var)


/*
 * This macro takes a trigger, and an arbitrary number of arguments. It will create an if condition depending on the trigger, that will call the
 * DEBUG(...) macro with the VA_ARGS, so it behaves basically the same
 */
#define TR_DEBUG(trigger, ...) if (trigger) DEBUG(__VA_ARGS__)

#else

#define DEBUG(...)

#endif
#endif
