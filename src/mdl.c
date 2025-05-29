#include "mdl.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>

/*
        UTILITIES
*/

// colored text in shell
#define mdl_LC_RED "\x1b[91m"
#define mdl_LC_GREEN "\x1b[92m"
#define mdl_LC_YELLOW "\x1b[1;93m"
#define mdl_LC_BOLD_YELLOW "\x1b[1;83m"
#define mdl_LC_WHITE "\x1b[97m"
#define mdl_LC_RESET "\x1b[0m"
#define mdl_LC_TIME_BG "\x1b[100m"
#define mdl_LC_ERROR_FILE_INFO "\x1b[1;95m"

// time
struct tm* mdl_get_time() 
{
        time_t current_time;
        struct tm* _time; 
        time(&current_time);
        _time = localtime(&current_time);

        return _time;
}

void mdl_get_time_str(char* __str)
{
        struct tm * _time = mdl_get_time();
        snprintf(__str, 32, "%d/%d/%d -> %d:%d:%d", _time->tm_mday,
                                            _time->tm_mon,
                                            _time->tm_year + 1900,
                                            _time->tm_hour, 
                                            _time->tm_min, 
                                            _time->tm_sec);
}

#define mdl_log_CLRPRINT(__todo, __color)\
        printf("%s", __color);\
        __todo;\
        printf("%s", mdl_LC_RESET);

struct mdl_log_level_context {
        const char* log_level_str;
        const char* log_level_color;

};

/*
        ACTUAL CODE
*/

#define mdl_LSTR_SUCCESS "SUCCESS"
#define mdl_LSTR_FAILURE "FAILURE"
#define mdl_LSTR_ERROR "ERROR"
#define mdl_LSTR_WARNING "WARNING"
#define mdl_LSTR_DEBUG "DEBUG"
#define mdl_LSTR_INFO "INFO"
#define mdl_LSTR_GENERIC "GENERIC"
#define mdl_LSTR_UNKNOWN "UNKNOWN LOG LEVEL"

struct mdl_log_level_context mdl_get_log_level_context(enum mdl_log_level __log_level)
{
        switch (__log_level)
        {
        case mdl_LL_SUCCESS:
                return (struct mdl_log_level_context){mdl_LSTR_SUCCESS, mdl_LC_GREEN};

        case mdl_LL_FAILURE:
                return (struct mdl_log_level_context){mdl_LSTR_FAILURE, mdl_LC_RED};
        
        case mdl_LL_ERROR:
                return (struct mdl_log_level_context){mdl_LSTR_ERROR, mdl_LC_RED};

        case mdl_LL_WARNING:
                return (struct mdl_log_level_context){mdl_LSTR_WARNING, mdl_LC_YELLOW};

        case mdl_LL_DEBUG:
                return (struct mdl_log_level_context){mdl_LSTR_DEBUG, mdl_LC_WHITE};

        case mdl_LL_INFO:
                return (struct mdl_log_level_context){mdl_LSTR_INFO, mdl_LC_WHITE};

        case mdl_LL_GENERIC:
                return (struct mdl_log_level_context){mdl_LSTR_GENERIC, mdl_LC_WHITE};

        default:
                break;
        }

        return (struct mdl_log_level_context) {mdl_LSTR_UNKNOWN, mdl_LC_WHITE};
}

// main log function
void mdl_log(enum mdl_log_level __log_level, const char* __file, int __line, const char* __endline, const char* __fmt, ...)
{
        va_list args;
        va_start(args, __fmt);

        char time_str[32];
        memset((char*) time_str, 0, 32);
        mdl_get_time_str(time_str);

        struct mdl_log_level_context ll_context = mdl_get_log_level_context(__log_level);

        #ifndef mdl_DEBUG

        if (__log_level != mdl_LL_DEBUG)
        {
                mdl_log_CLRPRINT(
                        printf("[%s]", time_str), 
                        mdl_LC_TIME_BG
                )
                mdl_log_CLRPRINT(
                        printf("[%s] ", ll_context.log_level_str),
                        ll_context.log_level_color
                )

                vfprintf(stdout, __fmt, args);
                printf("%s", __endline);
        }

        #else

        mdl_log_CLRPRINT(
                printf("[%s]", time_str), 
                mdl_LC_TIME_BG
        )
        mdl_log_CLRPRINT(
                printf("[%s] ", ll_context.log_level_str),
                ll_context.log_level_color
        )
        
        if (__log_level == mdl_LL_ERROR)
        {
                mdl_log_CLRPRINT(
                        printf("('%s' at line %d) ", __file, __line),
                        ll_context.log_level_color
                )
        }

        vfprintf(stdout, __fmt, args);
        printf(__endline);

        #endif

        va_end(args);
}