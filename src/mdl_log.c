#include "mdl_log.h"

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

void mdl_log(enum mdl_log_level __log_level, const char* __file, int __line, const char* __endline, const char* __fmt, ...)
{
        va_list _args;
        va_start(_args, __fmt);

        char _time_str[32];
        memset((char*) _time_str, 0, 32);
        mdl_get_time_str(_time_str);

        struct mdl_log_level_context _ll_context = mdl_get_log_level_context(__log_level);

        #ifndef mdl_DEBUG

        if (__log_level != mdl_LL_DEBUG)
        {
                mdl_log_CLRPRINT(
                        printf("[%s]", _time_str), 
                        mdl_LC_TIME_BG
                )
                mdl_log_CLRPRINT(
                        printf("[%s] ", _ll_context.log_level_str),
                        _ll_context.log_level_color
                )

                vfprintf(stdout, __fmt, _args);
                printf(__endline);
        }

        #else

        mdl_log_CLRPRINT(
                printf("[%s]", _time_str), 
                mdl_LC_TIME_BG
        )
        mdl_log_CLRPRINT(
                printf("[%s] ", _ll_context.log_level_str),
                _ll_context.log_level_color
        )
        
        if (__log_level == mdl_LL_ERROR)
        {
                mdl_log_CLRPRINT(
                        printf("('%s' at line %d) ", __file, __line),
                        _ll_context.log_level_color
                )
        }

        vfprintf(stdout, __fmt, _args);
        printf(__endline);

        #endif

        va_end(_args);
}