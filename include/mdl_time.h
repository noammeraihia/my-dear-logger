#ifndef mdl_TIME_h
#define mdl_TIME_h

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tm* mdl_get_time();
void mdl_get_time_str(char __str[256]);

#endif