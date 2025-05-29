#ifndef mdl_LOG_h
#define mdl_LOG_h

enum mdl_log_level {
        mdl_LL_SUCCESS,
        mdl_LL_FAILURE,
        mdl_LL_ERROR,
        mdl_LL_WARNING,
        mdl_LL_DEBUG,
        mdl_LL_INFO,
        mdl_LL_GENERIC
};

void mdl_log(enum mdl_log_level __log_level, const char* __file, int __line, const char* __endline, const char* __fmt, ...);

#define mdl_LOG_SUCCESS(__endline, ...) mdl_log(mdl_LL_SUCCESS, __FILE__, __LINE__, __endline, __VA_ARGS__)
#define mdl_LOG_FAILURE(__endline, ...) mdl_log(mdl_LL_FAILURE, __FILE__, __LINE__, __endline, __VA_ARGS__)
#define mdl_LOG_ERROR(__endline, ...) mdl_log(mdl_LL_ERROR, __FILE__, __LINE__, __endline, __VA_ARGS__)
#define mdl_LOG_WARNING(__endline, ...) mdl_log(mdl_LL_WARNING, __FILE__, __LINE__, __endline, __VA_ARGS__)
#define mdl_LOG_DEBUG(__endline, ...) mdl_log(mdl_LL_DEBUG, __FILE__, __LINE__, __endline, __VA_ARGS__)
#define mdl_LOG_INFO(__endline, ...) mdl_log(mdl_LL_INFO, __FILE__, __LINE__, __endline, __VA_ARGS__)
#define mdl_LOG_GENERIC(__endline, ...) mdl_log(mdl_LL_GENERIC, __FILE__, __LINE__, __endline, __VA_ARGS__)

#endif