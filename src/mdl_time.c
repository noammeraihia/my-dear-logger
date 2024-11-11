#include "mdl_time.h"

struct tm* mdl_get_time() 
{
        time_t _current_time;
        struct tm* _time; 
        time(&_current_time);
        _time = localtime(&_current_time);

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