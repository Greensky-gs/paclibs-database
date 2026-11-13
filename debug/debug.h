#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <stdio.h>

/*    DEBUG HEADER
 * this file can be included to have debug symbols. It can be controlled with the definition of certain macros. Hence :
 *
 * Including the following macros will have this effect :
 * - DBG_NO_COL : disable prefixing color by default of the DEBUG macro. By default, it is preceeded in green
 * - DBG_CLOCK : This will prefix the DEBUG with a clock of the real time. It is colored in purple
 * - DBG_POSITION : Insert before the clock a string with the file name and the line of the DEBUG macro
 * - NODEBUG or DISABLE_DEBUG : Disable the definition of the color macros. Replaces the DEBUG macro with an empty macro, effectively disabling all macro definition
 *
 * Here is how to use the DEBUG macro :
 * It is constructed with variadic arguments, that will replace the __VA_ARGS__ in printf(__PREFIX __VA_ARGS__); instruction
 * Which means, that inputing DEBUG("Message") will result in printf(__PREFIX "Message"); and to print a variable, it can be done by doing :
 * DEBUG("pointer : %p", *doubleptr);, that would result in : printf(__PREFIX "Pointer : %p", *doubleptr);
 *
 * Here's how to use color macros :
 * - Prefix everything with DBG_ and write in uppercase
 * - Formatting :
 *    bold, italic, underline and blink form color variables, and are not mutually exclusive
 * - Coloring :
 *   - All the following colors are available : black, green, yellow, red, blue, purple, cyan
 *   - You can prefix the color with LIGHT_ to get the light variable
 *   - You can suffix the DBG_ with BG_ to get the matching background color
 *   - Add a T at the end of the variable name to transform it into a macro accepting one argument and surrounding the argument with the matching color. It adds a reset that is __DEBUG_PREFIX (= the default color of the DEBUG macro)
 *   - DBG_RESET is a variable to reset all coloring
 * - Examples :
 *   DEBUG("this is green" DBG_RED " and this is red");
 *   DEBUG(DBG_BG_LIGHT_CYAN "HEADER : " DBG_LIGHT_RED "%s", string);
 */

#if !defined(NODEBUG) && !defined(DISABLE_DEBUG)

#define DBG_RESET "\x1b[0m"

//// Coloring Variables
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

//// Color macros
// Formatting
#define DBG_BOLDT(x)      "\x1b[1m" x __DEBUG_PREFIX
#define DBG_ITALICT(x)    "\x1b[3m" x __DEBUG_PREFIX
#define DBG_UNDERLINET(x) "\x1b[4m" x __DEBUG_PREFIX
#define DBG_BLINKT(x)     "\x1b[5m" x __DEBUG_PREFIX

// Coloring
#define DBG_BLACKT(x)  "\x1b[30m" x __DEBUG_PREFIX
#define DBG_GREENT(x)  "\x1b[32m" x __DEBUG_PREFIX
#define DBG_YELLOWT(x) "\x1b[33m" x __DEBUG_PREFIX
#define DBG_REDT(x)    "\x1b[31m" x __DEBUG_PREFIX
#define DBG_BLUET(x)   "\x1b[34m" x __DEBUG_PREFIX
#define DBG_PURPLET(x) "\x1b[35m" x __DEBUG_PREFIX
#define DBG_CYANT(x)   "\x1b[36m" x __DEBUG_PREFIX

#define DBG_LIGHT_BLACKT(x)  "\x1b[90m" x __DEBUG_PREFIX
#define DBG_LIGHT_GREENT(x)  "\x1b[92m" x __DEBUG_PREFIX
#define DBG_LIGHT_YELLOWT(x) "\x1b[93m" x __DEBUG_PREFIX
#define DBG_LIGHT_REDT(x)    "\x1b[91m" x __DEBUG_PREFIX
#define DBG_LIGHT_BLUET(x)   "\x1b[94m" x __DEBUG_PREFIX
#define DBG_LIGHT_PURPLET(x) "\x1b[95m" x __DEBUG_PREFIX
#define DBG_LIGHT_CYANT(x)   "\x1b[96m" x __DEBUG_PREFIX
#define DBG_GRAYT(x) DBG_LIGHT_BLACK x __DEBUG_PREFIX

// Backgrounds
#define DBG_BG_REDT(x)    "\x1b[41m" x __DEBUG_PREFIX
#define DBG_BG_GREENT(x)  "\x1b[42m" x __DEBUG_PREFIX
#define DBG_BG_YELLOWT(x) "\x1b[43m" x __DEBUG_PREFIX
#define DBG_BG_BLUET(x)   "\x1b[44m" x __DEBUG_PREFIX
#define DBG_BG_PURPLET(x) "\x1b[45m" x __DEBUG_PREFIX
#define DBG_BG_CYANT(x)   "\x1b[46m" x __DEBUG_PREFIX
#define DBG_BG_WHITET(x)  "\x1b[47m" x __DEBUG_PREFIX

#define DBG_BG_LIGHT_REDT(x)    "\x1b[101m" x __DEBUG_PREFIX
#define DBG_BG_LIGHT_GREENT(x)  "\x1b[102m" x __DEBUG_PREFIX
#define DBG_BG_LIGHT_YELLOWT(x) "\x1b[103m" x __DEBUG_PREFIX
#define DBG_BG_LIGHT_BLUET(x)   "\x1b[104m" x __DEBUG_PREFIX
#define DBG_BG_LIGHT_PURPLET(x) "\x1b[105m" x __DEBUG_PREFIX
#define DBG_BG_LIGHT_CYANT(x)   "\x1b[106m" x __DEBUG_PREFIX
#define DBG_BG_LIGHT_WHITET(x)  "\x1b[107m" x __DEBUG_PREFIX
#define DBG_BD_LIGHT_GRAYT(x)   "\x1b[100m" x __DEBUG_PREFIX

// Debugging macros

#ifdef DBG_NO_DCOL
#define __DEBUG_PREFIX
#else
#define __DEBUG_PREFIX DBG_GREEN
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
  printf(__DEBUG_PREFIX __VA_ARGS__);\
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
