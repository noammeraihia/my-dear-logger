#ifndef mdl_LOG_h
#define mdl_LOG_h

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "mdl_time.h"

#define mdl_LSTR_SUCCESS "SUCCESS"
#define mdl_LSTR_FAILURE "FAILURE"
#define mdl_LSTR_ERROR "ERROR"
#define mdl_LSTR_WARNING "WARNING"
#define mdl_LSTR_DEBUG "DEBUG"
#define mdl_LSTR_INFO "INFO"
#define mdl_LSTR_GENERIC "GENERIC"
#define mdl_LSTR_UNKNOWN "UNKNOWN LOG LEVEL"

#define mdl_LC_RED "\x1b[91m"
#define mdl_LC_GREEN "\x1b[92m"
#define mdl_LC_YELLOW "\x1b[1;93m"
#define mdl_LC_BOLD_YELLOW "\x1b[1;83m"
#define mdl_LC_WHITE "\x1b[97m"
#define mdl_LC_RESET "\x1b[0m"
#define mdl_LC_TIME_BG "\x1b[100m"

#define mdl_LC_ERROR_FILE_INFO "\x1b[1;95m"

enum mdl_log_level {
        mdl_LL_SUCCESS,
        mdl_LL_FAILURE,
        mdl_LL_ERROR,
        mdl_LL_WARNING,
        mdl_LL_DEBUG,
        mdl_LL_INFO,
        mdl_LL_GENERIC
};

struct mdl_log_level_context {
        const char* log_level_str;
        const char* log_level_color;

};

struct mdl_log_level_context mdl_get_log_level_context(enum mdl_log_level __log_level);
void mdl_log(enum mdl_log_level __log_level, const char* __file, int __line, const char* __endline, const char* __fmt, ...);

#define mdl_log_CLRPRINT(__todo, __color)\
        printf("%s", __color);\
        __todo;\
        printf("%s", mdl_LC_RESET);

#define mdl_LOG_SUCCESS(__endline, ...) mdl_log(mdl_LL_SUCCESS, __FILE__, __LINE__, __endline, __VA_ARGS__)
#define mdl_LOG_FAILURE(__endline, ...) mdl_log(mdl_LL_FAILURE, __FILE__, __LINE__, __endline, __VA_ARGS__)
#define mdl_LOG_ERROR(__endline, ...) mdl_log(mdl_LL_ERROR, __FILE__, __LINE__, __endline, __VA_ARGS__)
#define mdl_LOG_WARNING(__endline, ...) mdl_log(mdl_LL_WARNING, __FILE__, __LINE__, __endline, __VA_ARGS__)
#define mdl_LOG_DEBUG(__endline, ...) mdl_log(mdl_LL_DEBUG, __FILE__, __LINE__, __endline, __VA_ARGS__)
#define mdl_LOG_INFO(__endline, ...) mdl_log(mdl_LL_INFO, __FILE__, __LINE__, __endline, __VA_ARGS__)
#define mdl_LOG_GENERIC(__endline, ...) mdl_log(mdl_LL_GENERIC, __FILE__, __LINE__, __endline, __VA_ARGS__)

#endif